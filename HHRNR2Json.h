/*
 * HHRNR2Json.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#ifndef HHRNR2JSON_H_
#define HHRNR2JSON_H_
#include "HHRNRResult.h"
#include "ConvertTools.h"
using namespace std;
class HHRNR2Json: public ConvertTools {
public:
	HHRNR2Json(char*,char*);
	void convert();
	virtual ~HHRNR2Json();

};

#endif /* HHRNR2JSON_H_ */
