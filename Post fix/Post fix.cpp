// Post fix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <boost/algorithm/string.hpp>


using namespace std;
int evaluateexpression(vector<string>& expression);
bool isnumber(string input);

int main()
{
	//Defines string and vector.
	string expression;
	vector<string> expressionvector;
	int result;

	//Getting input and evaluation the expression.
	getline(cin, expression);
	boost::split(expressionvector, expression, boost::is_any_of(" "));
	result = evaluateexpression(expressionvector);
	cout << "Result : " << result << endl;

return 0;
system("pause");
}

//Evelatuating function for the expression.
int evaluateexpression(vector<string>& expression)
{
	vector<int> stackexpression;
	int x, y;
	int result = NULL;
	//Loops through the whole expression.
	for (unsigned int i = 0; i < expression.size(); i++)
	{
		//Push to the stack if it's an integer.
		if (isnumber(expression[i]))
		{
			stackexpression.push_back(stoi(expression[i]));
		}

		else
		{	//Check if the stack isn't empty.
			if (stackexpression.empty())
			{
				cout << "Stack is empty. An operation is not valid." << endl;
				break;
			}
			//Make sure there's more than one variable for the stack.
			else if (stackexpression.size() == 1)
			{
				cout << "There is only one element on the stack. An operation is not valid." << endl;
				break;
			}
			//Perform addition.
			else if (expression[i] == "+")
			{
				x = stackexpression.back();
				stackexpression.pop_back();

				y = stackexpression.back();
				stackexpression.pop_back();

				stackexpression.push_back((x + y));
			}
			//Perform subtraction.
			else if (expression[i] == "-")
			{
				x = stackexpression.back();
				stackexpression.pop_back();

				y = stackexpression.back();
				stackexpression.pop_back();

				stackexpression.push_back((y - x));
			}
			//Perform multiplication.
			else if (expression[i] == "*")
			{
				x = stackexpression.back();
				stackexpression.pop_back();

				y = stackexpression.back();
				stackexpression.pop_back();

				stackexpression.push_back((x * y));
			}
			//Perform division.
			else if (expression[i] == "/")
			{
				x = stackexpression.back();
				stackexpression.pop_back();

				y = stackexpression.back();
				stackexpression.pop_back();

				stackexpression.push_back((y / x));
			}
			//Perform modulus.
			else if (expression[i] == "%")
			{
				x = stackexpression.back();
				stackexpression.pop_back();

				y = stackexpression.back();
				stackexpression.pop_back();

				stackexpression.push_back((x % y));
			}
			//Perform power.
			else if (expression[i] == "^")
			{
				x = stackexpression.back();
				stackexpression.pop_back();

				y = stackexpression.back();
				stackexpression.pop_back();

				stackexpression.push_back(pow(x, y));
			}
			//Otherwise incorrect character.
			else
			{
				cout << "That is not a valid operator." << endl;
				break;
			}
		}
	}
	//Getting result and return result.
	if (!(stackexpression.empty()))
	{
		result = stackexpression.back();
		stackexpression.pop_back();
	}
	return result;
}
//Making sure we have a number string.
bool isnumber(string input)
{
	//Loop through every character and check if it's a digit.
	for (auto c : input)
	{
		if (!(isdigit(c)))
			return false;
	}
	return true;
}
