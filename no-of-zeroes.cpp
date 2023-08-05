#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,count=0;cin>>m>>n;
    for(int i = m ; i <= n ; i++){
            int x = i;
        while(x !=0){
            if(x%10 == 0) count++;
            x = x/10;
        }
    }
    cout<<count;
}
