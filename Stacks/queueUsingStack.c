#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int a[1000];
    int b[1000];
    int top1, top2;
} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue) + 1);
    q->top1 = -1;
    q->top2 = -1;
    return q;
}

void myQueuePush(MyQueue *obj, int x)
{
    obj->a[++obj->top1] = x;
}

int myQueuePop(MyQueue *obj)
{
    while (obj->top1 != -1)
    {
        obj->b[++obj->top2] = obj->a[obj->top1--];
    }
    int ans = obj->b[obj->top2--];
    while (obj->top2 != -1)
    {
        obj->a[++obj->top1] = obj->b[obj->top2--];
    }
    return ans;
}

int myQueuePeek(MyQueue *obj)
{
    while (obj->top1 != -1)
    {
        obj->b[++obj->top2] = obj->a[obj->top1--];
    }
    int ans = obj->b[obj->top2];
    while (obj->top2 != -1)
    {
        obj->a[++obj->top1] = obj->b[obj->top2--];
    }
    return ans;
}

bool myQueueEmpty(MyQueue *obj)
{
    if (obj->top1 == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void myQueueFree(MyQueue *obj)
{
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/