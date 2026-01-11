#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> PairSum(vector<int> &array, int target)
{

    unordered_map<int, int> mp;
    for (int i = 0; i < array.size(); i++)
    {
        int complement = target - array[i];
        // First Check if complement is present in map or not...
        if (mp.find(complement) != mp.end())
        {
            return {complement, array[i]};
        }
        // Second, store the current element in the map...
        mp[array[i]]++;
    }
    return {};
}

int main()
{

    vector<int> array = {7, 2, 5, 11};
    int target = 9;
    vector<int> ans = PairSum(array, target);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}