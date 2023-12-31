#include <iostream>
#include<list>

using namespace std;

class InputHandler
{
private:
    int the_number;

public:
    int getNumber()
    {
        return the_number;
    }

    void setNumber(int number)
    {
        the_number = number;
    }

    bool isValid()
    {
        return the_number > 0;
    }

    void printConstraints()
    {
        cout << "Input needs to be an integer bigger than 0 !!!\n";
    }

    InputHandler()
    {
        the_number = 0;
    }

    InputHandler(int input_number)
    {
        the_number = input_number;
    }
};

class MathHelper
{
    InputHandler &input_handler;
    list<int> prime_numbers;

public:
    /**
     * Calculate prime numbers and load them into prime_numbers intenal variable
     */
    void calcPrime()
    {
        int j, i = input_handler.getNumber();
        prime_numbers.clear();

        while (i > 1)
        {
            for (j = i - 1; j > 1; j--)
            {
                if (i % j == 0)
                {
                    break;
                }
            }
            if (j == 1)
            {
                prime_numbers.push_front(i);
            }
            i--;
        }
    }

    void printCurrentPrimeList(){
        cout << " [";
        for(int number: prime_numbers) {
            cout << " " << number;
        }
        cout << " ]";
    }

    MathHelper(InputHandler &input_handler_parameter) : input_handler(input_handler_parameter)
    {
    }
};

/**
 * Calculate the prime numbers from 1 to n
 */
int main(void)
{
    int n = 1;
    InputHandler input_handler(n);
    // InputHandler input_handler = InputHandler(n);
    MathHelper math_helper(input_handler);
    // MathHelper math_helper = MathHelper(input_handler);
    while (n != 0)
    {
        cout << "Prime numbers from 2 to N (0 to exit) N=";
        cin >> n;
        input_handler.setNumber(n);
        if (input_handler.isValid())
        {
            math_helper.calcPrime();
            math_helper.printCurrentPrimeList();
            cout<<"\n";
        }
        else
        {
            if (n != 0)
            {
                input_handler.printConstraints();
            }
        }
    }
    cout << "N = 0 = Exit, Thanks for visiting!\n\n";
    exit(0);
}