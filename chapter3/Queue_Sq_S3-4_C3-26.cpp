#include <stdio.h>
#include <stdlib.h>

#define Error(msg) {printf("Error: %s\n",msg);abort();}

// application

// ***** S3-4 C3-26 *****
typedef struct {
    char *name;
    char sex;
} Person;
typedef Person ElemType;

// ***** S3-4 C3-26 *****

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

// ***** S3-4 C3-26 *****
#include <iostream>

using namespace std;

void DancePartner(Person dancer[], int num) {
    SqQueue Mdancers, Fdancers;
    InitQueue_Sq(Mdancers);
    InitQueue_Sq(Fdancers);
    for (int i = 0; i < num; i++) {
        Person p = dancer[i];
        if (p.sex == 'F') EnQueue_Sq(Fdancers, p);
        else EnQueue_Sq(Mdancers, p);
    }
    cout << "The dancing partners are:\n";
    while (!(Fdancers.front == Fdancers.rear) && !(Mdancers.front == Mdancers.rear)) {
        Person p;
        DeQueue_Sq(Fdancers, p);
        cout << p.name << " ";
        DeQueue_Sq(Mdancers, p);
        cout << p.name;
        cout << "\n";
    }
    if (!(Fdancers.front == Fdancers.rear)) {
        int count = QueueLength_Sq(Fdancers);
        cout << "There are " << count << " women waitin for the next round.\n";
        Person p;
        GetHead_Sq(Fdancers, p);
        cout << p.name << " will be the first to get a partner.\n";
    }
    if (!(Mdancers.front == Mdancers.rear)) {
        int count = QueueLength_Sq(Mdancers);
        cout << "\nThere are " << count << " men waitin for the next round.\n";
        Person p;
        GetHead_Sq(Mdancers, p);
        cout << p.name << " will be the first to get a partner.\n";
    }
}
// ***** S3-4 C3-26 *****

int main() {
    Person a[] = {
            {(char *) "alex",   'F'},
            {(char *) "august", 'M'},

            {(char *) "blex",   'F'},
            {(char *) "bugust", 'M'},

            {(char *) "clex",   'M'},
            {(char *) "cugust",   'F'},
            {(char *) "DD", 'F'},
    };
    DancePartner(a, sizeof(a) / sizeof(Person));
    return 0;
}























