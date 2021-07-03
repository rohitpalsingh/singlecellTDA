#pragma once
#include "simplexBase.hpp"
#include <set>
#include "utils.hpp"

// Header file for pipePacket class - see pipePacket.cpp for descriptions



template<typename nodeType>
class pipePacket {
  private:
  public:
	std::vector<bettiBoundaryTableEntry> bettiTable;
	std::string ident;
	pipePacket<nodeType>(const std::string &, const double, const int);
	pipePacket<nodeType>(std::map<std::string, std::string>, const std::string&);
	std::string stats;
	std::string runLog;
    std::vector<std::string> time;
    std::vector<std::string> lineage;
    std::vector<std::string> type;
    std::vector<std::vector<double>> workData;
	std::vector<unsigned> centroidLabels;
	std::vector<std::vector<double>> inputData;
	std::vector<std::vector<double>> distMatrix;
	std::vector<std::vector<bool>> incidenceMatrix;
	simplexBase<nodeType>* complex = nullptr;
	
	std::vector<std::set<unsigned>> boundaries;
	std::set<double, std::greater<double>> weights;	
	std::string bettiOutput;
	
	double getSize();	
	std::string getStats();
};
