#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr []={1,2,2,4,3,67,67,43,23,43,54,2,35,100};
    int len = sizeof(arr)/sizeof(arr[0]);
    for ( int i = 0 ; i < len ; i++)
        for( int j = i+1 ; j < len ; j++)
        {
            if ( arr[i] == arr[j] )
            {
                for( int k = j ; k < len - 1 ; k++)
                    arr[k] = arr[k+1]; len--;

            }


        }
        for ( int i = 0 ; i <  len ; i ++)
            cout<<arr[i]<<" ";

    }






