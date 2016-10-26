#include "Command.h"


Command::Command(string inputpath, string outputpath, string num, int dis)
{
	input = inputpath;
	output = outputpath;
	number = num;
	distance = dis;
}


void Command::inputOutput() {


	ofstream myfile(input);

	if (myfile.is_open())
	{
		myfile << "1 2 3 4 5\n";
		myfile << "6 7 8 9 10\n";
		myfile << "11 12.2 13 14 15\n";
		myfile << "16 17 18 19 20\n";
		myfile << "21 22 23 24 25\n";
		myfile << "26.3 27 28 29 30\n";
		myfile << "31 32 33.4 34 35\n";
		myfile << "36 37 38 39 40\n";
		myfile << "41 42.5 43 44 45\n";
		myfile << "46 47.4 48 49.8 50\n";
		myfile << "51 52.5 53 54 55\n";
		myfile << "56 57 58 59 60\n";
		myfile << "61 62 63 64 65\n";
		myfile << "66 67 68.9 69 70\n";
		myfile << "71 72 73 74 75\n";
		myfile << "76 77.3 78 79 80\n";
		myfile << "81 82 83 84 85\n";
		myfile << "86 87 88 89 90\n";
		myfile << "91 92.5 93 94 95\n";
		myfile << "96 97 98 99 100\n";
		myfile.close();

	}


	ifstream infile(output);


	vector<string> it;


	if (!infile)
	{
		cout << "Error opening the file. \n";
	}


	while (infile.good())
	{
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 5; j++) {

				infile >> num[i][j];
			}

		}

	}
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 5; j++) {

			it.push_back(num[i][j]);
		}
	}

	cout << "output the file" << endl;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 5; j++) {

			cout << num[i][j] << "  ";
		}
		cout << endl;
	}


}

bool Command::findTheItemIndex() {

	int tempI;
	int tempJ;
	bool temp = false;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 5; j++) {
			if (number == num[i][j])
			{
				tempI = i;
				tempJ = j;
				indexI = tempI;
				indexJ = tempJ;
				cout << "Found!" << endl;
				temp = true;
			}

		}

	}

	return temp;
}

string Command::getLeftNum() {
	if (indexJ - distance >= 0)
	{
		left = num[indexI][indexJ - distance];


	}
	else {
		left = "-1";
	}
	cout << "Left: " << left << endl;

	return left;

}
string Command::getRightNum() {
	if (indexI + distance <= 100)
	{
		if (indexJ + distance < 100)
		{

			right = num[indexI][indexJ + distance];
		}
	}
	else {
		right = "-1";

	}
	cout << "Right: " << right << endl;
	return right;

}
string Command::getUpNum() {

	if (indexI - distance >= 0)
	{
		up = num[indexI - distance][indexJ];
	}
	else {
		up = "-1";
	}

	cout << "Up: " << up << endl;
	return up;
}
string Command::getDownNum() {
	if (indexI + distance <= 100)
	{

		down = num[indexI + distance][indexJ];

	}
	else {
		down = "-1";
	}

	cout << "Down: " << down << endl;
	return down;
}

Command::~Command()
{
}
