#include <iostream>
#include <vector>
using namespace std;

int duplicates_Optimal_Solution(vector<int> &array)
{
    int n = array.size();
    int j = 0; // Slow Poniter // overwrites the element...

    for(int i=1;i<n;i++){ // Scans Everything... 
        if(array[i]!=array[j]){
            j++;
            array[j]=array[i]; // Overwrite Duplicates...
        }
    }
    return j+1;
}

int main()
{
    vector<int> array = {1, 1, 2, 3, 4};
    int ans = duplicates_Optimal_Solution(array);

    cout << "[";
    cout<<ans;
    cout << "]";

    cout<<endl;
    cout<<"[";
    for(int i=0;i<ans;i++){
        cout<<array[i]<<",";
    }cout<<"]"<<endl;
}