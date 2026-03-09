#include<iostream>
#include<vector>
using namespace std;

vector<int> prefix_sum(vector<int>& arr){
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];

    for(int i=1;i<arr.size();i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

    return prefix;
}

vector<int> suffix_sum(vector<int>& arr){
    int n = arr.size();
    vector<int> suffix(n);

    suffix[n-1] = arr[n-1];

    for(int i=n-2;i>=0;i--){
        suffix[i] = suffix[i+1] + arr[i];
    }

    return suffix;
}

vector<int> prefix_sum_cp(vector<int>& arr){
    int n = arr.size();
    vector<int> prefix(n+1);

    prefix[0] = 0;

    for(int i=1;i<=n;i++){
        prefix[i] = prefix[i-1] + arr[i-1];
    }

    return prefix;
}

vector<int> suffix_sum_cp(vector<int>& arr){
    int n = arr.size();
    vector<int> suffix(n+1);

    suffix[n] = 0;

    for(int i=n-1;i>=0;i--){
        suffix[i] = suffix[i+1] + arr[i];
    }

    return suffix;
}

int main(){

    vector<int> arr = {1,23,3,1,2};

    vector<int> prefix = prefix_sum(arr);
    vector<int> suffix = suffix_sum(arr);
    vector<int> prefix_cp = prefix_sum_cp(arr);
    vector<int> suffix_cp = suffix_sum_cp(arr);

    cout<<"Prefix Sum:"<<endl;
    for(int x:prefix) cout<<x<<" ";
    cout<<endl;

    cout<<"Suffix Sum:"<<endl;
    for(int x:suffix) cout<<x<<" ";
    cout<<endl;

    cout<<"Prefix Sum CP:"<<endl;
    for(int x:prefix_cp) cout<<x<<" ";
    cout<<endl;

    cout<<"Suffix Sum CP:"<<endl;
    for(int x:suffix_cp) cout<<x<<" ";
    cout<<endl;
}
