#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE + 1];
    int head,tail;
} Queue;

void enqueue(int item, Queue *q){
    if((q->tail + 1 ) % (MAX_SIZE + 1) == q->head){
        cout<<"QUEUE IS FULL"<<endl;
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail + 1) % (MAX_SIZE + 1);

}
int dequeue(Queue *q){
    int item;
    if(q->head == q->tail)
    {
        cout<<" QUEUE IS EMPTY"<<endl;
        return -1;
    }
    item = q->data[q->head];
    q->head = (q->head + 1) % (MAX_SIZE + 1);
    return item;
}

void print_queue(Queue *q){
    for(int i = q->head ; i < q->tail ; i++){
        cout<<q->data[i]<<endl;
    }

}

int main(){
    Queue q1; int item;
    q1.head = 0;
    q1.tail = 0;

    enqueue(1,&q1);
    cout<<"Tail: "<<q1.tail<<endl;
    enqueue(3,&q1);
    cout<<"Tail: "<<q1.tail<<endl;
    enqueue(5,&q1);
    cout<<"Tail: "<<q1.tail<<endl;
    item = dequeue(&q1);
    cout<<"Dequeued "<<item<<"  "<<"New head "<<q1.head<<endl;
    item = dequeue(&q1);
    cout<<"Dequeued "<<item<<"  "<<"New head "<<q1.head<<endl;

    cout<<"________________________PRINTING THE QUEUE____________________________"<<endl;
    print_queue(&q1);






}
