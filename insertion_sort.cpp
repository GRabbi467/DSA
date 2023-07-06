#include<iostream>
#include<vector>
using namespace std;

void insertion(vector<int>&v){
    for(int i = 1 ; i < v.size() ; i ++){
        int item = v[i];
       int  j = i -1;
    while(j >= 0 && v[j] > item){
        v[j+1] = v[j];
        j--;
    }
    v[j+1] = item;
    }
}

int main(){
     vector<int>v{2,4,1,5,3,7,6,0};
     insertion(v);
     for(auto e:v)
        cout<<e<<endl;

}
