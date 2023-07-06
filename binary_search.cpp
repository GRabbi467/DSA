#include<bits/stdc++.h>
using namespace std;

int bsearch(vector<int>&v,int x){
    int l,r,m;
    l = 0;
    r = v.size() - 1;

    while(l <= r){
        m = (l+r) / 2;

        if( v[m] == x) return m;

        if( v[m] >  x) l = m - 1;
        else r = m + 1 ;

        return -1;
    }

}


int main(){
    vector<int>v{1,2,3,4,5,6,7,8,0};
    int res = bsearch(v,8);
    cout<<res;

}
