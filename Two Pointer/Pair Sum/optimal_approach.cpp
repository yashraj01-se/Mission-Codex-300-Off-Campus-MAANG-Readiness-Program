#include <iostream>
#include <vector>
using namespace std;

vector<int> Two_sum_optimal_approach(vector<int> &array, int target)
{

    // Two Pointers:
    int n = array.size();
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int sum = array[left] + array[right];

        // Condition 1:
        if (sum == target)
        {
            return {left, right};
        }

        // Condition 2:
        else if (sum < target)
        {
            left++; // Increase sum
        }

        // Condition 3:
        else
        {
            right--; // Decrease sum
        }
    }

    return {-1, -1};
}

int main()
{
    vector<int> array = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = Two_sum_optimal_approach(array, target);

    cout << "[";
    for (auto it : ans)
    {
        cout << it << ",";
    }
    cout << "]";
}