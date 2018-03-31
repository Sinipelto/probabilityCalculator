#include <thread>
#include <chrono>
#include <random>
#include <iostream>

using namespace std;

static bool debugMode; // Bool flag for debug prints

bool probability(unsigned const n) {
    // Generates true or false in specified probability 1/n where n is given input.
    // Currently uses mersenne twister with current time as seed for randomness.

    std::mt19937 gen(unsigned(time(0))); // Init generator here

    std::uniform_int_distribution<unsigned> timerange(1001, 1101); // Range secured for about 1 sec
    std::uniform_int_distribution<unsigned> number(1, n); // Range for vector index

    // Sleep for a randomized time (1050-1500) to get new seed value for random gen
    auto time = std::chrono::milliseconds(timerange(gen)); // Init random time in chrono milliseconds

    std::this_thread::sleep_for(time); // Sleep to change seed

    // Generate two random numbers in range with time delay between
    unsigned i = number(gen); // Generate a random number from 1 to n

    //std::this_thread::sleep_for(time); // Sleep again for different seed (optional)
    unsigned x = number(gen); // Generate another number

    if (debugMode) {
        cout << "delay: " << time.count() << "ms, " << "comparison: " << i << " == " << x << endl;
    }

    // Natural integer comparison between these two values
    return i == x;
}

int main()
{
    debugMode = false;
    string cmd("");
    string t("");

    while (true) {
        cout << "cmds: q(uit), loop, prob, debug, clear, help" << endl;
        cout << "command> ";

        getline(cin, cmd);

        if (cmd == "loop") {

            cout << "times> ";
            getline(cin, t);
            int n = std::stoi(t);

            cout << "prob> ";
            getline(cin, t);
            int p = stoi(t);

            if (n < 0 or p < 0) {
                continue;
            }

            unsigned a = 0, b = 0;

            for (int i = 0; i < n; ++i) {
                if (probability(unsigned(p))) {
                    a += 1;
                    cout << "TRUE" << endl;
                }
                else {
                    b += 1;
                    cout << "FALSE" << endl;
                }
            }
            cout << endl;
            cout << "TRUE: " << a << endl;
            cout << "FALSE: " << b << endl;

            cout << endl;
        }

        else if (cmd == "prob") {

            cout << "prob> ";
            getline(cin, t);
            int p = stoi(t);

            if (p < 0) {
                continue;
            }

            if (probability(unsigned(p))) {
                cout << "TRUE" << endl;
            }
            else {
                cout << "FALSE" << endl;
            }

            cout << endl;
        }

        else if (cmd == "debug") {

            debugMode = !debugMode; // Invert debug mode

            cout << "Debug mode ";
            if (debugMode) {
                cout << "ON";
            }
            else {cout << "OFF";}
            cout << "!\n" << endl;
        }

        else if (cmd == "q") {
            cout << "goodbye!\n" << endl;
            return 0;
        }

        else if (cmd == "clear") {
            for (unsigned i = 0; i < 80; ++i) {
                cout << endl;
            }
        }

        else if (cmd == "help") {

            cout << "q: Quits the program" << endl;
            cout << "loop: Generates n times with probability p."
                    " Both n and p are from user input." << endl;
            cout << "prob: Generates value from given probability p." << endl;
            cout << "debug: Changes debug mode on or off. Default: OFF" << endl;
            cout << "clear: Clears the screen." << endl;
            cout << "help: Displays this help text." << endl;
            cout << endl;
        }

        else {
            cout << "unknown command" << endl;
            cout << endl;
        }
    }
}
