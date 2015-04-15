/*
 * BLAPDB2Json.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#ifndef BLAPDB2JSON_H_
#define BLAPDB2JSON_H_
#include "BLAPDBResult.h"
#include "ConvertTools.h"
#include <vector>

using namespace std;
class BLAPDB2Json: public ConvertTools {
public:
	BLAPDB2Json(char*, char*);
	void write2JsonFile();
	void convert();
	virtual ~BLAPDB2Json();


private:
	vector<BLAPDBResult> BLAPDBResultVector;
};

#endif /* BLAPDB2JSON_H_ */
