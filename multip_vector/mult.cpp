//{ Driver Code Starts
#include <iostream>

using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> getTable(int n)
    {
        vector<int> vect;
        if (n > 0 && n < 1000000)
        {

            for (int i = 1; i < 11; i++)
            {
                vect.push_back(n * i);
            }
        }
        else
        {
            cout << "Invalid input, try program using input > 0 and < 10^6";
        }
        return vect;
    }
};

//{ Driver Code Starts.
int main()
{

    int N;
    cin >> N;
    Solution ob;
    vector<int> ans = ob.getTable(N);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
// } Driver Code Ends