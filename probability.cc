#include "probability.hh"

bool probability(unsigned const n, bool const debugMode) {
    // Generates true or false in specified probability 1/n where n is given input.
    // Currently uses mersenne twister with current time as seed for randomness.

    std::mt19937 gen(unsigned(time(0))); // Init generator here

    std::uniform_int_distribution<unsigned> timerange(1001, 1101); // Range secured for about 1 sec
    std::uniform_int_distribution<unsigned> number(1, n); // Range for vector index

    // Init random time in chrono milliseconds
    std::chrono::milliseconds time = std::chrono::milliseconds(timerange(gen));

    // Sleep for a randomized time (1050-1500) to get new seed value for random gen
    std::this_thread::sleep_for(time);

    // Generate two random numbers in range with time delay between
    unsigned i = number(gen); // Generate a random number from 1 to n

    //std::this_thread::sleep_for(time); // Sleep again for different seed (optional)
    unsigned x = number(gen); // Generate another number

    if (debugMode) {
        std::cout << "delay: " << time.count() << "ms, " << "comparison: " << i << " == " << x << std::endl;
    }

    // Natural integer comparison between these two values
    return i == x;
}
