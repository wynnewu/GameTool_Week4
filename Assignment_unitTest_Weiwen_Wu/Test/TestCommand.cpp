#include "TestCommand.h"
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include"TestCommand.h"
#include"Command.h"
#include<cppunit/XmlOutputter.h>
#include"iostream"

/*
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


*/
int main()
{
	string fileName;
	cout << "Create File: input file name" << endl;
	cin >> fileName;
	int distance;
	string output;
	cout << "Output the file: enter the file name" << endl;
	cin >> output;
	string number;
	cout << "input the number(1-100)" << endl;
	cin >> number;
	cout << "input the distance" << endl;
	cin >> distance;
	Command c(fileName, output, number, distance);

	c.inputOutput();
	c.findTheItemIndex();
	
	cout << "=======print======" << endl;
	c.getUpNum();

	c.getDownNum();
	c.getLeftNum();
	c.getRightNum();

	CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();
	CppUnit::TextUi::TestRunner runner;

	std::ofstream fs("Result.txt");
	CppUnit::XmlOutputter*outputter = new CppUnit::XmlOutputter(&runner.result(), fs);
	runner.setOutputter(outputter);

	runner.addTest(suite);
	bool wasSucessful = runner.run();

	return wasSucessful ? 0 : 1;

	

}


void TestCommand::testFindNumber() {
	Command test1("test1.txt", "test1.txt", "10", 2);
	test1.inputOutput();
	test1.findTheItemIndex();

	CPPUNIT_ASSERT(test1.findTheItemIndex()==true);

}
void TestCommand::testUpNum() {
	Command test1("test1.txt", "test1.txt", "10", 2);
	test1.inputOutput();
	test1.findTheItemIndex();
	CPPUNIT_ASSERT(test1.getUpNum() == "-1");


}
void TestCommand::testDownNum() {
	Command test1("test1.txt", "test1.txt", "3", 1);
	test1.inputOutput();
	test1.findTheItemIndex();
	CPPUNIT_ASSERT(test1.getDownNum() == "8");

}
void TestCommand::testLeftNum() {
	Command test1("test1.txt", "test1.txt", "74", 3);
	test1.inputOutput();
	test1.findTheItemIndex();
	CPPUNIT_ASSERT(test1.getDownNum() == "71");

}
void TestCommand::testRightNum() {
	Command test1("test1.txt", "test1.txt", "66", 2);
	test1.inputOutput();
	test1.findTheItemIndex();
	CPPUNIT_ASSERT(test1.getDownNum() == "68.9");
}

TestCommand::TestCommand()
{
}


TestCommand::~TestCommand()
{
}
