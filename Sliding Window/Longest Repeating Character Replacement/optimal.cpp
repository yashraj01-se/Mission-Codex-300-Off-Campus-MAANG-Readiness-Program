// algo-> for example there are 70 percent BJP and all other parties made up 30 percent , it is much more advantagous to change that make these parties as BJP rather the making BJP like rest of the parties.
#include<iostream>
#include<vector>
using  namespace std;
int findmax(vector<int>&arr){
    int maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    return maxi;
}
int sol(string &s,int k){
    vector<int>arr(26,0);
    int low=0;
    int high=0;
    int ans=INT_MIN;
    while(high<s.length()){
        arr[s[high]-'A']++;
        int len=high-low+1; //total
        int maxi=findmax(arr); //BJP
        int diff=len-maxi; //INDI BLOCK
        while(diff>k){
            arr[s[low]-'A']--;
            low++;
            maxi=findmax(arr);
            len=high-low+1;
            diff=len-maxi;
        }
        if(diff<k || diff==k){
            ans=max(ans,high-low+1);
        }
        high++;
    }
    return ans;
}
int main(){
    string s="ABAB";
    int k=2;
    int ans=sol(s,k);
    cout<<ans;
}