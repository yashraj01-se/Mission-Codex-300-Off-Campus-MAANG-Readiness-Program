#include <iostream>
#include <vector>
using namespace std;
int abssum(vector<int> &arr)
{
    int maxsum = arr[0];
    int minsum = arr[0];
    int ans = abs(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        maxsum = max(maxsum + arr[i], arr[i]);
        minsum = min(minsum + arr[i], arr[i]);

        ans = max(ans, max(abs(maxsum), abs(minsum)));
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, -3, 2, 3, -4};
    int ans = abssum(arr);
    cout << ans;
}