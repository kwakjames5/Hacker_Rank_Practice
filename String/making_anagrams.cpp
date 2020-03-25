#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b)
{
	// keeps track of minimum deletions needed
	int deletions = 0;

	// these arrays are set to 26 for each letter in the alphabet to be potentially tracked
	int a_frequency[26];
	int b_frequency[26];

	// initialize the empty arrays with 0s first
	for(int i = 0; i < 26; i ++)
	{
		a_frequency[i] = b_frequency[i] = 0;
	}

	// to get track of the letters in string a
	for(int i = 0; i < a.size(); i++)
	{
		// get the current character we are on
		char curr_char = a.at(i);

		// changes the curr_char to a ascii int value by type casting the curr_char as an int
		int char_to_int = (int)curr_char;

		// char_to_int is an ascii int value, meaning that any 'a's we get are 97, 'b's are 98, etc.
		// to counteract this so we can use the position for our alphabet array, subtract (int)'a'
		// this makes it so 'a's are tracked as 0, 'b' at 1, etc.
		int position = char_to_int - (int)'a';

		// increment the counter of the letter we are testing
		a_frequency[position]++;
	}

	// to get track of the letters in string b
	for(int i = 0; i < b.size(); i++)
	{
		char curr_char = b.at(i);
		int char_to_int = (int)curr_char;
		int position = char_to_int - (int)'a';
		b_frequency[position]++;
	}

	// calculates the difference of quantities of each alphabet letter. updates deletion count every time there is a difference
	for(int i = 0; i < 26; i++)
	{
		int difference = abs(a_frequency[i] - b_frequency[i]);
		deletions += difference;
	}

	return deletions;

}

int main()
{
    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    cout << res << "\n";

    return 0;
}
