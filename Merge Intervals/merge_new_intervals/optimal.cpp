#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> merge_interval(vector<vector<int>> &arr)
{
    vector<vector<int>> ans;
    int start1 = arr[0][0];
    int end1 = arr[0][1];

    for (int i = 1; i < arr.size(); i++)
    {
        int start2 = arr[i][0];
        int end2 = arr[i][1];

        if (end1 >= start2)
        {
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
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newinterval = {2, 5};
    vector<vector<int>>res;

    // Insertion:
    bool insert=false;
    for(int i=0;i<intervals.size();i++){
        int start=intervals[i][0];
        if(insert==false && start>=newinterval[0]){
            res.push_back({newinterval[0],newinterval[1]});
            insert=true;
        }
        res.push_back({intervals[i][0],intervals[i][1]});
    }

    if(insert==false){
        res.push_back({newinterval[0],newinterval[1]});
    }

    // overlap Merger:
    vector<vector<int>> ans = merge_interval(res);

    cout << "[";
    for (auto it : ans)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout<<"]";
    }
    cout << "]";
}
