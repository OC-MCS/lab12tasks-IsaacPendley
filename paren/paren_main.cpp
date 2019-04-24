#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool isBalanced(string s)
{
	// replace the body of this function 
	vector<char> balance;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(') {
			balance.push_back('(');
		}
		else {
			if (balance.size() > 0)
			{
				balance.pop_back();
			}
			else {
				return false;
			}
		}
	}

	return (balance.size() == 0);
}

int main()
{
	ifstream file;
	file.open("balancedTestCases.txt");
	string s;
	while (getline(file, s))
	{
		if (isBalanced(s))
			cout << s << " is balanced." << endl;
		else
			cout << s << " is not balanced. " << endl;
	}

}