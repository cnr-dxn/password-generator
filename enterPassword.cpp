#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

int main(int argc, char const *argv[])
{
        int continuer = 1;
        string key = argv[1];
        string input;
        unsigned long long counter = 0;

        while (continuer == 1)
        {
                cin >> input;

                if (input == key)
                {
                        counter++;
                        cout << "Cracked '" << input << "' in " << counter << " guesses." << endl;
                        exit(0);
                }

                else
                {
                        counter++;
                }
        }
}
