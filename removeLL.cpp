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

 Node* remove_node(Node* node, Node* head){
     //removing if the element is the  first element of the LL
     if(node == head){
        head = node->next;
        delete node;

        return head;
     }
     Node* current_node = head;

     while(current_node != nullptr){
        if(current_node->next == node) break;
        current_node = current_node->next;
     }

     if(current_node == nullptr) return head;

     current_node->next = node->next;
     delete node;

     return head;
 }

 void insert_node( int item, Node* node){
     Node* new_node = create_node(item,node->next);
     node->next = new_node;
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
      Node *n1,*head,*n2,*n3,*n4;
      n1 = create_node(10,nullptr);

      head = n1;
      head = prepend(5,head);
      head = append(20,head);
      head = append(30,head);

      //insert_node(15,n1);

      //Before deletation
//      print_linked_list(head);
//      head = remove_node(n1,head);
//      //after deleting 10
      print_linked_list(head);

      return 0;
  }
