#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>Dutch_National_algo(vector<int>&arr){
    int low=0;
    int mid=0;
    int high=arr.size()-1;
    while(mid<high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[high],arr[mid]);
            high--;
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {2,0,2,1,1,0};
    vector<int>ans=Dutch_National_algo(arr);
    for(int e:ans){
        cout<<e<<" ";
    }
}