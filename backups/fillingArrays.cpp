#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>

#define LENGTH_OF_WORD_VECTOR 20063

using namespace std;

struct password
{
	string word;
	int num1;
	int num2;
	string sym1;
	string sym2;
};

string capitalizeFirst(string word)
{
        word[0] = toupper(word[0]);
        return word;
}

int main(int argc, char const *argv[])
{
	ifstream fileToolCommon;
	ifstream fileToolWords;
	ifstream fileToolSyms;
	ifstream fileToolOtherSyms;

	vector<string> words;
	vector<string> syms1;
	vector<string> syms2;

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
			cout << words[counter] << endl;
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

	
        fileToolOtherSyms.open("symbolAssets2.txt");
        if (fileToolOtherSyms.is_open())
        {
                string line = "";
                while (getline(fileToolOtherSyms, line))
                {
			syms2.push_back(line);
                }
        }

        else
        {
                cout << "The file didn't open correctly" << endl;
        }

        fileToolOtherSyms.close();

	cout << "words.size(): " << words.size() << endl;
	cout << "syms1.size(): " << syms1.size() << endl;
	cout << "syms2.size(): " << syms2.size() << endl;
}



























