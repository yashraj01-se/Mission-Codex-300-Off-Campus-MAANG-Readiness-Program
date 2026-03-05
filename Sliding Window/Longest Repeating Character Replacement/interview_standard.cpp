// algo-> for example there are 70 percent BJP and all other parties made up 30 percent , it is much more advantagous to change that make these parties as BJP rather the making BJP like rest of the parties.
#include <iostream>
#include <vector>
using namespace std;

int sol(string &s, int k)
{
    vector<int> arr(26, 0);
    int low = 0;
    int high = 0;
    int ans = 0;
    int maxfreq = 0;
    while (high < s.length())
    {
        arr[s[high] - 'A']++;
        maxfreq = max(maxfreq, arr[s[high] - 'A']);
        while (((high - low + 1) - maxfreq) > k)
        {
            arr[s[low] - 'A']--;
            low++;
        }
        ans = max(ans, high - low + 1);
        high++;
    }
    return ans;
}
int main()
{
    string s = "ABAB";
    int k =2;
    int ans = sol(s, k);
    cout << ans;
}