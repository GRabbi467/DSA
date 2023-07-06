#include<iostream>
#include<vector>
using namespace std;

int selection_sort(vector<int>&v){
    for(int i = 0 ; i < v.size() ; i++){
        int idx_min = i;
        for( int j = i+1 ; j < v.size() ; j++){
            if( v[j] < v[idx_min] ){
                idx_min = j;
            }
        }
        if( idx_min != i){
            swap(v[i],v[idx_min]);
        }
    }
}



int main(){
    vector<int> v{4,2,7,5,3,1,43,5};
    selection_sort(v);
    for(auto e: v){
        cout<<e<<endl;
    }


}
