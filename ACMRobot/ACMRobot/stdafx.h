// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <string>
#include <iostream>
#include <vector>
#include <windows.h>
#define emptySquare -51
struct obstacle{
	int x, y;
	obstacle(){
		x = 0;
		y = 0;
	};
	obstacle(int x2,int y2){
		x = x2;
		y = y2;
	};
	friend std::ostream& operator<<(std::ostream& os, const obstacle& object)
	{
		os << object.x << " , " << object.y;
		return os;
	}

};
struct Robot :obstacle{
public: 
	Robot():obstacle(){
	}
private:
};
class Matrix{
public:
	
	int numColl;
	int numRow;
	char* Map;
	Matrix(int,int);
	~Matrix();
	void printMap();
	bool addObject(obstacle,char);
	void RemoveObject(obstacle);
	int loc(obstacle Object){
		int index = Object.x + (Object.y*(numColl ));
		return index;
	
	};
	void MoveTo(obstacle,Robot);
	void addRow(Robot);
	void addColl(Robot);
private:
};


// TODO: reference additional headers your program requires here
