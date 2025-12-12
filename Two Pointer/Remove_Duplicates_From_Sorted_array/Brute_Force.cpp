#include<iostream>
#include<vector>
using namespace std;

vector<int>duplicates_Brute_Force(vector<int>&arr){

    vector<int>ans;
    int n=arr.size();

   ans.push_back(arr[0]);

    for(int i=1;i<n;i++){
        if(arr[i]!=ans.back()){
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

int main(){
    vector<int>array={1,1,2,3,4};
    vector<int>ans=duplicates_Brute_Force(array);

    cout << "[";
    for (auto it : ans)
    {
        cout << it << ",";
    }
    cout << "]";
}