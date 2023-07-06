#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;
struct node {
    int data;
    Node* next;
};

Node* create_node(int item,Node* next){
   Node* new_node = new Node;


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

 Node* append(int item, Node* head){
     Node* new_node = create_node(item,nullptr);
     if(head == nullptr){
        return new_node;
     }
     Node* current_node = head;

     while( current_node->next != nullptr){
        current_node = current_node->next;
     }
     current_node->next = new_node;

     return head;
 }

  void print_linked_list(Node* head){
      Node* current_node = head;
      while(current_node != nullptr){
        cout<<current_node->data<<" ";
        current_node = current_node->next;
      }
      cout<<"\n";
  }

  int main(){
      Node *n1,*head;
      n1 = create_node(10,nullptr);
      head = n1;
      head = prepend(30,head);
      head = append(20,head);
      head = append(40,head);
      print_linked_list(head);
  }
