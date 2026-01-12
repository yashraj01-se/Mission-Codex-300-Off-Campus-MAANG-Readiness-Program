#include<iostream>
#include<vector>
using namespace std;

vector<int>Remove_Dup(vector<int>&arr){
    int i=0; //officer
    int j=1; //CM

    int n=arr.size();

    while(j<n){
        if(arr[i]==arr[j]){
            j++; // CM moves ahead
        }
        else{
            arr[i+1]=arr[j]; // officer updates next position
            i++;
            j++;
        }
    }
    arr.resize(i+1);
    return arr;
}

int main(){
    vector<int>arr={1,1,1,1,2,2,2,3,3,3,4,4};
    vector<int>ans=Remove_Dup(arr);
    for(auto i:ans){
        cout<<i<<" ";
    }
}