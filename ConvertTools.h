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

using namespace std;

class ConvertTools {
public:
	ConvertTools(char*,char*);
	virtual ~ConvertTools();
	void trim(string& str);
	virtual void convert()=0;
protected:
	char* inputFilename;
	char* outputJsonFilename;
};

#endif /* CONVERTTOOLS_H_ */
