#include <iostream>
#include <vector>
using namespace std;
int min_win(vector<int> &arr, int target)
{
    int low = 0;
    int n = arr.size();
    int high = 0;
    int currsum = 0;
    int min_window = INT_MAX;

    while (high < n)
    {
        currsum += arr[high]; // Hiring.....
        high++;
        while (currsum >= target)
        { // Firing till condition satisfy..
            int win = high - low;
            min_window = min(min_window, win);
            currsum -= arr[low];
            low++;
        }
    }
    return (min_window == INT_MAX) ? 0 : min_window;
}
int main()
{
    vector<int> arr = {1, 2, 4, 4};
    int target = 4;
    int ans = min_win(arr, target);
    cout << ans;
}