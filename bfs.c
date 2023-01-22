// to implement breadth first search
#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
} queue; // end of structure definition
int isEmpty(queue *q)
{
    if (q->front == q->rear)
        return (1);
    return (0);
} // end of fn.
int isFull(queue *q)
{
    if (q->rear == q->size - 1)
        return (1);
    return (0);
} // end of fn.
void enqueue(queue *q, int val)
{
    if (isFull(q))
        printf("\nThe queue is full");
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
    } // end of if-else
} // end of fn.
int dequeue(queue *q)
{
    int a = -1;
    if (isEmpty(q))
        printf("\nThe queue is empty");
    else
    {
        q->front++;
        a = q->arr[q->front];
    } // end of if-else
    return (a);
} // end of fn.
void main()
{
    queue q;
    q.size = 400;
    q.front = q.rear = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    int node;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int adj[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (adj[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            } // end of if block
        } // end of for loop
    } // end of while loop
} // end of main
