#include<bits/stdc++.h>
using namespace std;
int pivot_idx(vector<int>&v){
    int count = 0;
    for(int i = 0 ; i < v.size() ; i++){
        count += v[i];
    }
    int left =0,right = count;
    for(int i = 0  ;i < v.size() ; i++){
        left += v[i];
        if(left == right) return i;
        right -=v[i];
    }
    return 0;
}

int main(){
    vector<int>v{1,6,2,7,8,15,1};
    cout<<pivot_idx(v);

}
