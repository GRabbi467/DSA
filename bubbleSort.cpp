#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>&v){
    for(int i = 0 ; i < v.size() ; i++){
        for(int j = 0 ; j < v.size()-i-1; j++){
            if(v[j]>v[j+1]){
                swap(v[j+1],v[j]);
            }
        }
    }
}

int main(){
    vector<int>v{2,4,1,5,3,7,6,0};
    bubbleSort(v);
    for(auto e : v)
        cout<<e<<endl;

}
