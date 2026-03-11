#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int contiarr(vector<int>&arr){
    unordered_map<int,int>mp;
    mp[0]=-1;
    int maxlen=INT_MIN;
    int diff=0;
    
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1)diff++; // 1 if num[i]==1 else -1 for 0
        else diff--;

        if(mp.count(diff)){
            maxlen=max(maxlen,i-mp[diff]);
        }
        else{
            mp[diff]=i;
        }
    }
    return maxlen;
}
int main(){
    vector<int>arr={0,1,1,1,1,1,0,0,0};
    int len=contiarr(arr);
    cout<<len;
}