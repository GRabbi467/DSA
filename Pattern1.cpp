#include<bits/stdc++.h>
using namespace std;
void pattern1(int x){
    for (int i = 0 ; i < x ; i++ ){
        for(int j = 0 ; j <= i ; j++){
            cout<<"*";
        }
    cout<<"\n";
    }
}

void pattern8(int x){
    for(int i = x ; i >0 ; i--){
        for(int j = 0 ; j < x-i; j++){
            cout<<" ";
        }
        for(int k = 0 ; k < 2*i-1; k++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern9(int n){
    for(int i {0} ; i < n ; i++){
        for(size_t j {0} ; j < n-i-1 ; j++){
            cout<<" ";
        }
        for(int k = 0 ; k < 2*i+1 ; k++){
            cout<<"*";
        }

        cout<<endl;
    }
        for(int i = n ; i >0 ; i--){
        for(int j = 0 ; j < n-i; j++){
            cout<<" ";
        }
        for(int k = 0 ; k < 2*i-1; k++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main(){
    int x=5;
    pattern9(x);



}
