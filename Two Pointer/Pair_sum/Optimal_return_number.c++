#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> PairSum(vector<int> &array, int target)
{
    sort(array.begin(), array.end()); // If question ask for number that makes the sum we can apply sorting....
    int i = 0;
    int j = array.size() - 1;
    vector<int> ans;
    while (i < j)
    {
        int sum = array[i] + array[j];

        if (sum == target)
        {
            ans.push_back(array[i]);
            ans.push_back(array[j]);
            return ans;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return ans;
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