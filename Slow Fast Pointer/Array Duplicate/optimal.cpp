#include<iostream>
#include<vector>
using namespace std;
int dup(vector<int>&arr){
    int slow=arr[0];
    int fast=arr[0];
    while(fast<arr.size()){
        slow=arr[slow];
        fast=arr[arr[fast]];
        if(slow==fast){
            slow=arr[0];
            while(slow!=fast){
                slow=arr[slow];
                fast=arr[fast];
            }
            return slow;
        }
    }
    return slow;
}
int main(){
    vector<int>arr={2,1,2,3,4};
    int ans=dup(arr);
    cout<<ans;
}