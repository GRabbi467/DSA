#include<bits/stdc++.h>
using namespace std;

int find_largest(vector<int> &v){
   // int steps=0,comparisons=0;
    for(int step = 0 ; step <1 ; step++ ){
          //  steps++;
        for(int comp = 0 ; comp <v.size()-step-1 ; comp++){
           // comparisons++;
            if(v[comp]>v[comp+1])
                swap(v[comp],v[comp+1]);
        }
    }
    return v[v.size()-1];
   // cout<<v[4]<<" Steps "<<steps<<":"<<"Comparisons"<<comparisons<<endl;
}



int main(){
    vector<int>v{8,2,4,1,5};
    int largest = find_largest(v);
    //find_largest(v);
    cout<<largest;

}
