#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};
typedef struct node Node;

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

void insert_node(int item ,Node* node){
    Node* new_node = create_node(item,node->next);
    node->next = new_node;

}
Node* prepend(int item, Node* head){
    Node* new_node = create_node(item,head);
    return new_node;
}

Node* append(int item, Node* head){
    Node* new_node = create_node(item,nullptr);
    if(head == nullptr) return new_node;

    Node* current_node = head;
    while(current_node->next != nullptr){
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return head;
}


Node* remove_node(Node* node, Node* head){
    //check if the node is the first node of the LL
    if(node == head){
        head = node->next;
        delete node;

        return head;
    }
    Node* current_node = head;

    while(current_node->next != nullptr){
        if(current_node->next == node){
            break;
        }
        current_node = current_node->next;
    }
    if(current_node == nullptr) return head;
    current_node->next = node->next;
    delete node;
    return head;
}
Node* ll_reverse(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next ;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void printLL(Node* head){
    Node* current_node = head;
    while(current_node != nullptr){
        cout<<current_node->data<<endl;
        current_node = current_node->next;
    }
}

int main(){
    Node *n1,*n2,*n3,*head;
    n1 = create_node(20,nullptr);
    n2 = create_node(15,n1);
    head = n2;
    head = prepend(10,head);
    //printLL(head);
    head = append(25,head);
    insert_node(30,n2);
    //head = remove_node(n2,head);

    //head = ll_reverse(head);
    printLL(head);

    return 0;
}
