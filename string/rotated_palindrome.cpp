#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Recursive function to check if `str[low…high]` is a palindrome or not
bool isPalindrome(string str, int low, int high)
{
	return (low >= high) || (str[low] == str[high] &&
			isPalindrome(str, low + 1, high - 1));
}

// Function to check if a given string is a rotated palindrome or not
bool isRotatedPalindrome(string str)
{
	// length of the given string
	int n = str.length();

	// check for all rotations of the given string if it
	// is palindrome or not
	for (int i = 0; i < n; i++)
	{
		// in-place rotate the string by 1 unit
		rotate(str.begin(), str.begin() + 1, str.end());
		// rotate(str.rbegin(), str.rbegin() + 1, str.rend());

		// return true if the rotation is a palindrome
		if (isPalindrome(str, 0, n - 1)) {
			return true;
		}
	}

	// return false if no rotation is a palindrome
	return false;
}

int main()
{
	// palindromic string
	string str = "ABCDCBA";

	// rotate it by 2 units
	rotate(str.begin(), str.begin() + 2, str.end());

	if (isRotatedPalindrome(str)) {
		cout << "The string is a rotated palindrome";
	}
	else {
		cout << "The string is not a rotated palindrome";
	}

	return 0;
}