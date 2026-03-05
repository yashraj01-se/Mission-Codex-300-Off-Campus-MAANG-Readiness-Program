#include <iostream>
#include <vector>
using namespace std;
int maxprodsubarray(vector<int> &arr)
{
    int maxending = arr[0];
    int minending = arr[0];
    int ans = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        int v1 = arr[i]; //first option 
        int v2 = maxending * arr[i]; //second option 
        int v3 = minending * arr[i]; //third option
        maxending = max(v1, max(v2, v3));
        minending = min(v1, min(v2, v3));
        ans = max(ans, max(maxending, minending));
    }

    return ans;
}
int main()
{
    vector<int> arr = {-2, 3, -4};
    int ans = maxprodsubarray(arr);
    cout << ans;
}