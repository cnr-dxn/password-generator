#include <string>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

struct Timer
{
        //declares the start and end variables for clock, as well as variable to store the change in time
        time_point<high_resolution_clock> start;
        time_point<high_resolution_clock> end;
        duration<float> timed;
        //function to start timer
        void startTimer()
        {
                start = high_resolution_clock::now();
        }
        //function to end timer and return change in time
        float endTimer()
        {
                end = high_resolution_clock::now();
                timed = end - start;
                return (timed.count()*1000);
        }
};
