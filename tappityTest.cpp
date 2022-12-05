/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, equalsReferenceLength) 
{
	tappity qTest("referencephrase");
	qTest.entry("referencephrase");
	
	ASSERT_EQ(qTest.length_difference(), 0);
}

TEST(tappityTest, greaterReferenceLength)
{
	tappity qTest("referencephrase");
	qTest.entry("reference");

	ASSERT_EQ(qTest.length_difference(), 6);
}

TEST(tappityTest, greaterInputLength)
{
	tappity qTest("reference");
	qTest.entry("referencephrase");

	ASSERT_EQ(qTest.length_difference(), 6);
}

TEST(tappityTest, emptyLengthDifference)
{
	tappity qTest("");
	qTest.entry("");

	ASSERT_EQ(qTest.length_difference(), 0);
}

TEST(tappityTest, SpacesNumbersWordsCharacters)
{
	tappity qTest("ahjssd  12323 #%$^%&  {}{P");
	qTest.entry("ahjssd  12323 #%$^%&  {}{P");

	ASSERT_EQ(qTest.length_difference(), 0);
}

TEST(tappityTest, hundredAccuracy)
{
	tappity qTest("Please give me hundred on this quiz");
	qTest.entry("Please give me hundred on this quiz");

	ASSERT_EQ(qTest.accuracy(), double(100));
}

TEST(tappityTest, zeroAccuracy)
{
	tappity qTest(" THIS IS ALL WRONG");
	qTest.entry("y");

	ASSERT_EQ(qTest.accuracy(), double(0));
}

TEST(tappityTest, emptyAccuracy)
{
	tappity qTest("");
	qTest.entry("");

	ASSERT_EQ(qTest.accuracy(), double(100));
}

TEST(tappityTest, largerReferenceWithCharacters)
{
	tappity qTest("%$#%$@ &#$@$m ^$");
	qTest.entry("%$#%$@ &#$@$m ^");

	ASSERT_EQ(qTest.accuracy(), double(93.75));
}

TEST(tappityTest, smallerReference) 
{
	tappity qTest("strings");
	qTest.entry("stringss");

	ASSERT_EQ(qTest.accuracy(), double(87.5));
}

TEST(tappityTest, randomCorrectandIncorrect)
{
	tappity qTest("this is randomly");
	qTest.entry("this iz rondamly");

	ASSERT_EQ(qTest.accuracy(), double(81.25));
}

TEST(tappityTest, capitalization)
{
	tappity qTest("STRING");
	qTest.entry("string");

	ASSERT_EQ(qTest.accuracy(), double(0));
}