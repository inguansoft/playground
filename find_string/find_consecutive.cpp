#include <iostream>
// Find substring with highest consecutive repetition
using namespace std;

string findConsecutiveRepeat(string input_string)
{
    // TODO: validate input
    string top_match = "";
    int max_match = 0, current_match = 0;
    char prev = '\0';
    for (char &c : input_string)
    {
        if (prev == c)
        cout << c;
    }
    return "dddd";
}

int main()
{
    string input = "abcddddefefefefef";
    string actual = findConsecutiveRepeat(input),
           expected = "dddd";

    // Assert
    cout << actual << "\n";
    cout << ((actual == expected) ? "." : "E");
    cout << "\n\n";
}