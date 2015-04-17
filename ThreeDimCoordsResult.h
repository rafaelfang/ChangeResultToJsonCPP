/*
 * ThreeDimCoordsResult.h
 *
 *  Created on: Apr 15, 2015
 *      Author: Chao
 */

#ifndef THREEDIMCOORDSRESULT_H_
#define THREEDIMCOORDSRESULT_H_
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;
class ThreeDimCoordsResult {
public:
	ThreeDimCoordsResult();
	virtual ~ThreeDimCoordsResult();
	vector<float>& getRowX();
	void setRowX(vector<float>& rowX);
	vector<float>& getRowY();
	void setRowY(vector<float>& rowY);
	vector<float>& getRowZ();
	void setRowZ(vector<float>& rowZ);
	string& getSubject();
	void setSubject(string& subject);
	const string& getProteinName() const;
	void setProteinName(const string& proteinName);
	int getSubjectStart() const;
	void setSubjectStart(int subjectStart);

private:
	string proteinName;
	string subject;
	int subjectStart;
	vector<float> rowX;
	vector<float> rowY;
	vector<float> rowZ;
};

#endif /* THREEDIMCOORDSRESULT_H_ */
