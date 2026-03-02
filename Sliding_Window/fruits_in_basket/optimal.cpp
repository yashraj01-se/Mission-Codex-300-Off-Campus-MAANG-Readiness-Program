#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int fruits(vector<int> &arr)
{
    unordered_map<int, int> mp;
    int low = 0;
    int high = 0;
    int ans = 0;
    while (high < arr.size())
    {
        mp[arr[high]]++; // hiring
        while (mp.size() > 2)
        {
            mp[arr[low]]--; // firing
            if (mp[arr[low]] == 0)
            {
                mp.erase(arr[low]); // to remove the element from the map, as we want the size of the map as a condition...
            }
            low++;
        }
        ans = max(ans, high - low + 1);
        high++;
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 1};
    int ans = fruits(arr);
    cout << ans;
}