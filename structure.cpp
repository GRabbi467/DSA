#include<bits/stdc++.h>
using namespace std;
struct student{
    string name;
    int id;
    char section;
};

int main(){
//    student s1;
//    s1.name = "Abdul Karim";
//    s1.id = 1001;
//    s1.section = 'A';
//    cout<<s1.name<<" "<<s1.id<<" "<<s1.section;


//    student *s1,d;
//    s1 = &d;
//    cin>>(*s1).name;
//    cin>>s1->id;
//    cout<<s1->name<<" "<<s1->id;


    //student s1 ={"Rabbi",101,'A'};

    struct student *p;
    p=(struct student*)malloc(sizeof(struct student));
    p->name = "Rabbi";
    cin>>p->id;
    cout<<p->name;
    cout<<'\n'<<p->id;

}
