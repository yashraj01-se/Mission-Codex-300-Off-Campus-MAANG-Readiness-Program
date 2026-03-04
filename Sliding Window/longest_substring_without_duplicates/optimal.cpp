#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int dup(string &s)
{
    int low = 0;
    int high = 0;
    int ans = 0;
    unordered_map<char, int> mp;
    while (high < s.length())
    {
        mp[s[high]]++; // hiring...
        while (mp[s[high]] > 1)
        {                 // duplicate
            mp[s[low]]--; // firing...
            if (mp[s[low]] == 0)
            { // no occurence..remove...
                mp.erase(s[low]);
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
    string s = "pwwkew";
    int ans = dup(s);
    cout << ans;
}