#pragma once


#include <cppunit/extensions/HelperMacros.h>


class TestCommand:public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(TestCommand);

	CPPUNIT_TEST(testUpNum);
	CPPUNIT_TEST(testDownNum);
	CPPUNIT_TEST(testLeftNum);
	CPPUNIT_TEST(testRightNum);
	CPPUNIT_TEST(testFindNumber);
	CPPUNIT_TEST_SUITE_END();
public:
	TestCommand();
	~TestCommand();

	void testUpNum();
	void testDownNum();
	void testLeftNum();
	void testRightNum();
	void testFindNumber();
};

