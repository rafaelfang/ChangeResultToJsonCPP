/*
 * ConvertTools.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#ifndef CONVERTTOOLS_H_
#define CONVERTTOOLS_H_
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "ThreeDimCoordsResult.h"
#include "json/json.h"
using namespace std;

class ConvertTools {
public:
	ConvertTools(char*, char*);
	virtual ~ConvertTools();
	void trim(string& str);
	virtual void convert()=0;
	void buildDirectory();
	void jsonReader();
	virtual void writeAlignmentResults2JsonFile()=0;

protected:
	char* rootName;
	char* inputFilename;
	char* outputJsonFilename;
	string DBInfoLocation;
	string inputFileLocation;
	string outputFileLocation;
	string coordsOutputFileLocation;

};

#endif /* CONVERTTOOLS_H_ */
