/*
 * HHR2Json.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#ifndef HHR2JSON_H_
#define HHR2JSON_H_
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "ConvertTools.h"
using namespace std;
class HHR2Json: public ConvertTools {
public:
	HHR2Json(char*);
	void convert();
	virtual ~HHR2Json();
};

#endif /* HHR2JSON_H_ */
