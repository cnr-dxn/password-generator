#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
	ifstream filetool;
	string input = argv[1];
	int counter = 1;
        filetool.open("commonWords.txt");
        if (filetool.is_open())
        {
                string line = "";
                while (getline(filetool, line))
                {
			if (line == input)
			{
				cout << "found at line " << counter << endl;
				exit(0);
			}

			counter++;
                }
        }
        else
        {
                cout << "The file didn't open correctly" << endl;
        }

	cout << "not found" << endl;

        filetool.close();
}
