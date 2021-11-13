#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
        ifstream filetool;
        string input = argv[1];
	float parameter = stof(argv[2]);
        int counter = 1;
	float placeholder = -1.000;
        filetool.open("wordAssets.txt");
        if (filetool.is_open())
        {
                string line = "";
                while (getline(filetool, line))
                {
                        if (line == input)
                        {
                                cout << "found at line " << counter << endl;
				placeholder = counter;
				break;
                        }

                        counter++;
                }
        }
        else
        {
                cout << "The file didn't open correctly" << endl;
        }
        filetool.close();


	if (placeholder == -1)
	{
       		cout << "not found" << endl;
		exit(0);
	}

	else
	{
		float seconds = 0;
		float minutes = 0;
		float hours = 0;
		float days = 0;
		float weeks = 0;
		
		seconds = (placeholder * parameter);
		minutes = (seconds/60);
		hours = (minutes/60);
		days = (hours/24);
		weeks = (days/7);

		if (weeks >= 1)
		{
			cout << fixed << setprecision(3) << "Rough estimate of weeks until completion: " << weeks << endl;
		}

		else if (days >= 1)
		{
			cout << fixed << setprecision(3) << "Rough estimate of days until completion: " << days << endl;
		}

		else if (hours >= 1)
		{
			cout << fixed << setprecision(3) << "Rough estimate of hours until completion: " << hours << endl;
		}

		else if (minutes >= 1)
		{
			cout << fixed << setprecision(3) << "Rough estimate of minutes until completion: " << minutes << endl;
		}

		else 
		{
			cout << fixed << setprecision(3) << "Rough estimate of seconds until completion: " << seconds << endl;
		}
	}
}
