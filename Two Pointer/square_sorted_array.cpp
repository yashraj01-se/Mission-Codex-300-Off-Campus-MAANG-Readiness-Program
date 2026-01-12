#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> square_sorted_array(vector<int> &arr)
{
   int n=arr.size();
   vector<int>ans(n);
   int left=0;
   int right=n-1;
   int k=n-1;
   while(left<=right){
    if(abs(arr[left])>abs(arr[right])){
        ans[k]=arr[left]*arr[left];
        left++;
    }
    else{
        ans[k]=arr[right]*arr[right];
        right--;
    }
    k--;
   }
   return ans;
}
int main()
{
    vector<int> arr = {-4, -1, 0, 3, 10};
    int n = arr.size();
    vector<int> ans = square_sorted_array(arr);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}