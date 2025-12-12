#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> duplicates_Better_Solution(vector<int> &arr)
{
    set<int> s(arr.begin(), arr.end());
    vector<int> ans;
    for (auto it : s)
    {
        ans.push_back(it);
    }
    return ans;
}

int main()
{
    vector<int> array = {1, 1, 2, 3, 4};
    vector<int> ans = duplicates_Better_Solution(array);

    cout << "[";
    for (auto it : ans)
    {
        cout << it << ",";
    }
    cout << "]";
}