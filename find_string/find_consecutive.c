// Find substring with highest consecutive repetition

char* find_top_consecutive_repeat(char* input_string)
{
    // TODO: validate input
}

int main()
{
    char input[] = "abcddddefefefefef",
     *actual = find_top_consecutive_repeat(input),
           expected = "dddd";

    // Assert
    cout << actual << "\n";
    cout << ((actual == expected) ? "." : "E");
    cout << "\n\n";
}