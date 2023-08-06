#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v{12,34,56,23,54,11,6,8,9,100};
    srand(time(nullptr));

    for(int i = 0 ; i < 10 ; i++){
      int rannum = rand() % 10 ;
     swap(v[rannum] , v[i]);
    }
    for(auto &x : v) cout<<x<<endl;
}
