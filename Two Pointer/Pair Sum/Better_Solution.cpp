#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> Two_sum_Better_Solution(vector<int> &arr, int target)
{

    unordered_map<int, int> mp;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int left = target - arr[i];
        if (mp.find(left) != mp.end())
        {
            return {mp[left], i};
        }
        // store the value and index for future reference...
        mp[arr[i]] = i;
    }
    return {-1, -1};
}

int main()
{
    vector<int> array = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = Two_sum_Better_Solution(array, target);

    cout << "[";
    for (auto it : ans)
    {
        cout << it << ",";
    }
    cout << "]";
}