#include "probability.hh"
#include <iostream>

using namespace std;

int main()
{
    bool debugMode = false;
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
                if (probability(unsigned(p), debugMode)) {
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

            if (probability(unsigned(p), debugMode)) {
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
