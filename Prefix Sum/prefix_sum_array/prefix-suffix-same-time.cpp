#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={1,22,3,1,2};
    int n=arr.size();
    vector<int> prefix(n);
    vector<int> suffix(n);

    prefix[0]=arr[0];
    suffix[n-1]=arr[n-1];

    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
        suffix[n-i-1]=suffix[n-i]+arr[n-1-i];
    }

    cout<<"Prefix:\n";
    for(int x:prefix) cout<<x<<" ";

    cout<<"\nSuffix:\n";
    for(int x:suffix) cout<<x<<" ";

}