#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string remover(string s) {
	string fixed;
	for (int i = 0; i < s.length(); i++)
	{
		if (isupper(s[i])) {
			fixed += tolower(s[i]);
		}
		else if (s[i] != ' ' && !(ispunct(s[i])))
		{
			fixed += s[i];
		}
	}
	return fixed;
}

bool isPalindrome(string s) {
	// Copy the string to a string with no punctuation spaces or capitolization 
	string sCopy = remover(s);
	if (sCopy.length() == 0 || sCopy.length() == 1) {
		return true;
	}
	else if (sCopy.length() == 2 && sCopy[0] == sCopy[1])
	{
		return true;
	}
	else if (sCopy[0] == sCopy[sCopy.length() - 1]) {
		string newS;
		for (int i = 1; i < (sCopy.length() - 1); i++)
		{
			string temp = " ";
			temp[0] = sCopy[i];
			newS.append(reinterpret_cast<char*>(&temp[0]));
		}
		return isPalindrome(newS);
	}
	else {
		return false;
	}
	return true;
}

int main()
{
	ifstream file;
	file.open("testCases.txt");
	string s;
	while (getline(file, s))
	{
		if (isPalindrome(s))
			cout << s << " is a palindrome." << endl;
		else
			cout << s << " is not a palindrome. " << endl;
	}
	file.close();
	return 0;
}