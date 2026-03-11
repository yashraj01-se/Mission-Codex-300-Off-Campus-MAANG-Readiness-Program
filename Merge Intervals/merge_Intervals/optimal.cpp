#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<vector<int>> merge_interval(vector<vector<int>> &arr)
{
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    int start1 = arr[0][0];
    int end1 = arr[0][1];

    for (int i = 1; i < arr.size(); i++)
    {
        int start2 = arr[i][0];
        int end2 = arr[i][1];

        if (end1 >= start2)
        { // Mergeing condition
            start1 = start1;
            end1 = max(end1, end2);
            continue;
        }
        ans.push_back({start1, end1});
        start1 = start2;
        end1 = end2;
    }
    ans.push_back({start1, end1});
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = merge_interval(arr);

    cout<<"[";
    for (auto i : ans)
    {
        cout << "[";
        for (auto it : i)
        {
            cout << it << " ";
        }
        cout<< "]";
    }
    cout<<"]";
}