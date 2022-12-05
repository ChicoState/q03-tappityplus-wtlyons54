#include "tappity.h"
#include <cstring>

/**
 * Class for tappity
**/


//Constructor sets the reference phrase
tappity::tappity(std::string reference)
{
	ref = reference;
	inp = "";
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
	inp = input;	
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
	if(ref.length() > inp.length()){
		int dif = abs(ref.length() - inp.length());
		return dif;
	}else if(inp.length() > ref.length()){
		int dif = abs(inp.length() - ref.length());
		return dif;
	}
	return 0;
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
	int rl = ref.length();
	int il = inp.length();
	int longest;
	if(ref.length() > inp.length()){
		longest = ref.length();
	}else{
		longest = inp.length();
	}
	char r[rl+1];
	char in[il+1];

	strcpy(r, ref.c_str());
	strcpy(in, inp.c_str());

	double num_correct = 0;
	double percent;

	if(inp == ref){
		return 100;
	}else{
		for(int i=0; i < longest; i++){
			if(r[i] == in[i]){
				num_correct++;
			}
		}
		percent = num_correct/longest * 100;
		return percent;
	}
}
