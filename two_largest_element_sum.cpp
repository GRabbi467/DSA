#include<bits/stdc++.h>
using namespace std;
int two_largest_sum(vector<int>&v){
    int sum = 0;
    for(int i = 0 ; i <2 ; i++){
        for(int j = 0 ; j < v.size() - i - 1 ; j++){
            if(v[j]>v[j+1])
                swap(v[j],v[j+1]);
        }
    }

     sum = v[v.size()-1] + v[v.size()-2];
     return sum;
}




int main(){
    vector<int>v{2,5,3,8,1};
    int x = two_largest_sum(v);
    cout<<x;

}
