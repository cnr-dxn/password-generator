#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>

#define LENGTH_OF_WORD_VECTOR 20063
#define SEVERITY 9999

using namespace std;

struct password
{
	string word;
	string cappedWord;
	int num1;
	int num2;
	string sym1;
	string sym2;
};

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

	fileToolCommon.open("mostCommon.txt");
        if (fileToolCommon.is_open())
        {
                string line = "";
                while (getline(fileToolCommon, line))
                {
                //        cout << line << endl;
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
	int tempCounter = 0;
        if (fileToolSyms.is_open())
        {
                string line = "";
                while (getline(fileToolSyms, line))
                {
			syms1.push_back(line);
			cout << syms1[tempCounter] << endl;
			tempCounter++;
                }
        }

        else
        {
                cout << "The file didn't open correctly" << endl;
        }

        fileToolSyms.close();

	
	cout << "words.size(): " << words.size() << endl;
	cout << "syms1.size(): " << syms1.size() << endl;

//----------------------------------------------------------------------------

	int wordTracker = 0;
	int num1Tracker = 0;
	int num2Tracker = 9999;
	int sym1Tracker = 0;
	int sym2Tracker = 10;
	int wholeTracker = 1;

	password currPassword;
	currPassword.word = words[wordTracker];
	currPassword.cappedWord = capitalizeFirst(words[wordTracker]);
	currPassword.num1 = num1Tracker;
	currPassword.num2 = num2Tracker;
	currPassword.sym1 = syms1[sym1Tracker];
	currPassword.sym2 = syms1[sym2Tracker];

	while (1 > 0)
	{
		string output;

		while (wholeTracker < SEVERITY)
		{
			output = currPassword.word;
			cout << output << endl;
			output = currPassword.word + to_string(currPassword.num1);
			cout << output << endl;
			output = currPassword.word + to_string(currPassword.num1) + to_string(currPassword.num2);
			cout << output << endl;
			output = currPassword.word + to_string(currPassword.num1) + to_string(currPassword.num2) + currPassword.sym1;
			cout << output << endl;
			output = currPassword.word + to_string(currPassword.num1) + to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2;
			cout << output << endl; 

			output = currPassword.cappedWord;
			cout << output << endl;
			output = currPassword.cappedWord + to_string(currPassword.num1);
			cout << output << endl;
			output = currPassword.cappedWord + to_string(currPassword.num1) + to_string(currPassword.num2);
			cout << output << endl;
			output = currPassword.cappedWord + to_string(currPassword.num1) + to_string(currPassword.num2) + currPassword.sym1;
			cout << output << endl;
			output = currPassword.cappedWord + to_string(currPassword.num1) + to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2;
			cout << output << endl; 

			output = to_string(currPassword.num1) + to_string(currPassword.num2);
			cout << output << endl;
			output = to_string(currPassword.num1) + to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2 + currPassword.word;
			cout << output << endl;

			output = to_string(currPassword.num1) + to_string(currPassword.num2);
			cout << output << endl;
			output = to_string(currPassword.num1) + to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2 + currPassword.cappedWord;
			cout << output << endl;

			output = to_string(currPassword.num2);
			cout << output << endl;
			output = to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2 + currPassword.word;
			cout << output << endl;
			output = to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2 + currPassword.word + to_string(currPassword.num1);
			cout << output << endl;

			output = to_string(currPassword.num2);
			cout << output << endl;
			output = to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2 + currPassword.cappedWord;
			cout << output << endl;
			output = to_string(currPassword.num2) + currPassword.sym1 + currPassword.sym2 + currPassword.cappedWord + to_string(currPassword.num1);
			cout << output << endl;

			output = currPassword.sym1 + currPassword.sym2 + currPassword.word;
			cout << output << endl;
			output = currPassword.sym1 + currPassword.sym2 + currPassword.word + to_string(currPassword.num1);
			cout << output << endl;
			output = currPassword.sym1 + currPassword.sym2 + currPassword.word + to_string(currPassword.num1) + to_string(currPassword.num2);
			cout << output << endl;

			output = currPassword.sym1 + currPassword.sym2 + currPassword.cappedWord;
			cout << output << endl;
			output = currPassword.sym1 + currPassword.sym2 + currPassword.cappedWord + to_string(currPassword.num1);
			cout << output << endl;
			output = currPassword.sym1 + currPassword.sym2 + currPassword.cappedWord + to_string(currPassword.num1) + to_string(currPassword.num2);
			cout << output << endl;

			output = currPassword.sym2 + currPassword.word;
			cout << output << endl;
			output = currPassword.sym2 + currPassword.word + to_string(currPassword.num1);
			cout << output << endl;
			output = currPassword.sym2 + currPassword.word + to_string(currPassword.num1) + to_string(currPassword.num2);
			cout << output << endl;
			
			output = currPassword.sym2 + currPassword.cappedWord;
			cout << output << endl;
			output = currPassword.sym2 + currPassword.cappedWord + to_string(currPassword.num1);
			cout << output << endl;
			output = currPassword.sym2 + currPassword.cappedWord + to_string(currPassword.num1) + to_string(currPassword.num2);
			cout << output << endl;
			
			num1Tracker = (rand()%10);
			num2Tracker = (rand()%10000);
			sym1Tracker = (rand()%10);
			sym2Tracker = (rand()%10);
			
			currPassword.num1 = num1Tracker;
			currPassword.num2 = num2Tracker;
			currPassword.sym1 = syms1[sym1Tracker];
			currPassword.sym2 = syms1[sym2Tracker];
			wholeTracker++;
		}

		wholeTracker = 0;
		wordTracker++;
		if (wordTracker == 2)
		{
			exit(0);
		}

		currPassword.word = words[wordTracker];
		currPassword.cappedWord = capitalizeFirst(words[wordTracker]);
	}
}



























