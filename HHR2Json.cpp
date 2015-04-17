/*
 * HHR2Json.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#include "HHR2Json.h"


HHR2Json::HHR2Json(char* inFilename, char* outFilename) :
		ConvertTools(inFilename, outFilename) {

}

void HHR2Json::convert() {

	char line[500];
	int counter = 0;
	string inFilename(inputFileLocation);
	inFilename += inputFilename;

	FILE* inputFile = fopen((char*) inFilename.c_str(), "r");
	if (inputFile == NULL) {
		cout << "input file: " << inFilename << " can't open" << endl;
	}

	HHRResult result;
	Utility utility;
	while (fgets(line, 200, inputFile) != NULL) {

		if (strstr(line, ">") != NULL) {
			counter++;
			char proteinName[7];
			char* pos1 = strstr(line, ">");
			sscanf(pos1 + 1, "%s", proteinName);
			string proteinNameStr(proteinName);
			result.setProteinName(proteinNameStr);

			while (strstr(line, "Probab=") == NULL) {
				fgets(line, 500, inputFile); //skip long name
			}

			//get probab, E-value, Score, Aligned_cols, Identities, Similarity, Sum_probs

			pos1 = strstr(line, "=");
			float probab;
			sscanf(pos1 + 1, "%f", &probab);
			result.setProbab(probab);

			char* pos2 = strstr(pos1 + 1, "=");
			float eValue;
			sscanf(pos2 + 1, "%f", &eValue);
			result.setExpect(eValue);

			char* pos3 = strstr(pos2 + 1, "=");
			float score;
			sscanf(pos3 + 1, "%f", &score);
			result.setScore(score);

			char* pos4 = strstr(pos3 + 1, "=");
			int alignedCols;
			sscanf(pos4 + 1, "%d", &alignedCols);
			result.setAlignedCols(alignedCols);

			char* pos5 = strstr(pos4 + 1, "=");
			float identities;
			sscanf(pos5 + 1, "%f", &identities);
			result.setIdentities(identities);

			char* pos6 = strstr(pos5 + 1, "=");
			float similarity;
			sscanf(pos6 + 1, "%f", &similarity);
			result.setSimilarities(similarity);

			char* pos7 = strstr(pos6 + 1, "=");
			float sumProbs;
			sscanf(pos7 + 1, "%f", &sumProbs);
			result.setSumProbs(sumProbs);

			fgets(line, 200, inputFile); //blank

			//get the query
			fgets(line, 200, inputFile);
			char query_ss_pred[100];
			sscanf(line + 17, "%s", query_ss_pred);
			string strQuery_ss_pred(query_ss_pred);
			result.setQuerySsPred(strQuery_ss_pred);

			fgets(line, 200, inputFile);
			int queryStart;
			char query[100];
			int queryEnd;
			sscanf(line + 17, "%d %s %d", &queryStart, query, &queryEnd);
			result.setQueryStart(queryStart);
			string strQuery(query);
			result.setQuery(strQuery);
			result.setQueryEnd(queryEnd);

			//get the Q Consensus
			fgets(line, 200, inputFile);
			int QConsensusStart;
			char QConsensus[100];
			int QConsensusEnd;
			sscanf(line + 17, "%d %s %d", &QConsensusStart, QConsensus,
					&QConsensusEnd);
			string strQConsensus(QConsensus);
			result.setQueryConsensus(strQConsensus);

			//get alignment
			fgets(line, 200, inputFile);
			char alignment[100];
			sscanf(line + 17, "%s", alignment);
			string strAlignment(alignment);
			result.setAlignment(strAlignment);

			//get the T Consensus
			fgets(line, 200, inputFile);
			int targetStart;
			char targetConsensus[100];
			int targetEnd;
			sscanf(line + 17, "%d %s %d", &targetStart, targetConsensus,
					&targetEnd);
			result.setTargetStart(targetStart);
			string strTargetConsensus(targetConsensus);
			result.setTargetConsensus(strTargetConsensus);
			result.setTargetEnd(targetEnd);

			//get the Target
			fgets(line, 200, inputFile);

			char target[100];

			sscanf(line + 17, "%d %s %d", &targetStart, target, &targetEnd);
			string strTarget(target);
			result.setTarget(strTarget);

			//get the TPred
			fgets(line, 200, inputFile);
			char tPred[100];
			sscanf(line + 17, "%s", tPred);
			string strTPred(tPred);
			result.setTargetSsPred(strTPred);

			counter++;
			string searchDBFilename(DBInfoLocation);
			searchDBFilename += proteinName;
			searchDBFilename += ".db";
			//cout<<searchDBFilename<<endl;
			utility.find3DCorrds((char*) searchDBFilename.c_str(),
					coordsOutputFileLocation, proteinName, target, targetStart);
			HHRResultVector.push_back(result);
		}
	}

	fclose(inputFile);

}

void HHR2Json::writeAlignmentResults2JsonFile() {
	string outFilename(outputFileLocation);
	outFilename += outputJsonFilename;
	ofstream outputFile(outFilename.c_str());
	if (outputFile == NULL) {
		cout << "The output file " << outputFile << " can't open" << endl;
	}
	outputFile << "{" << "\n";
	for (int i = 0; i < HHRResultVector.size(); i++) {
		outputFile << "\"protein" << i << "\":{\n";
		outputFile << "\t\"proteinName\":\""
				<< HHRResultVector[i].getProteinName() << "\",\n";
		outputFile << "\t\"probab\":\"" << HHRResultVector[i].getProbab()
				<< "\",\n";
		outputFile << "\t\"eValue\":\"" << HHRResultVector[i].getExpect()
				<< "\",\n";
		outputFile << "\t\"score\":\"" << HHRResultVector[i].getScore()
				<< "\",\n";
		outputFile << "\t\"alignedCols\":\""
				<< HHRResultVector[i].getAlignedCols() << "\",\n";
		outputFile << "\t\"identities\":\""
				<< HHRResultVector[i].getIdentities() << "\",\n";
		outputFile << "\t\"similarity\":\""
				<< HHRResultVector[i].getSimilarities() << "\",\n";
		outputFile << "\t\"sumProbs\":\"" << HHRResultVector[i].getSumProbs()
				<< "\",\n";
		outputFile << "\t\"QuerySSPred\":\""
				<< HHRResultVector[i].getQuerySsPred() << "\",\n";
		outputFile << "\t\"QueryStart\":\""
				<< HHRResultVector[i].getQueryStart() << "\",\n";
		outputFile << "\t\"Query\":\"" << HHRResultVector[i].getQuery()
				<< "\",\n";
		outputFile << "\t\"QueryEnd\":\"" << HHRResultVector[i].getQueryEnd()
				<< "\",\n";
		outputFile << "\t\"QueryConsensus\":\""
				<< HHRResultVector[i].getQueryConsensus() << "\",\n";
		outputFile << "\t\"alignment\":\"" << HHRResultVector[i].getAlignment()
				<< "\",\n";
		outputFile << "\t\"TargetStart\":\""
				<< HHRResultVector[i].getTargetStart() << "\",\n";
		outputFile << "\t\"TargetConsensus\":\""
				<< HHRResultVector[i].getTargetConsensus() << "\",\n";
		outputFile << "\t\"TargetEnd\":\"" << HHRResultVector[i].getTargetEnd()
				<< "\",\n";
		outputFile << "\t\"target\":\"" << HHRResultVector[i].getTarget()
				<< "\",\n";
		outputFile << "\t\"tPred\":\"" << HHRResultVector[i].getTargetSsPred()
				<< "\"\n";
		outputFile << "},\n";
	}
	outputFile << "\"finish\":\"end\"" << "\n";
	outputFile << "}" << "\n";

	outputFile.close();
}

HHR2Json::~HHR2Json() {
	// TODO Auto-generated destructor stub
}

