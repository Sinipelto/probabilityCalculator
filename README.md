# probabilityCalculator
Calculates true or false (meaning event happens or not happens) with given probability of 1/n where n is user input.

Function probability(unsigned const n):
  Input n is the factor of the probability to use with a simple formula 1/n. For example, if n = 100, function will calculate
  true or false with probability 1/100 (which means a probability of 0.01 (1%). Any value that is >= 0 and <= INT_MAX may be used.
  
  Function generates 2 random unsigned integers between 1 and n and compares them with each other. If they do match, then the event
  does happen (it's true, returns true), otherwise it doesn't (it's false, returns false).
  
In the main function is a user interface to use this function more easily. The UI is also very easy to expand with more
commands if necessary.
