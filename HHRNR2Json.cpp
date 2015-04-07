/*
 * HHRNR2Json.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */
#include "ConvertTools.h"
#include "HHRNR2Json.h"

HHRNR2Json::HHRNR2Json(char* inputFilename):ConvertTools(inputFilename) {
	// TODO Auto-generated constructor stub

}

void HHRNR2Json::convert(){
	char line[500];
		int counter = 1;
		FILE* inputFile = fopen(fileName, "r");
		ofstream outputFile("HHRNRResult.json");

		outputFile << "{" << "\n";
		while (fgets(line, 200, inputFile) != NULL) {

			if (strstr(line, ">") != NULL) {
				outputFile << "\"protein" << counter << "\":{\n";
				//get protein name
				char proteinName[200];
				sscanf(line, "%s ", proteinName);
				string tmp(proteinName);
				outputFile << "\t\"proteinName\":\"" << tmp.substr(1, 7) << "\",\n";

				//get probab, E-value, Score, Aligned_cols, Identities, Similarity, Sum_probs
				fgets(line, 500, inputFile);
				char* pos1 = strstr(line, "=");
				float probab;
				sscanf(pos1 + 1, "%f", &probab);
				outputFile << "\t\"probab\":\"" << probab << "\",\n";

				char* pos2 = strstr(pos1 + 1, "=");
				float eValue;
				sscanf(pos2 + 1, "%f", &eValue);
				outputFile << "\t\"eValue\":\"" << eValue << "\",\n";

				char* pos3 = strstr(pos2 + 1, "=");
				float score;
				sscanf(pos3 + 1, "%f", &score);
				outputFile << "\t\"score\":\"" << score << "\",\n";

				char* pos4 = strstr(pos3 + 1, "=");
				int alignedCols;
				sscanf(pos4 + 1, "%d", &alignedCols);
				outputFile << "\t\"alignedCols\":\"" << alignedCols << "\",\n";

				char* pos5 = strstr(pos4 + 1, "=");
				float identities;
				sscanf(pos5 + 1, "%f", &identities);
				outputFile << "\t\"identities\":\"" << identities << "\",\n";

				char* pos6 = strstr(pos5 + 1, "=");
				float similarity;
				sscanf(pos6 + 1, "%f", &similarity);
				outputFile << "\t\"similarity\":\"" << similarity << "\",\n";

				char* pos7 = strstr(pos6 + 1, "=");
				float sumProbs;
				sscanf(pos7 + 1, "%f", &sumProbs);
				outputFile << "\t\"sumProbs\":\"" << sumProbs << "\",\n";

				fgets(line, 200, inputFile); //blank

				//get the Q ref|

				fgets(line, 200, inputFile);
				int QRefStart;
				char QRef[100];
				int QRefEnd;
				sscanf(line + 17, "%d %s %d", &QRefStart, QRef, &QRefEnd);
				outputFile << "\t\"QRefStart\":\"" << QRefStart << "\",\n";
				outputFile << "\t\"QRef\":\"" << QRef << "\",\n";
				outputFile << "\t\"QRefEnd\":\"" << QRefEnd << "\",\n";

				//get the Q Consensus
				fgets(line, 200, inputFile);
				int QConsensusStart;
				char QConsensus[100];
				int QConsensusEnd;
				sscanf(line + 17, "%d %s %d", &QConsensusStart, QConsensus,
						&QConsensusEnd);
				outputFile << "\t\"QConsensusStart\":\"" << QConsensusStart
						<< "\",\n";
				outputFile << "\t\"QConsensus\":\"" << QConsensus << "\",\n";
				outputFile << "\t\"QConsensusEnd\":\"" << QConsensusEnd << "\",\n";

				//get alignment
				fgets(line, 200, inputFile);
				char alignment[100];
				sscanf(line + 17, "%s", alignment);
				outputFile << "\t\"alignment\":\"" << alignment << "\",\n";

				//get the T Consensus
				fgets(line, 200, inputFile);
				int TConsensusStart;
				char TConsensus[100];
				int TConsensusEnd;
				sscanf(line + 17, "%d %s %d", &TConsensusStart, TConsensus,
						&TConsensusEnd);
				outputFile << "\t\"TConsensusStart\":\"" << TConsensusStart
						<< "\",\n";
				outputFile << "\t\"TConsensus\":\"" << TConsensus << "\",\n";
				outputFile << "\t\"TConsensusEnd\":\"" << TConsensusEnd << "\",\n";

				//get the Target
				fgets(line, 200, inputFile);
				int targetStart;
				char target[100];
				int targetEnd;
				sscanf(line + 17, "%d %s %d", &targetStart, target, &targetEnd);
				outputFile << "\t\"targetStart\":\"" << targetStart << "\",\n";
				outputFile << "\t\"target\":\"" << target << "\",\n";
				outputFile << "\t\"targetEnd\":\"" << targetEnd << "\",\n";

				//get the TDssp
				fgets(line, 200, inputFile);
				char tDssp[100];
				sscanf(line + 17, "%s", tDssp);
				outputFile << "\t\"tDssp\":\"" << tDssp << "\",\n";

				//get the TPred
				fgets(line, 200, inputFile);
				char tPred[100];
				sscanf(line + 17, "%s", tPred);
				outputFile << "\t\"tPred\":\"" << tPred << "\"\n";

				outputFile << "},\n";
				counter++;
			}
		}
		outputFile << "\"finish\":\"end\"" << "\n";
		outputFile << "}" << "\n";
		fclose(inputFile);
		outputFile.close();

}

HHRNR2Json::~HHRNR2Json() {
	// TODO Auto-generated destructor stub
}

