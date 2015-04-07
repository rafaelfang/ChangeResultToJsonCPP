/*
 * BLANR2Json.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#include "BLANR2Json.h"

BLANR2Json::BLANR2Json(char* inputFilename) :
		ConvertTools(inputFilename) {
	// TODO Auto-generated constructor stub

}
void BLANR2Json::convert() {

	char line[500];
	int counter = 1;
	FILE* inputFile = fopen(fileName, "r");
	ofstream outputFile("BLANRResult.json");

	outputFile << "{" << "\n";
	while (fgets(line, 500, inputFile) != NULL) {

		if (strstr(line, ">") != NULL) {
			outputFile << "\"protein" << counter << "\":{\n";
			//get protein name
			char proteinName[20];
			sscanf(line, "%s ", proteinName);
			string tmp(proteinName);
			outputFile << "\t\"proteinName\":\"" << tmp.substr(1, 7) << "\",\n";

			//get length
			fgets(line, 40, inputFile);
			char temp[10];
			int seqLen;
			sscanf(line, "%s = %d", temp, &seqLen);
			outputFile << "\t\"Length\":\"" << seqLen << "\",\n";

			fgets(line, 500, inputFile); //blank

			//get score, expect
			fgets(line, 500, inputFile);

			float score;
			char* pos1 = strstr(line, "=");
			sscanf(pos1 + 1, "%f", &score);
			outputFile << "\t\"Score\":\"" << score << "\",\n";

			char* pos2 = strstr(pos1 + 1, "=");
			float eValue;
			sscanf(pos2 + 1, "%f", &eValue);
			outputFile << "\t\"eValue\":\"" << eValue << "\",\n";

			//get idenities, positives
			fgets(line, 500, inputFile);
			pos1 = strstr(line, "(");
			int identities;
			sscanf(pos1 + 1, "%d", &identities);
			outputFile << "\t\"Identities\":\"" << identities << "\",\n";

			pos2 = strstr(pos1 + 1, "(");
			int positives;
			sscanf(pos2 + 1, "%d", &positives);
			outputFile << "\t\"Positives\":\"" << positives << "\",\n";

			fgets(line, 500, inputFile); //blank

			//get query
			int nInt1, nInt2;
			char var1[20], var2[20];
			char tmpQuery_pro[200];
			fgets(line, 500, inputFile);
			sscanf(line, "%s %d %s %d", var1, &nInt1, tmpQuery_pro, &nInt2);
			outputFile << "\t\"QueryStart\":\"" << nInt1 << "\",\n";
			outputFile << "\t\"Query\":\"" << tmpQuery_pro << "\",\n";
			outputFile << "\t\"QueryEnd\":\"" << nInt2 << "\",\n";

			//match
			fgets(line, 500, inputFile);
			string str(line);
			trim(str);
			outputFile << "\t\"alignment\":\"" << str << "\",\n";

			//get subject
			fgets(line, 500, inputFile);
			sscanf(line, "%s %d %s %d", var1, &nInt1, tmpQuery_pro, &nInt2);
			outputFile << "\t\"SubjectStart\":\"" << nInt1 << "\",\n";
			outputFile << "\t\"Subject\":\"" << tmpQuery_pro << "\",\n";
			outputFile << "\t\"SubjectEnd\":\"" << nInt2 << "\"\n";

			outputFile << "},\n";
			counter++;
		}
	}
	outputFile << "\"finish\":\"end\"" << "\n";
	outputFile << "}" << "\n";
	fclose(inputFile);
	outputFile.close();

}



BLANR2Json::~BLANR2Json() {
	// TODO Auto-generated destructor stub
}

