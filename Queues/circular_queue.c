#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("queue is full");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("queue is empty");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
}
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

int main()
{
    struct Queue q;
    create(&q, 5);
    enqueue(&q, 12);
    enqueue(&q, 22);
    enqueue(&q, 32);
    enqueue(&q, 42);
    dequeue(&q);
    Display(q);
    return 0;
}