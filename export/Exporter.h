/*
 * Exporter.h
 *
 *  Created on: 13.01.2023
 *      Author: roman
 */

#ifndef EXPORT_EXPORTER_H_
#define EXPORT_EXPORTER_H_

#include <memory>
#include <cmath>
#include <exception>
#include <fstream>
#include <sstream>
#include <vector>
#include <exception>

#include "../table/TruthTable.h"
#include "../benchmark/Benchmark.h"

template<class T>
class Exporter {
public:
	Exporter() = default;

	int chunkSize;
	const int MAX_CHUNK_SIZE = 32;
	const std::string BENCHMARK_DIR =
			"/home/roman/git-eclipse/boolean-benchmark-builder/data/plu/";

	std::ofstream ofs;

	std::shared_ptr<std::vector<std::vector<T>>> compress(
			std::shared_ptr<TruthTable> truthTable);

	void to_plu_file(std::shared_ptr<Benchmark> benchmark,
			std::string benchmark_name);

	virtual ~Exporter() = default;
};

template<class T>
void Exporter<T>::to_plu_file(std::shared_ptr<Benchmark> benchmark,
		std::string benchmark_name) {


	std::shared_ptr<TruthTable> truthTable = benchmark->getTable();

	int numInputs = benchmark->getNumInputs();
	int numOutputs = benchmark->getNumOutputs();
	int numCols = truthTable->getCols();

	std::shared_ptr<std::vector<std::vector<T>>> compressedTable =
			this->compress(truthTable);

	int numChunks = compressedTable->at(0).size();

	std::string file_path;

	file_path.append(BENCHMARK_DIR + benchmark_name + ".plu");

	std::ofstream ofs(file_path.c_str(),
			std::ofstream::out | std::fstream::trunc);

	if (ofs) {
		ofs << ".i " << numInputs << std::endl;
		ofs << ".o " << numOutputs << std::endl;
		ofs << ".p " << numChunks << std::endl;

		for (int i = 0; i < numChunks; i++) {
			for (int j = 0; j < numCols; j++) {
				ofs << (*compressedTable)[j][i] << " ";
				if (j == numInputs - 1) {
					ofs << "  ";
				}
			}
			ofs << std::endl;
		}
		ofs.close();
	} else {
		throw std::runtime_error("Could not open or create benchmark file!");
	}
}

template<class T>
std::shared_ptr<std::vector<std::vector<T>>> Exporter<T>::compress(
		std::shared_ptr<TruthTable> truthTable) {

	bool chunk_table = false;
	int numRows = truthTable->getRows();
	int numCols = truthTable->getCols();

	if (numRows > MAX_CHUNK_SIZE) {

		if ((numRows % MAX_CHUNK_SIZE) != 0) {
			throw new std::runtime_error("Number of rows does "
					"not fit with max chunk size " + MAX_CHUNK_SIZE);
		}

		chunkSize = MAX_CHUNK_SIZE;
		chunk_table = true;
	} else {
		chunkSize = numRows;
	}

	std::shared_ptr<std::vector<std::vector<T>>> compressedTable =
			std::make_shared<std::vector<std::vector<T>>>();

	T value = 0;
	std::vector<T> chunks;

	int bin;
	int exp;

	for (int i = 0; i < numCols; i++) {
		value = 0;

		for (int j = 0; j < numRows; j++) {

			bin = truthTable->at(j, i);

			if (chunk_table) {
				exp = j % chunkSize;
			} else {
				exp = j;
			}

			value += bin * std::pow(2.0, exp);

			if (chunk_table && ((j + 1) % chunkSize == 0)) {
				chunks.push_back(value);
				value = 0;
			}
		}

		if (chunk_table) {
			compressedTable->push_back(chunks);
		} else {
			std::vector<T> column;
			column.push_back(value);
			compressedTable->push_back(column);
		}
		chunks.clear();
	}

	return compressedTable;
}

#endif /* EXPORT_EXPORTER_H_ */
