convert: jsoncpp.o ConvertTools.o BLANRResult.o BLAPDBResult.o HHRNRResult.o HHRResult.o BLANR2Json.o BLAPDB2Json.o HHR2Json.o HHRNR2Json.o Driver.o ThreeDimCoordsResult.o Utility.o
	g++ jsoncpp.o ConvertTools.o BLANRResult.o BLAPDBResult.o HHRNRResult.o HHRResult.o BLANR2Json.o BLAPDB2Json.o HHR2Json.o HHRNR2Json.o Driver.o ThreeDimCoordsResult.o Utility.o -o convert

jsoncpp.o: jsoncpp.cpp
	g++ -c jsoncpp.cpp
ConvertTools.o:ConvertTools.cpp
	g++ -c ConvertTools.cpp
BLANRResult.o: BLANRResult.cpp
	g++ -c BLANRResult.cpp
BLAPDBResult.o: BLAPDBResult.cpp
	g++ -c BLAPDBResult.cpp
HHRNRResult.o:HHRNRResult.cpp
	g++ -c HHRNRResult.cpp
HHRResult.o:HHRResult.cpp
	g++ -c HHRResult.cpp
BLANR2Json.o: BLANR2Json.cpp
	g++ -c BLANR2Json.cpp
BLAPDB2Json.o: BLAPDB2Json.cpp
	g++ -c BLAPDB2Json.cpp
HHR2Json.o:HHR2Json.cpp
	g++ -c HHR2Json.cpp
HHRNR2Json.o:HHRNR2Json.cpp
	g++ -c HHRNR2Json.cpp
ThreeDimCoordsResult.o:ThreeDimCoordsResult.cpp
	g++ -c ThreeDimCoordsResult.cpp
Utility.o:Utility.cpp
	g++ -c Utility.cpp
Driver.o: Driver.cpp
	g++ -c Driver.cpp

clean:
	rm *.o convert