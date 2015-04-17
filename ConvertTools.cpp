/*
 * ConvertTools.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#include "ConvertTools.h"

ConvertTools::ConvertTools(char* theInputFilename,
		char* theOutputJsonFilename) {

	inputFilename = theInputFilename;
	outputJsonFilename = theOutputJsonFilename;
	jsonReader();
	buildDirectory();
}
void ConvertTools::buildDirectory() {

	char cmd[500];
	string outputFileFoldername(outputFileLocation);
	sprintf(cmd, "mkdir -p %s", (char*) outputFileFoldername.c_str());
	//cout << cmd << endl;
	system(cmd);

	string outputCoordsFoldername(coordsOutputFileLocation);
	sprintf(cmd, "mkdir -p %s", (char*) outputCoordsFoldername.c_str());
	//cout << cmd << endl;
	system(cmd);
}
void ConvertTools::jsonReader() {
	Json::Reader reader;
	Json::Value root;

	//read from file
	ifstream is;
	is.open("configdebug.json", ios::binary);

	if (reader.parse(is, root)) {
		DBInfoLocation = root["DBInfoLocation"].asString();
		inputFileLocation = root["inputFileLocation"].asString();
		outputFileLocation = root["outputFileLocation"].asString();
		coordsOutputFileLocation = root["coordsOutputFileLocation"].asString();
	}

	is.close();

}
void ConvertTools::trim(string& s) {

	size_t p = s.find_first_not_of(" \t");
	s.erase(0, p);

	p = s.find_last_not_of(" \t");
	if (string::npos != p)
		s.erase(p + 1);

}
ConvertTools::~ConvertTools() {
// TODO Auto-generated destructor stub
}

