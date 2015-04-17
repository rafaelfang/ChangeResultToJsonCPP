/*
 * Utility.cpp
 *
 *  Created on: Apr 14, 2015
 *      Author: Chao
 */

#include "Utility.h"

Utility::Utility() {

}
void Utility::find3DCorrds(char* fileName,string output3DFileLocation, string rootName,string subject, int subjectStart) {

	FILE* fptr = fopen(fileName, "r");
	if(fptr==NULL){
		cout<<fileName<<" can't open!"<<endl;
	}
	char line[500];
	char proteinSeq[500];
	int seqLength;
	while (fgets(line, 500, fptr) != NULL) {
		if (strstr(line, ">Reference Sequence Info:") != NULL) {
			fgets(line, 500, fptr);
			sscanf(line, "%s", proteinSeq);
			string s(proteinSeq);
			seqLength = s.size();
			continue;
		}
		if (strstr(line, ">Ca XYZ:") != NULL) {
			XCoords.resize(seqLength);
			YCoords.resize(seqLength);
			ZCoords.resize(seqLength);

			float temp;
			for (int i = 0; i < seqLength; i++) {
				fscanf(fptr, "%f", &temp);
				XCoords[i] = temp;
			}
			for (int i = 0; i < seqLength; i++) {
				fscanf(fptr, "%f", &temp);
				YCoords[i] = temp;
			}
			for (int i = 0; i < seqLength; i++) {
				fscanf(fptr, "%f", &temp);
				ZCoords[i] = temp;
			}
			break;
		}
	}
	fclose(fptr);

	string protein3DCorrdsFilename(output3DFileLocation);
	protein3DCorrdsFilename+= rootName;
	protein3DCorrdsFilename+= "_";
	protein3DCorrdsFilename += subject;
	protein3DCorrdsFilename += "_3DCoords.json";
	//cout<<"protein3DCorrdsFilename: "<<protein3DCorrdsFilename<<endl;
	//cout<<"proteinName: "<<rootName<<endl;
	//cout<<"subject: "<<subject<<endl;
	write2Json(protein3DCorrdsFilename, rootName, subject, subjectStart);

}
void Utility::write2Json(string protein3DCorrdsFilename, string proteinName,
		string subject, int subjectStart) {

	ofstream outJsonFile(protein3DCorrdsFilename.c_str(), ios::out);
	outJsonFile << "{\n";
	outJsonFile << "\"proteinName\":\"" << proteinName << "\"\n";
	for (int i = 0; i < subject.size(); i++) {
		if (subject[i] == '-') {
			outJsonFile << "\"" << subject[i] << "\":\""
					<< "10000,10000,10000\n";
		} else {
			outJsonFile << "\"" << subject[i] << "\":\"" << XCoords[i] << ","
					<< YCoords[i] << "," << ZCoords[i] << "\"\n";
		}

	}
	outJsonFile << "}\n";
	outJsonFile.close();
}
Utility::~Utility() {
	// TODO Auto-generated destructor stub
}

