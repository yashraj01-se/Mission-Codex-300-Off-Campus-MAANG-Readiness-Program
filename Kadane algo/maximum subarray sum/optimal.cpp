#include <iostream>
#include <vector>
using namespace std;
int maxsumsubarray(vector<int> &arr)
{
    int ans = arr[0];
    int bestending = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        int v1 = bestending + arr[i]; // first option
        int v2 = arr[i];              // Second option
        bestending = max(v1, v2);
        ans = max(ans, bestending);
    }
    return ans;
}
int main()
{
    vector<int> arr = {-2, 1, 2, -4, 5};
    int ans = maxsumsubarray(arr);
    cout << ans;
}