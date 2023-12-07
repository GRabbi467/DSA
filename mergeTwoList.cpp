#include<iostream>
#include<vector>
using namespace std;
void mergeTwoList(int a[], int b[], int m, int n, int c[]){
    int i = 0, j = 0 , k = 0;

    while(i < m && j < n){
        if(a[i] < b[j]){
            c[k++] = a[i++];
        }
        else{
            c[k++] = b[j++];
        }
    }
      for( ; i < n ; i++)
            c[k++] = a[i];
      for( ; j < n ; j++)
            c[k++] = b[j];

}

int main(){
    int A[]{2,10,18,20,23};
    int B[]{4,9,19,25};
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
    int C[m+n];
    mergeTwoList(A,B,m,n,C);
    for( int i = 0 ; i < m+n ; i++){
        cout<<C[i]<<endl;
    }



}
