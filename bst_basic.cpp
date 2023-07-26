#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node{
    int data;
    Node* parent;
    Node* left;
    Node* right;
};

Node* create_node(int item){
    Node* new_node = new Node;
    if(new_node == nullptr){
        cout<<"Node is not created"<<endl;
        exit(1);
    }
    new_node->data = item;
    new_node->parent = nullptr;
    new_node->left = nullptr;
    new_node->right = nullptr;

    return new_node;
}
void add_left_node(Node* node,Node* child){
    node->left = child;
    if(child != nullptr)
        child->parent = node;
}
void add_right_node(Node* node,Node* child){
    node->right = child;
    if(child != nullptr)
        child->parent = node;
}

void pre_order(Node* node){
      cout << node->data << "->";
    if(node->left != nullptr){
        pre_order(node->left);
    }

    if(node->right != nullptr){
        pre_order(node->right);
    }
}

Node* bst_insert(Node* root, Node* node){
    Node* parent_node;
    Node* current_node;
    if(root == nullptr){
        root = node;
        return root;
    }
    parent_node = nullptr;
    current_node = root;
    while(current_node != nullptr){
        parent_node = current_node;
        if(node->data < current_node->data){
            current_node = current_node->left;
        }
        else{
            current_node = current_node->right;
        }
    }
    if(node->data < parent_node->data){
        add_left_node(parent_node,node);
    }
    else{
        add_right_node(parent_node,node);
    }
    return root;
}
Node* create_bst(){
    Node *root,*node;

    vector<int>v{5,17,3,7,12,19,1,4,13,8};
    root = create_node(10);
    for(int i = 0 ; i < v.size() ; i++){
        node = create_node(v[i]);
        root = bst_insert(root,node);
    }

    return root;
}

Node* search_bst(Node* root, int item){
    Node* node = root;
    while(node != nullptr){
        if(node->data == item)
            return node;
        if(item < node->data)
            node = node->left;
        else node = node->right;
    }
    return node;
}
Node* bst_minimum(Node* root){
    Node* node = root;
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

Node* transplant_bst(Node* root, Node* current_node, Node* new_node){
    if(root == current_node){
        root = new_node;
        return root;
    }
    else if(current_node == current_node->parent->left){
        add_left_node(current_node->parent, new_node);
    }
    else{
        add_right_node(current_node->parent, new_node);
    }
    return root;
}
Node* bst_delete(Node* root, Node* node){
    Node* smallest_node;
    if(node->left == nullptr)
        root = transplant_bst(root,node,node->right);
    else if(node->right == nullptr)
        root = transplant_bst(root,node,node->left);
    else{
        smallest_node = bst_minimum(node->right);
        if(smallest_node->parent != node){
            root = transplant_bst(root,smallest_node,smallest_node->right);
            add_right_node(smallest_node,node->right);
        }
            root = transplant_bst(root,node,smallest_node);
            add_left_node(smallest_node,node->left);
    }
    delete node;

    return root;
}

int main(){
    Node* root = create_bst();
    pre_order(root);
    cout<<"\n";
    Node *node1,*node2;
    node1 = search_bst(root,10);

    if(node1 != nullptr){
         cout<<node1->data<<" deleted from bst"<<endl;
         root = bst_delete(root,node1);
    }
    else cout<<"node is not found in bst."<<endl;

    cout<<"New node :"<<endl;
    pre_order(root);

    return 0;
}
