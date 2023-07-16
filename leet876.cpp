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
  int count_node (Node* head){
      int count{0};
      Node* current_node = head;
      while (current_node != nullptr){
            count++;
            current_node = current_node->next;
      }
      return count;
  }

  int main(){
      Node *n1,*head,*n2,*n3,*n4,*n5,*n6,*current_node;
      int cnt;
      n1 = create_node(10,nullptr);
      n2 = create_node(20,n1);
      n3 = create_node(30,n2);
      n4 = create_node(40,n3);
      n5 = create_node(60,n4);
      n6 = create_node(70,n5);
      insert_node(50,n1);
      head = n6;
      cnt = count_node(head);
      int middle = (cnt/2) + 1;


      for(int i = 1 ; i < middle ; i++){
        current_node = head;
        head = current_node->next;
        delete current_node;
      }

      print_linked_list(head);
      return 0;
  }
