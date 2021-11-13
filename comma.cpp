#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	string mediator = argv[1];;

	int n = mediator.length();
	for (int i = 0; i < n / 2; i++)
	{ 
        	swap(mediator[i], mediator[n - i - 1]);
	}

	string finalString = "";
	for (int i = 1; i <= mediator.length(); i++)
	{
		finalString += mediator[i-1];
		if (i%3 == 0 && i != mediator.length())
		{
			finalString+= ",";
		}
	}

	n = finalString.length();
	for (int i = 0; i < n / 2; i++)
	{ 
        	swap(finalString[i], finalString[n - i - 1]);
	}

	cout << finalString << endl;
}
