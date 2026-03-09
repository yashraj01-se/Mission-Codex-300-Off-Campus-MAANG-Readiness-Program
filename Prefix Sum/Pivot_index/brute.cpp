#include <iostream>
#include <vector>
using namespace std;

int pivot_index(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prefix(n);
    vector<int> suffix(n);

    prefix[0] = arr[0];
    suffix[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    for (int i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] + arr[i];

    for (int i = 0; i < n; i++)
    {
        int leftsum;
        int rightsum;

        if (i == 0)
            leftsum = 0;
        else
            leftsum = prefix[i - 1];

        if (i == n - 1)
            rightsum = 0;
        else
            rightsum = suffix[i + 1];

        if (leftsum == rightsum)
            return i;
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 7, 3, 6, 5, 6};
    cout << pivot_index(arr);
}