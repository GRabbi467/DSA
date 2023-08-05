#include<bits/stdc++.h>
using namespace std;
#define PI 3.1416
int main(){
    int o1,o2,x1,x2,y1,y2; double r,l,s;
    cout<<"Enter the co-ordinates of center"<<endl;
    cin>>o1>>o2;
    cout<<"Enter the co-ordinates of point A"<<endl;
    cin>>x1>>x2;
    cout<<"Enter the co-ordinates of point B"<<endl;
    cin>>y1>>y2;
    l = ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));
    r = sqrt(l);
    s = (PI*r) / 2;

    cout<<s;
}
