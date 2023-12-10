#include<bits/stdc++.h>
using namespace std;
void merging ( int arr[], int l,int mid, int h);
void merge_sort(int arr[], int l, int h){
    int mid;
    if(l<h){
        mid = (l+h)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,h);
        merging(arr,l,mid,h);

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
    int a[]{8,2,9,6,5,3,7,4};
    int n = sizeof(a)/sizeof(a[0]);
    int l =0;
    int h = n-1;
    int mid = (l+h)/2;
    merge_sort(a,l,h);
    cout<<"Sorted List :";
    for(int i = 0 ; i < n ; i++){
        cout<<a[i]<<" ";
    }

}
