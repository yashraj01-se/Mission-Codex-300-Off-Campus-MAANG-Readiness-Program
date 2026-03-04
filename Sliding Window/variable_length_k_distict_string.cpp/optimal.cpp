#include <iostream>
#include <unordered_map>
using namespace std;
int long_sub(string &s, int k)
{
    unordered_map<char, int> mp;
    int low = 0;
    int high = 0;
    int ans = 0;
    while (high < s.length())
    {

        mp[s[high]]++; //hiring
        while (mp.size() > k)
        {
            mp[s[low]]--; // firing....
            if (mp[s[low]] == 0)
            {
                mp.erase(s[low]);
            }
            low++;
        }
        if (mp.size() == k)
        { /// condition meeting...
            ans = max(ans, high - low + 1);
        }
        high++;
    }
    return ans;
}
int main()
{
    string s = "aabacbebebe";
    int k = 3;
    int ans = long_sub(s, k);
    cout << ans;
}