/*
 * BLANR2Json.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#ifndef BLANR2JSON_H_
#define BLANR2JSON_H_
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <string.h>

#include "BLANRResult.h"
#include "ConvertTools.h"
#include <vector>
using namespace std;
class BLANR2Json: public ConvertTools {
public:
	BLANR2Json(char*,char*);
	void convert();
	void write2JsonFile();

	virtual ~BLANR2Json();


private:
	vector<BLANRResult> BLANRResultVector;
};

#endif /* BLANR2JSON_H_ */
