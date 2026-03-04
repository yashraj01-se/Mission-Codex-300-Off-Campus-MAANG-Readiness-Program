#include <iostream>
#include <unordered_map>
using namespace std;
string mini(string &s, string &t)
{
    unordered_map<char, int> mp;

    for (char c : t)
    { // Populating map with t's character.
        mp[c]++;
    }

    int low = 0;
    int high = 0;
    int count = t.length();
    int start = 0;
    int minlen = INT_MAX;

    while (high < s.length())
    {
        if (mp[s[high]] > 0)
        {
            count--;
        }
        mp[s[high]]--;

        while (count == 0)
        {
            if ((high - low + 1) < minlen)
            {
                minlen = high - low + 1;
                start = low;
            }
            mp[s[low]]++;
            if (mp[s[low]] > 0)
            {
                count++;
            }
            low++;
        }
        high++;
    }
    if (minlen == INT_MAX)
        return "";
    else
        return s.substr(start, minlen);
}
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ans = mini(s, t);
    for (char c : ans)
    {
        cout << c << "";
    }
}