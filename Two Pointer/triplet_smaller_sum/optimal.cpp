#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int three_sum_less_than(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int count=0;
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < target)
            {
                count+=k-j; //key idea...
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> arr = {5, 1, 3, 4, 7};
    int target = 12;
    int ans = three_sum_less_than(arr, target);
    cout << ans;
}