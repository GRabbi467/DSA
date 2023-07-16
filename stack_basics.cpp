#include<bits/stdc++.h>
using namespace std;
#define STACK_MAX 10

typedef struct {
    int data[STACK_MAX];
    int top;
}Stack;

void push(Stack *s , int item){
    if(s->top < STACK_MAX){
        s->data[s->top] = item;
        s->top = s->top + 1;
    }
    else cout<<"THE STACK IS FULL"<<endl;
}

int pop(Stack *s){
    int item;
    if(s->top ==0){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    else{
        s->top = s->top - 1;
        item = s->data[s->top];
    }
    return item;
}

void print_stack(Stack *s){
   for(int i = 0 ; i < s->top ; i++){
    cout<<s->data[i]<<endl;
   }
}



int main(){
    Stack my_stack;
    int item;
    my_stack.top = 0;
    push(&my_stack,1);
    push(&my_stack,2);
    push(&my_stack,3);

    item = pop(&my_stack);
    cout<<"item "<<item<<" popped from stack"<<endl;




    print_stack(&my_stack);
}
