#pragma once


#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <cmath>
#include "utils.hpp"
// Header file for readInput class - see readInput.cpp for descriptions

class readInput {
  private:
  	FILE *pFile;
  	char streamBuffer[1000];
  	static bool parseDoubleVector(std::string, std::vector<double> &);
        static bool parseStringVector(std::string line, std::vector<std::string> &row);
  	static bool parseDoubleSparseVector(std::string , std::vector<dataNode> &);

  public:
    readInput();
    static std::vector<std::vector<double>> readCSV(std::string filename);
    static std::vector<std::vector<dataNode>> readSingleCellCSV(std::string filename);
    
    static std::vector<std::vector<std::string>> readFeatures(std::string filename);
    static std::vector<std::vector<std::string>> readMetaData(std::string filename);
    static std::vector<std::vector<double>> readMAT(std::string filename);
    bool streamInit(std::string filename);
    bool streamRead(std::vector<double>&);
};

