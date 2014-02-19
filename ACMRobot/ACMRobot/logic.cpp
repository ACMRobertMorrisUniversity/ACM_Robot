// logic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std; 
Matrix::Matrix(int col, int  row){
	numColl=col;
	numRow = row;
	Map = new char[row*col];
	Map[0] = 'R';

}
Matrix::~Matrix(){}
void Matrix::printMap(){
	system("CLS");
	int loc = 0;
	
	for (int x = 0; x <numRow ; x++){
		for (int y = 0; y < numColl; y++){
			cout <<Map[loc];
			loc++;

		}
		cout << endl;
	}	
}
bool Matrix::addObject(obstacle object,char type){
	bool effect = true; 
	if ((int)Map[loc(object)] != emptySquare){
		effect = false;
	}
	else
	{
		Map[loc(object)] = type;
	}
		return effect;
}
void Matrix::RemoveObject(obstacle x){
	Map[loc(x)] = emptySquare;



}
void Matrix::MoveTo(obstacle newloc,Robot r){
	cout << r << endl;
	RemoveObject(r);
	if (r.x != newloc.x){
		r.x++;
		if ((r.x ) == numRow)
			addColl(r);
	}
	if (r.y != newloc.y){
		r.y++;
		if((r.y)==numColl)
		addRow(r);
	
	}
	cout << r << endl;
	addObject(r, 'R');
	Sleep(1000);
	printMap();
	if (r.x == newloc.x&&r.y == newloc.y)
		return;
	MoveTo(newloc, r);
}
void Matrix::addColl(Robot R){
	cout << "Collumn Added" << endl;

}
void Matrix::addRow(Robot R){
	cout << "Row Added" << endl;



}
int _tmain(int argc, _TCHAR* argv[])
{	
Matrix test =  Matrix(5,5);
Robot r = Robot();
test.addObject(obstacle(1, 1), 'q');
test.printMap();
test.MoveTo(obstacle(0,1), r);

	
	system("Pause");
	return 0;
}


