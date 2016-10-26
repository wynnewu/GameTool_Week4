#pragma once
#include"iostream"
#include <fstream>
#include <iostream>
#include <sstream>
#include<vector>
#include <iterator>  
#include <algorithm> 
using namespace std;
class Command {
public:
	bool findTheItemIndex();

	void inputOutput();

	string getLeftNum();
	string getRightNum();
	string getUpNum();
	string getDownNum();

	Command(string inputfilename,string outoutfilename,string num,int dis);
	~Command();
private:
	string number;
	int distance;
	int indexI;
	int indexJ;

	//4 numbers 
	string up;
	string down;
	string left;
	string right;
	string num[25][5];
	string input;
	string output;



};
