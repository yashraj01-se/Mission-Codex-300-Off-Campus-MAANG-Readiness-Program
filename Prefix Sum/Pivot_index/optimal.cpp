#include <iostream>
#include <vector>
using namespace std;
int pivot_index(vector<int>&arr){
    int total=0;
    for(int c:arr){
        total+=c;
    }
    //Instead of Maintaining whole array we just update the latest sum variable
    int leftsum=0;
    for(int i=0;i<arr.size();i++){
        int rightsum=total-leftsum-arr[i]; // For every index we calculate right sum
        if(leftsum==rightsum){ 
            return i;
        }
        leftsum+=arr[i];
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 7, 3, 6, 5, 6};
    cout << pivot_index(arr);
}