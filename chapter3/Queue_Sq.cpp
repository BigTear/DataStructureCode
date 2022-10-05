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














int main() {
    Error("1");
    return 0;
}