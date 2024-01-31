#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int x = 4;
    int y = -8;

    cout << x << " bin: " << bitset<32>(x) << endl;
    cout << y << " bin: " << bitset<32>(y) << endl;

    if (((x ^ y) < 0))
    {
        cout << x << " , " << y << " opposite" << endl;
    }
    else
    {
        cout << x << " , " << y << " same" << endl;
    }

    return 0;
}