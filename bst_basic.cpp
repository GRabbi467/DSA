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
void in_order(Node* node){
    if(node->left != nullptr){
        in_order(node->left);
    }
    cout << node->data << "->";
    if(node->right != nullptr){
        in_order(node->right);
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

Node* bst_transplant(Node* root, Node* current_node, Node* new_node){
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
        root = bst_transplant(root,node,node->right);
    else if(node->right == nullptr)
        root = bst_transplant(root,node,node->left);
    else{
        smallest_node = bst_minimum(node->right);
        if(smallest_node->parent != node){
            root = bst_transplant(root,smallest_node,smallest_node->right);
            add_right_node(smallest_node,node->right);
        }
            root = bst_transplant(root,node,smallest_node);
            add_left_node(smallest_node,node->left);
    }
    delete node;

    return root;
}
int bst_height(Node* root){
    if(root == nullptr) return 0;
    int lheight = bst_height(root->left);
    int rheight = bst_height(root->right);

    return 1+max(lheight,rheight);

}
int bst_diameter(Node* root){
   if(root == nullptr) return 0;
   int l_height = bst_height(root->left);
   int r_height = bst_height(root->right);
   int l_diameter = bst_diameter(root->left);
   int r_diameter = bst_diameter(root->right);
   int dia = max(l_height + r_height +1,max(l_diameter,r_diameter));
   return dia;
}
  bool isBST(Node* root, int min, int max){
        if(root == nullptr) return true;
        if(root->data <= min || root->data > max) return false;

        return isBST(root->left, min, root->data) &&
               isBST(root->right,root->data,max);
    }

Node* invert(Node* root){
    if(root == nullptr) return NULL;
    invert(root->left);
    invert(root->right);
    swap(root->left,root->right);
    return root;
}
int sum(Node* root){
    int addition = root->data + root->left->data + root->right->data;
    return addition;
}

int main(){
    int min = INT_MIN;
    int max = INT_MAX;
    //creating a bst
    Node* root = create_bst();
    //checking wheather the tree is bst or not
    cout<<"BST or NOT"<<endl;
    bool bst = isBST(root,min,max);
    string x = (bst) ? "IsBST ":"NotBST";
    cout<<x<<endl;
    //pre order traversal
    cout<<"BST in pre order:"<<endl;
    pre_order(root);
    //in order traversal
    cout<<"BST in In order:"<<endl;
    in_order(root);
    cout<<"\n";
    //height of a bst
    int depth = bst_height(root);
    cout<<endl<<"Height of the bst :"<<depth<<endl;
    //diametre of a bst
    int diameter = bst_diameter(root);
    cout<<"Diameter of the tree is :"<<diameter<<endl;
    //Invert a bst
    int add = sum(root);
    cout<<"Sum of root "<<add<<endl;
    root = invert(root);
    cout<<"After Inverting"<<endl;
    pre_order(root);
    cout<<"\n";


    Node *node1,*node2;
    node1 = search_bst(root,10); //searching a node from bst

    if(node1 != nullptr){
         cout<<node1->data<<" deleted from bst."<<endl;//deleting a node
         root = bst_delete(root,node1);
    }
    else cout<<"node is not found in bst."<<endl;

    cout<<"After deleting 10 "<<endl;
    pre_order(root);

    return 0;
}
