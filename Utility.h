/*
 * Utility.h
 *
 *  Created on: Apr 14, 2015
 *      Author: Chao
 */

#ifndef UTILITY_H_
#define UTILITY_H_
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;
class Utility {
public:
	Utility();
	void find3DCorrds(char*,string,string,string,int);
	void write2Json(string,string,string,int);
	virtual ~Utility();
private:
	vector<float> XCoords;
	vector<float> YCoords;
	vector<float> ZCoords;
};

#endif /* UTILITY_H_ */
