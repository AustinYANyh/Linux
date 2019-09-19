#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <limits>
#include <functional>

using namespace std;

string solution(vector < string > input)
{
	string q{ 0 };

	if (input[0][0] == '0' && input[0][2] == '0')
	{
		input[0][0] = input[0][4];
		input[0][2] = input[0][6];
		input[0][4] = '0';
		input[0][6] = '0';
	}

	//if (input[0][0] == 0)
	//{
	//	input[0][0] = input[0][4] + input[0][6];
	//	input[1] = input[3];
	//	input[2] = 0;
	//	input[3] = 0;
	//}
	else
	{
		char s = { 0 };

		input[0][0] = *_itoa(atoi(&input[0][0]) + atoi(&input[0][2]), &s, 10);
		input[0][2] = *_itoa(atoi(&input[0][4]) + atoi(&input[0][6]), &s, 10);
		input[0][4] = '0';
		input[0][6] = '0';
	}

	string s1 = { 0 };
	s1 = input[0][0];
	s1 += ' ';
	s1 += input[0][2];
	s1 += ' ';
	s1 += input[0][4];
	s1 += ' ';
	s1 += input[0][6];

	return s1;
}						

int main() 
{
	string res;

	int _input_size = 0;
	cin >> _input_size;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<string> _input;

	string _input_item;

	for (int _input_i = 0; _input_i < _input_size; _input_i++) 
	{
		getline(cin, _input_item);
		_input.push_back(_input_item);
	}

	res = solution(_input);
	cout << res << endl;

	system("pause");
	return 0;
}
