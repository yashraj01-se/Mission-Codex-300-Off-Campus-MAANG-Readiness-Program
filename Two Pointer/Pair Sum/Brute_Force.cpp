#include <iostream>
#include <vector>
using namespace std;

vector<int> Two_sum_Brute_Force(vector<int> &array, int target)
{
    int n = array.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] + array[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    vector<int> array = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = Two_sum_Brute_Force(array, target);

    cout << "[";
    for (auto it : ans)
    {
        cout << it << ",";
    }
    cout << "]";
}