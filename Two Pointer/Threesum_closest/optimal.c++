#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int three_sum_closest(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int max_diff = INT_MAX;
    int resum = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            int diff = abs(sum - target);
            if (diff < max_diff)
            {
                max_diff = diff;
                resum = sum;
            }
            if (sum == target)
            {
                return sum;
            }
            else if (sum > target)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return resum;
}

int main()
{
    vector<int> arr = {-1, 2, 1, -4};
    int target = 1;
    int ans = three_sum_closest(arr, target);
    cout << ans;
}