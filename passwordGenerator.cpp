#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>

#define LENGTH_OF_WORD_VECTOR 20162
#define SEVERITY 9999

using namespace std;

struct password
{
	string word;
	string cappedWord;
	int num1;
	int num2;
	int num3;
	string sym1;
	string sym2;
};

string insertCommas(unsigned long long number)
{
	string mediator = to_string(number);

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

	return finalString;
}

void compare(string input, string key, unsigned long long &otherCounter)
{
        if (input == key)
        {
                otherCounter++;
		ofstream fileTool;
		string printer = insertCommas(otherCounter);
		fileTool.open("output.txt");
                fileTool << "Cracked '" << input << "' in " << printer << " guesses." << endl;
		fileTool.close();
                exit(0);
        }

        else
        {
               otherCounter++;
        }
}

int quadHash(int current, int counter, int size)
{
	return (current + (counter*counter) % size);
}

string capitalizeFirst(string word)
{
        word[0] = toupper(word[0]);
        return word;
}

int main(int argc, char const *argv[])
{
	srand( time(NULL) );
	ifstream fileToolCommon;
	ifstream fileToolWords;
	ifstream fileToolSyms;

	vector<string> words;
	vector<string> syms1;

        unsigned long long iterationCounter = 0;
	string key = argv[1];

	fileToolCommon.open("mostCommon.txt");
	int weirdCounter = 1;
        if (fileToolCommon.is_open())
        {
                string line = "";
                while (getline(fileToolCommon, line))
                {
			compare(line, key, iterationCounter);
			weirdCounter++;
                }
        }

        else
        {
                cout << "The file didn't open correctly" << endl;
        }

        fileToolCommon.close();

        fileToolWords.open("wordAssets.txt");
        if (fileToolWords.is_open())
        {
                string line = "";
                while (getline(fileToolWords, line))
                {
			words.push_back(line);
                }
        }

        else
        {
                cout << "The file didn't open correctly" << endl;
        }

        fileToolWords.close();

        fileToolSyms.open("symbolAssets.txt");
        if (fileToolSyms.is_open())
        {
                string line = "";
                while (getline(fileToolSyms, line))
                {
			syms1.push_back(line);
                }
        }

        else
        {
                cout << "The file didn't open correctly" << endl;
        }

        fileToolSyms.close();

//----------------------------------------------------------------------------

	int wordTracker = 0;
	int num1Tracker = 0;
	int num2Tracker = 0;
	int num3Tracker = 0;
	int sym1Tracker = 0;
	int sym2Tracker = 10;
	int wholeTracker = 1;

	password currPassword;
	currPassword.word = words[wordTracker];
	currPassword.cappedWord = capitalizeFirst(words[wordTracker]);
	currPassword.num1 = num1Tracker;
	currPassword.num2 = num2Tracker;
	currPassword.num3 = num3Tracker;
	currPassword.sym1 = syms1[sym1Tracker];
	currPassword.sym2 = syms1[sym2Tracker];

	while (1 > 0)
	{
		string output;

		cout << "on iteration " << wordTracker << " out of 20162" << endl;
		if (currPassword.word == "bread")
		{
			cout << "bread" << endl;
			system("echo checking bread | ssmtp 9702195822@vtext.com");
		}
		while (wholeTracker < SEVERITY)
		{
			output = currPassword.word;
			compare(output, key, iterationCounter);
			output = currPassword.word + to_string(currPassword.num1);
			compare(output, key, iterationCounter);
			output = currPassword.word + to_string(currPassword.num1) + to_string(currPassword.num2);
			compare(output, key, iterationCounter);
			output = currPassword.word + to_string(currPassword.num1) + to_string(currPassword.num2) + currPassword.sym1;
			compare(output, key, iterationCounter);
			output = currPassword.word + to_string(currPassword.num1) + to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2;
			compare(output, key, iterationCounter);

			output = currPassword.cappedWord;
			compare(output, key, iterationCounter);
			output = currPassword.cappedWord + to_string(currPassword.num1);
			compare(output, key, iterationCounter);
			output = currPassword.cappedWord + to_string(currPassword.num1) + to_string(currPassword.num2);
			compare(output, key, iterationCounter);
			output = currPassword.cappedWord + to_string(currPassword.num1) + to_string(currPassword.num2) + currPassword.sym1;
			compare(output, key, iterationCounter);
			output = currPassword.cappedWord + to_string(currPassword.num1) + to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2;
			compare(output, key, iterationCounter);

			output = currPassword.word;
			compare(output, key, iterationCounter);
			output = currPassword.word + to_string(currPassword.num3);
			compare(output, key, iterationCounter);
			output = currPassword.word + to_string(currPassword.num3) + currPassword.sym1;
			compare(output, key, iterationCounter);
			output = currPassword.word + to_string(currPassword.num3) + currPassword.sym1 + currPassword.sym2;
			compare(output, key, iterationCounter);

			output = currPassword.cappedWord;
			compare(output, key, iterationCounter);
			output = currPassword.cappedWord + to_string(currPassword.num3);
			compare(output, key, iterationCounter);
			output = currPassword.cappedWord + to_string(currPassword.num3) + currPassword.sym1;
			compare(output, key, iterationCounter);
			output = currPassword.cappedWord + to_string(currPassword.num3) + currPassword.sym1 + currPassword.sym2;
			compare(output, key, iterationCounter);

			output = to_string(currPassword.num1) + to_string(currPassword.num2);
			compare(output, key, iterationCounter);
			output = to_string(currPassword.num1) + to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2 + currPassword.word;
			compare(output, key, iterationCounter);
			output = to_string(currPassword.num3) + currPassword.sym1 + currPassword.sym2 + currPassword.word;
			compare(output, key, iterationCounter);

			output = to_string(currPassword.num1) + to_string(currPassword.num2);
			compare(output, key, iterationCounter);
			output = to_string(currPassword.num1) + to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2 + currPassword.cappedWord;
			compare(output, key, iterationCounter);
			output = to_string(currPassword.num3) + currPassword.sym1 + currPassword.sym2 + currPassword.cappedWord;
			compare(output, key, iterationCounter);

			output = to_string(currPassword.num2);
			compare(output, key, iterationCounter);
			output = to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2 + currPassword.word;
			compare(output, key, iterationCounter);
			output = to_string(currPassword.num3) + currPassword.sym2 + currPassword.word;
			compare(output, key, iterationCounter);
			output = to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2 + currPassword.word + to_string(currPassword.num1);
			compare(output, key, iterationCounter);
			output = currPassword.sym1 + currPassword.sym2 + currPassword.word + to_string(currPassword.num3);
			compare(output, key, iterationCounter);

			output = to_string(currPassword.num2);
			compare(output, key, iterationCounter);
			output = to_string(currPassword.num3);
			compare(output, key, iterationCounter);
			output = to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2 + currPassword.cappedWord;
			compare(output, key, iterationCounter);
			output = to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2 + currPassword.cappedWord + to_string(currPassword.num1);
			compare(output, key, iterationCounter);

			output = currPassword.sym1 + currPassword.sym2 + currPassword.word;
			compare(output, key, iterationCounter);
			output = currPassword.sym1 + currPassword.sym2 + currPassword.word + to_string(currPassword.num1);
			compare(output, key, iterationCounter);
			output = currPassword.sym1 + currPassword.sym2 + currPassword.word + to_string(currPassword.num1) + to_string(currPassword.num2);
			compare(output, key, iterationCounter);

			output = currPassword.sym1 + currPassword.sym2 + currPassword.cappedWord;
			compare(output, key, iterationCounter);
			output = currPassword.sym1 + currPassword.sym2 + currPassword.cappedWord + to_string(currPassword.num1);
			compare(output, key, iterationCounter);
			output = currPassword.sym1 + currPassword.sym2 + currPassword.cappedWord + to_string(currPassword.num1) + to_string(currPassword.num2);
			compare(output, key, iterationCounter);

			output = currPassword.sym2 + currPassword.word;
			compare(output, key, iterationCounter);
			output = currPassword.sym2 + currPassword.word + to_string(currPassword.num1);
			compare(output, key, iterationCounter);
			output = currPassword.sym2 + currPassword.word + to_string(currPassword.num1) + to_string(currPassword.num2);
			compare(output, key, iterationCounter);
			
			output = currPassword.sym2 + currPassword.cappedWord;
			compare(output, key, iterationCounter);
			output = currPassword.sym2 + currPassword.cappedWord + to_string(currPassword.num1);
			compare(output, key, iterationCounter);
			output = currPassword.sym2 + currPassword.cappedWord + to_string(currPassword.num1) + to_string(currPassword.num2);
			compare(output, key, iterationCounter);

			output = to_string(currPassword.num1) + currPassword.word + currPassword.sym2;
			compare(output, key, iterationCounter);
			output = currPassword.sym1 + currPassword.word + to_string(currPassword.num1);
			compare(output, key, iterationCounter);
			output = to_string(currPassword.num1) + currPassword.word + currPassword.sym2 + to_string(currPassword.num2);
			compare(output, key, iterationCounter);
			output = currPassword.word + currPassword.sym1 + currPassword.sym2 + to_string(currPassword.num2);
			compare(output, key, iterationCounter);
			output = currPassword.word + currPassword.sym1;
			compare(output, key, iterationCounter);

			output = to_string(currPassword.num3) + currPassword.word + currPassword.sym2;
			compare(output, key, iterationCounter);
			output = currPassword.sym1 + currPassword.word + to_string(currPassword.num3);
			compare(output, key, iterationCounter);
			output = to_string(currPassword.num3) + currPassword.word + currPassword.sym2 + to_string(currPassword.num2);
			compare(output, key, iterationCounter);
			output = currPassword.word + currPassword.sym1 + currPassword.sym2 + to_string(currPassword.num3);
			compare(output, key, iterationCounter);

			output = to_string(currPassword.num1) + currPassword.cappedWord + currPassword.sym2;
                        compare(output, key, iterationCounter);
                        output = currPassword.sym1 + currPassword.cappedWord + to_string(currPassword.num1);
                        compare(output, key, iterationCounter);
                        output = to_string(currPassword.num1) + currPassword.cappedWord + currPassword.sym2 + to_string(currPassword.num2);
                        compare(output, key, iterationCounter);
                        output = currPassword.cappedWord + currPassword.sym1 + currPassword.sym2 + to_string(currPassword.num2);
                        compare(output, key, iterationCounter);

			output = to_string(currPassword.num3) + currPassword.cappedWord + currPassword.sym2;
                        compare(output, key, iterationCounter);
                        output = currPassword.sym1 + currPassword.cappedWord + to_string(currPassword.num3);
                        compare(output, key, iterationCounter);
                        output = to_string(currPassword.num3) + currPassword.cappedWord + currPassword.sym2 + to_string(currPassword.num2);
                        compare(output, key, iterationCounter);
                        output = currPassword.cappedWord + currPassword.sym1 + currPassword.sym2 + to_string(currPassword.num3);
                        compare(output, key, iterationCounter);

			num1Tracker = (rand()%10);
			num2Tracker = (rand()%1000);
			num3Tracker = (rand()%10000);
			sym1Tracker = (rand()%10);
			sym2Tracker = (rand()%10);

			currPassword.num1 = num1Tracker;
			currPassword.num2 = num2Tracker;
			currPassword.num3 = num3Tracker;
			currPassword.sym1 = syms1[sym1Tracker];
			currPassword.sym2 = syms1[sym2Tracker];
			wholeTracker++;
		}

		wholeTracker = 0;
		wordTracker++;

		currPassword.word = words[wordTracker];
		currPassword.cappedWord = capitalizeFirst(words[wordTracker]);
	}
}



























