#include<bits/stdc++.h>
using namespace std;
void different_k(vector<int>&v, int k){
    int n = v.size();
    for(int i = 0 ; i <n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(v[j] - v[i]  == k){
                cout<<v[i]<<"  "<<v[j]<<endl;
            }
        }
    }

}

int main(){
    vector<int>v{1,3,4,5,7,8,9,12};
    int k = 3;
    different_k(v,k);

}
