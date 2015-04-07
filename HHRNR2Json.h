/*
 * HHRNR2Json.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#ifndef HHRNR2JSON_H_
#define HHRNR2JSON_H_
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "ConvertTools.h"
using namespace std;
class HHRNR2Json: public ConvertTools {
public:
	HHRNR2Json(char*);
	void convert();
	virtual ~HHRNR2Json();

};

#endif /* HHRNR2JSON_H_ */
