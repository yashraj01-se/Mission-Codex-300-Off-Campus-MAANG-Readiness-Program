#include<iostream>
#include<vector>
using namespace std;
int maxsumsubarraydel(vector<int>&arr){

    //There can be two scenarios ->1.nodelete 2.onedelete
    int nodelete=arr[0];
    int onedelete=INT_MIN;
    int ans=arr[0];

    for(int i=1;i<arr.size();i++){
        int prev=nodelete;
        nodelete=max(nodelete+arr[i],arr[i]); // normal Kadane's algo;

        
        if(onedelete==INT_MIN){ //deletetion scenarios;
            onedelete=prev;
        }
        else{
            onedelete=max(onedelete+arr[i],prev);//onedelete+arr[i] means there is alredy one deleted and we can include upcoming element, prev means incoming is not included
        }

        ans=max(ans,max(nodelete,onedelete));
    }

    return ans;
}
int main(){
    vector<int>arr={1,-2,0,3};
    int ans=maxsumsubarraydel(arr);
    cout<<ans;
}