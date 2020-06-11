
#include<iostream>
#include<stack>
#include<string>
using namespace std;


bool AreParanthesesBalanced(string exp)
{
	stack<char>  S;
	char top ;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			top = S.top();
			
			if(S.empty()){
				return false;
			}
			
			if(top == '(' && exp[i] != ')' || top == '[' && exp[i] != ']' || top == '{' && exp[i] != '}')
			{
				return false;
			}
			
			else
				S.pop();
		}
	}
	return S.empty() ? true:false;
}

int main()
{
	
	string expression;
	cout<<"Enter an expression:  "; // input expression from STDIN/Console
	cin>>expression;
	if(AreParanthesesBalanced(expression))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
}
