#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    unsigned int x = 0x80000000;

    for (int i = 0; i < 32; i++)
    {
        cout << bitset<32>(x >> i) << endl;
    }

    x = 0x00000002;

    for (int i = 0; i < 32; i++)
    {
        cout << bitset<32>(x << i) << endl;
    }
    return 0;
}