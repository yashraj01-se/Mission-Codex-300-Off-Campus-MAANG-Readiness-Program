#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_two_vectors(const vector<int> &arr1, const vector<int> &arr2)
{
    int i = 0; // pointer for arr1
    int j = 0; // pointer for arr2
    vector<int> merged;

    int n = arr1.size();
    int m = arr2.size();

    while (i < n && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            merged.push_back(arr2[j]);
            j++;
        }
        else
        {
            merged.push_back(arr1[i]);
            i++;
        }
    }

    if (i < n)
    {
        while (i < n)
        {
            merged.push_back(arr1[i]);
            i++;
        }
    }

    if (j < m)
    {
        while (j < m)
        {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    return merged;
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8, 9, 10};
    vector<int> merged = merge_two_vectors(arr1, arr2);
    for (auto i : merged)
    {
        cout << i << " ";
    }
}