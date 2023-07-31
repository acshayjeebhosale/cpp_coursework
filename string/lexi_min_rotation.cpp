#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to find the lexicographically minimal string rotation
string findLexicalMinRotation(string str)
{
	// to store the lexicographic minimum string
	string min = str;

	for (int i = 0; i < str.length(); i++)
	{
		// left-rotate the string by 1 unit
		rotate(str.begin(), str.begin() + 1, str.end());

		// update the result if the rotation is minimum so far
		if (str.compare(min) < 0) {
			min = str;
		}
	}

	return min;
}

int main()
{
	string str = "bbaaccaadd";

	cout << "The lexicographically minimal rotation of " << str
		 << " is " << findLexicalMinRotation(str);

	return 0;
}