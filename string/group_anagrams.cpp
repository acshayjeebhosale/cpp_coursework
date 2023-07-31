#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

// Function to group anagrams from a given list of words
set<set<string>> groupAnagrams(vector<string> const &words)
{
	// a set to store anagrams
	set<set<string>> anagrams;

	// construct a vector from the given words with each word sorted
	vector<string> list(words);
	for (string &s: list) {		// don't forget to put `&`
		sort(s.begin(), s.end());
	}

	// construct an `unordered_multimap` where the key is each sorted word,
	// and value is a list of indices where it is present
	unordered_multimap<string, int> map;
	for (int i = 0; i < words.size(); i++) {
		map.insert(make_pair(list[i], i));
	}

	// iterate through the multimap and read indices for each sorted key.
	// The anagrams are present in the actual list at those indices
	auto itr = map.begin();
	while (itr != map.end())
	{
		set<string> anagram;
		for (auto curr = itr; itr != map.end() && itr->first == curr->first; itr++) {
			anagram.insert(words[itr->second]);
		}
		if (anagram.size() > 1) {
			anagrams.insert(anagram);
		}
	}

	return anagrams;
}

int main()
{
	// vector of words
	vector<string> words =
	{
		"CARS", "REPAID", "DUES", "NOSE", "SIGNED", "LANE", "PAIRED", "ARCS",
		"GRAB", "USED", "ONES", "BRAG", "SUED", "LEAN", "SCAR", "DESIGN"
	};

	// get set containing all the anagrams grouped together
	set<set<string>> anagrams = groupAnagrams(words);

	// print the result
	for (set<string> anagram: anagrams) {
		for (string s: anagram) {
			cout << s << ' ';
		}
		cout << endl;
	}

	return 0;
}