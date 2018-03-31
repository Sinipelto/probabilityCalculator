#include <thread>
#include <chrono>
#include <random>
#include <iostream>

using namespace std;

static bool debugMode;

bool probability(unsigned const n) {
    // Generates true or false in specified probability 1/n where n is given input.

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
        cout << time.count() << " ms, " << i << " == " << x << endl;
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
        cout << "q(uit), loop, prob, debug" << endl;
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

            for (int i = 0; i < n; ++i) {
                cout << probability(unsigned(p)) << endl;
            }
        }

        else if (cmd == "prob") {

            cout << "prob> ";
            getline(cin, t);
            int p = stoi(t);

            if (p < 0) {
                continue;
            }

            cout << probability(unsigned(p)) << endl;
        }

        else if (cmd == "debug") {
            debugMode = !debugMode; // Invert debug mode
            if (debugMode) {
                cout << "Debug mode ON!\n" << endl;
            }
            else {cout << "Debug mode OFF\n" << endl;}
        }

        else if (cmd == "q") {
            return 0;
        }

        else {
            cout << "unknown" << endl;
        }
    }
}
