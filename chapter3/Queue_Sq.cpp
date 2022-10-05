#include <stdio.h>
#include <stdlib.h>

#define Error(msg) {printf("Error: %s\n",msg);abort();}

typedef int ElemType;

#define QUEUE_MAX_SIZE 10
typedef struct {
    ElemType *elem;
    int front;
    int rear;
} SqQueue;

void InitQueue_Sq(SqQueue &Q) {
    Q.elem = new ElemType[QUEUE_MAX_SIZE];
    if (!Q.elem) Error("Overflow!");
    Q.front = Q.rear = 0;
}

void DestroyQueue_Sq(SqQueue &Q) {
    delete[] Q.elem;
    Q.front = Q.rear = 0;
}

void ClearQueue_Sq(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

int QueueLength_Sq(SqQueue Q) {
    int length = (Q.rear - Q.front + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
    return length;
}

void GetHead_Sq(SqQueue Q, ElemType &e) {
    if (Q.front == Q.rear) Error("Queue Empty!");
    e = Q.elem[Q.front];
}

void EnQueue_Sq(SqQueue &Q, ElemType e) {
    if (((Q.rear + 1) % QUEUE_MAX_SIZE) == Q.front) Error("Queue Overflow!");
    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear + 1) % QUEUE_MAX_SIZE;
}

void DeQueue_Sq(SqQueue &Q, ElemType &e) {
    if (Q.front == Q.rear) Error("Queue Empty!");
    e = Q.elem[Q.front];
    Q.front = (Q.front + 1) % QUEUE_MAX_SIZE;
}

void mem(SqQueue q) {
    printf("{");
    for (int i = 0; i < QUEUE_MAX_SIZE; i++) {
        printf("%d,", q.elem[i]);
    }
    printf("} Front: %d Rear: %d\n", q.front, q.rear);
}


int main() {
    SqQueue q;
    InitQueue_Sq(q);
    //mem(q);

    EnQueue_Sq(q, 1);
    EnQueue_Sq(q, 2);
    EnQueue_Sq(q, 3);
    EnQueue_Sq(q, 1);
    EnQueue_Sq(q, 2);
    EnQueue_Sq(q, 3);
    mem(q);

    ElemType temp;
    DeQueue_Sq(q, temp);
    mem(q);
    printf("temp = %d\n", temp);

    DeQueue_Sq(q, temp);
    mem(q);
    printf("temp = %d\n", temp);


    return 0;
}






















