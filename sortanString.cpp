#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string>v{"bat","cat","apple","duck"};
    sort(v.begin(),v.end());
    for(auto x : v){
        cout<<x<<endl;
    }
}
