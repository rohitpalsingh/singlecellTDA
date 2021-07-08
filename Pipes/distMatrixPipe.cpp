/*
 * distMatrix hpp + cpp extend the basePipe class for calculating the 
 * distance matrix from data input
 * 
 */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
#include <set>
#include <algorithm>
#include "distMatrixPipe.hpp"
#include "utils.hpp"
#include "readInput.hpp"
// basePipe constructor
distMatrixPipe::distMatrixPipe(){
	pipeType = "DistMatrix";
	return;
}

// runPipe -> Run the configured functions of this pipeline segment
void distMatrixPipe::runPipe(pipePacket &inData){
//	 std::ofstream file("mouseDM.csv");
	//Store our distance matrix
	
	if(inData.distMatrix.size() > 0) inData.distMatrix.clear();
//	   inData.distMatrix.resize(inData.workData.size(), std::vector<double>(inData.workData.size(),0));
	auto rs = readInput();
	std::cout<<"Reading Matrix";
	int kl;
	std::cin>>kl;
	inData.distMatrix = rs.readMAT("mouseDMCorrected.csv");
/*	//Iterate through each vector, create lower
	for(unsigned i = 0; i < inData.inputData.size(); i++){
		//Grab a second vector to compare to 
		for(unsigned j = 0; j < inData.inputData.size(); j++){
			//Calculate vector distance 
			if(j>i){
			    double distance = this->ut.vectors_distanceSparse(inData.workData[i],inData.workData[j]);

				  inData.distMatrix[i][j] = distance;
				  file<<distance<<" ";
			}else
	     		file<<0<<" ";
				
		}
		file<<"\n";
	}
	file.close();


	for(unsigned i = 0; i < inData.workData.size(); i++){
		double r_i = 0;
		for(unsigned j = 0; j < inData.workData.size(); j++) r_i = std::max(r_i, inData.distMatrix[std::min(i, j)][std::max(i, j)]);
		enclosingRadius = std::min(enclosingRadius, r_i);
	}
	* */
/*	if(inData.complex->complexType == "alphaComplex" && (this->betaMode == "lune" || this->betaMode == "circle"))
				inData.incidenceMatrix = this->ut.betaNeighbors(inData.inputData,beta,betaMode);
*/
	inData.complex->setDistanceMatrix(&inData.distMatrix);
	
	//Creating Separate Distance Matrices for diffrent time stamps, Lineages, types
	
	
                std::set<std::string> time;
                std::set<std::string> type;
                std::set<std::string> lineage;
		for(auto x : inData.metaData){
			time.insert(x[19]);
			lineage.insert(x[32]);
			type.insert(x[33]);
		}
	        
		for(auto y :time){
		       	std::vector<unsigned> indices;
			unsigned count =0;
			for(auto x:inData.metaData){
				if(x[19]==y)
					indices.push_back(count);
				count++;
			}

		        std::ofstream file("mouseTimeDM"+y+".csv");
			for(auto x:indices){
               			file<<x<<",";
				for(auto y:indices){
					file<<inData.distMatrix[x][y]<<",";
				}
				file<<"\n";
			}
			file.close();
                }


		for(auto y :type){
		       	std::vector<unsigned> indices;
			unsigned count =0;
			for(auto x:inData.metaData){
				if(x[33]==y)
					indices.push_back(count);
				count++;
			}

		        std::ofstream file("mouseTypeDM"+y+".csv");
			for(auto x:indices){
               			file<<x<<",";
				for(auto y:indices){
					file<<inData.distMatrix[x][y]<<",";
				}
				file<<"\n";
			}
			file.close();
		}


		for(auto y :lineage){
		       	std::vector<unsigned> indices;
			unsigned count =0;
			for(auto x:inData.metaData){
				if(x[32]==y)
					indices.push_back(count);
				count++;
			}

		        std::ofstream file("mouseLineageDM"+y+".csv");
			for(auto x:indices){
               			file<<x<<",";
				for(auto y:indices){
					file<<inData.distMatrix[x][y]<<",";
				}
				file<<"\n";
			}
			file.close();
		}

//	inData.complex->setEnclosingRadius(enclosingRadius);
//	inData.complex->setIncidenceMatrix(&inData.incidenceMatrix);

	this->ut.writeDebug("distMatrix", "\tDist Matrix Size: " + std::to_string(inData.distMatrix.size()) + " x " + std::to_string(inData.distMatrix.size()));
	return;
}



// configPipe -> configure the function settings of this pipeline segment
bool distMatrixPipe::configPipe(std::map<std::string, std::string> &configMap){
	std::string strDebug;
	
	auto pipe = configMap.find("debug");
	if(pipe != configMap.end()){
		debug = std::atoi(configMap["debug"].c_str());
		strDebug = configMap["debug"];
	}
	pipe = configMap.find("outputFile");
	if(pipe != configMap.end())
		outputFile = configMap["outputFile"].c_str();
	
	ut = utils(strDebug, outputFile);
	
	pipe = configMap.find("epsilon");
	if(pipe != configMap.end())
		enclosingRadius = std::atof(configMap["epsilon"].c_str());
	else return false;

	configured = true;
	ut.writeDebug("distMatrixPipe","Configured with parameters { eps: " + configMap["epsilon"] + " , debug: " + strDebug + ", outputFile: " + outputFile + " }");
	
	return true;
}

// outputData -> used for tracking each stage of the pipeline's data output without runtime
void distMatrixPipe::outputData(pipePacket &inData){
	std::ofstream file;
	file.open("output/" + pipeType + "_output.csv");
	
	for(std::vector<double> a : inData.distMatrix){
		for(auto d : a){
			file << d << ",";
		}
		file << "\n";
	}
	
	file.close();
	return;
}

