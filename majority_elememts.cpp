#include<bits/stdc++.h>
using namespace std;

void majority(vector<int>v,int n){
    vector<int>v2(n,0);
    for(int i = 0 ; i < n; i++){
        v2[v[i]]++;
    }
    for(int j = 0 ; j < v2.size() ;j++){
        if(v2[j]){
            cout<<j<<"--->"<<v2[j]<<endl;
        }
    }
}

int main(){
    vector<int>v{2,2,1,2,1,4,2,1,1,2};
    int n = v.size();
    majority(v,n);
}
