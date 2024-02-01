#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    unsigned int x = 0x80000000,
                 main = 0xa0bb1234, fragment = 0x95;
    // Objective insert in the 0x000XX000
    for (int i = 0; i < 32; i++)
    {
        cout << bitset<32>(x >> i) << endl;
    }

    x = 0x00000002;

    for (int i = 0; i < 32; i++)
    {
        cout << bitset<32>(x << i) << endl;
    }

    printf("%08x --masked--> %08x\n", main,
           (main | 0x00FF0000) & ((fragment << 16) | 0xFF00FFFF));
    return 0;
}