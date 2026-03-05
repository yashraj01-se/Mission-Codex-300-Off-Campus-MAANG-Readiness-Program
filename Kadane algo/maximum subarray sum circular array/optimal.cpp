#include <iostream>
#include <vector>
using namespace std;
int t(vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum;
}
int cirarraysum(vector<int> &arr)
{
    int currmaxsum = arr[0];
    int maxsum = arr[0];
    int currminsum = arr[0];
    int minsum = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        currmaxsum = max(currmaxsum + arr[i], arr[i]);
        maxsum = max(currmaxsum, maxsum);
        currminsum = min(currminsum + arr[i], arr[i]);
        minsum = min(currminsum,minsum);
    }
    int total = t(arr);
    if (maxsum < 0)
    {
        return maxsum;
    }
    return max(maxsum, total - minsum);
}
int main()
{
    vector<int> arr = {5, -1, -2, -3, 4};
    int ans = cirarraysum(arr);
    cout << ans;
}