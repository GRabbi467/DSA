#include<iostream>
#include<vector>
using namespace std;

int linear_search(vector<int>&v,int x){
    size_t i;
    for(i = 0 ; i < v.size(); i++){
        if(v[i] == x)
         return i;
    }
    i =-1;
    return i;
}

int main(){
    vector<int>v{1,2,3,4,5,6};
    int pos = linear_search(v,7);
    cout<<pos;
}
