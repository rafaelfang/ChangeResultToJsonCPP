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

using namespace std;

class ConvertTools {
public:
	ConvertTools(char*);
	virtual ~ConvertTools();
	void trim(string& str);
	virtual void convert()=0;
protected:
	char* fileName;
};

#endif /* CONVERTTOOLS_H_ */
