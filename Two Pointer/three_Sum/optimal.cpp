#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> three_sum(vector<int>&arr){
    vector<vector<int>> res;
    sort(arr.begin(),arr.end());
    int n=arr.size();
    for(int i=0;i<n-2;i++){ // 1.For Each i we run a Two sum... minimum 2 left after i
        int j=i+1;
        int k=n-1;

        if(i>0 && arr[i]==arr[i-1])continue; //2.taking care of duplicates...

        while(j<k){
            if(arr[i]+arr[j]+arr[k]==0){
                res.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1])j++; //3.taking care of duplicates...
                while(j<k && arr[k]==arr[k+1])k--; //4.taking care of duplicates...
            }
            else if(arr[i]+arr[j]+arr[k]>0){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return res;
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
    
    vector<vector<int>> ans=three_sum(arr);;
    for(auto v:ans){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}