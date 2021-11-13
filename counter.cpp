#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
	ifstream filetool;
	string filename = argv[1];
	int counter = 0;
        filetool.open(filename);
        if (filetool.is_open())
        {
                string line = "";
                while (getline(filetool, line))
                {
                       counter++;
                }
        }
        else
        {
                cout << "The file didn't open correctly" << endl;
        }

	cout << "counter finished at: " << counter << endl;

        filetool.close();
}
