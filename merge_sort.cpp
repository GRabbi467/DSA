#include<bits/stdc++.h>
using namespace std;
void merging ( int arr[], int l,int mid, int h);
void merge_sort(int arr [], int n ){
    int p;
    for( p = 2 ; p <= n ; p = p*2){
        for(int i = 0 ; i+p-1<n ; i=i+p){
            int l = i;
            int h = i+p-1;
            int mid = (l+h)/2;
            merging(arr,l,mid,h);

        }
    }
    if(p/2 < n){
        merging(arr, 0, p/2-1, n-1);
    }

}
void merging ( int arr[], int l,int mid, int h){
    int i,j,k, arr2[h+1];
    i = l, j = mid+1, k = l;

    while( i <= mid && j <= h ){
        if(arr[i] < arr[j])
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
    }
    for( ; i <= mid ; i++)
        arr2[k++] = arr[i];

    for( ; j <= h ; j++)
        arr2[k++] = arr[j];

    for(int i = l ; i <= h ; i++){
        arr[i] = arr2[i];
    }
}


int main(){
    int arr[]{ 12, 11, 13, 5, 6, 7, 10, 23, 14 };
    int n = sizeof(arr)/sizeof(arr[0]);
     for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" " ;
    }
    cout<<"\n";
    merge_sort(arr,n);
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" " ;
    }

}

