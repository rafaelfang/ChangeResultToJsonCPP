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
#include "ConvertTools.h"
#include "BLANRResult.h"
using namespace std;
class BLANR2Json: public ConvertTools {
public:
	BLANR2Json(char*,char*);
	void convert();

	virtual ~BLANR2Json();
};

#endif /* BLANR2JSON_H_ */
