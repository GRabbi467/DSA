#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};

typedef struct node Node;

Node* create_node(int item,Node* next){
    //Node* new_node = (Node*)malloc(sizeof(Node)); //C type memory allocation
   Node* new_node = new Node; //C++ memory allocation
    if(new_node == nullptr){
        cout<<"Could not create a new node";
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;

    return new_node;
}

Node* prepend(int item, Node* head){
    Node * new_node = create_node(item,head);
    return new_node;
}

int main(){
    Node *n1,*n2,*n3,*n4,*n5,*head;

    n1 = create_node(10,nullptr);
    head = n1;

    head = prepend(20,head);

    n2 = head;
    n3 = n2->next;

    head = prepend(30,head);
    n4 = head;
    cout<<"First data :" <<n4->data<<"  Next address  :"<<n4->next<<endl;
    cout<<"Second data :"<<n2->data<<" "<<n2<<endl;
    cout<<"Third data :"<<n3->data<<endl;


}
