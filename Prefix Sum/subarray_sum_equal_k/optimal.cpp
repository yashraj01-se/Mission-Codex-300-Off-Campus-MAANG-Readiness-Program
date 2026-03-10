#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int countsub(vector<int>&arr,int k){
    unordered_map<int,int>mp;
    mp[0]=1; //INITIALIZE ZERO SUM...
    int count=0;
    int prefix_sum=0;
    for (int i=0;i<arr.size();i++){
        prefix_sum+=arr[i]; //(Running Sum...)
        int rem=prefix_sum-k; //(Prefix_sum to search in hash map...)condition check
        count+=mp[rem]; //How many times this prefix_sum appeared... update count... condition check...
        mp[prefix_sum]++; // update current prefix sum record...
    }
    return count;
}
int main(){
    vector<int>arr={1,1,1};
    int k=2;
    int ans=countsub(arr,k);
    cout << ans;
}
