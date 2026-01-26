#include <iostream>
#include <vector>
using namespace std;
int subarray(vector<int> &arr, int k)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum = sum + arr[i];
    }
    int maxsum = sum;

    for (int i = k; i < n; i++)
    {
        sum = sum + arr[i] - arr[i - k];
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}
int main()
{
    vector<int> arr = {100, 200, 300, 400};
    int k = 2;
    int ans = subarray(arr, k);
    cout << ans;
}