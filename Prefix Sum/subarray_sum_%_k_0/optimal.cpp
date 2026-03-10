#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int countsubModuleok(vector<int>&arr,int k){
   unordered_map<int,int>mp; //storing reminder in map...
   int prefix_sum=0;
   int count=0;
   mp[0]=1;
   for(int i=0;i<arr.size();i++){
        prefix_sum+=arr[i]; //running sum...
        int rem=prefix_sum%k; //condition check
        if(rem<0){ //handling negative number...
            rem+=k;
        }
        count+=mp[rem]; //updating ans...
        mp[rem]++; //updating cuurent map...
   }
   return count;
}
int main(){
    vector<int>arr={4,5,0,-2,-3,1};
    int k=5;
    int ans=countsubModuleok(arr,k);
    cout << ans;
}
