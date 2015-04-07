/*
 * BLAPDB2Json.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#ifndef BLAPDB2JSON_H_
#define BLAPDB2JSON_H_

#include "ConvertTools.h"
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "ConvertTools.h"
using namespace std;
class BLAPDB2Json: public ConvertTools {
public:
	BLAPDB2Json(char*);
	void convert();
	virtual ~BLAPDB2Json();
};

#endif /* BLAPDB2JSON_H_ */
