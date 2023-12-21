#include <stdio.h>
#include <stdlib.h>

// typedef struct stack
// {
//     int size;
//     int top;
//     int *arr;
// } stack;

// void push(struct stack *ptr, int num)
// {
//     if (ptr->top == (ptr->size - 1))
//     {
//         printf("\nOverflow");
//     }
//     else
//     {
//         ptr->top += 1;
//         ptr->arr[ptr->top] = num;
//     }
// }

// void pop(struct stack *ptr)
// {
//     if (ptr->top == -1)
//     {
//         printf("\nUnderflow");
//     }
//     else
//     {
//         // printf("popped");
//         ptr->arr[ptr->top] = -1;
//         ptr->top -= 1;
//     }
// }

// void printStack(struct stack *ptr)
// {
//     for (int i = ptr->top; i >= 0; i--)
//     {
//         printf("%d", ptr->arr[i]);
//     }
//     printf("\n");
// }

// int longestValidParentheses(char *s)
// {
//     stack *st = (stack *)malloc(sizeof(stack));
//     st->size = 30000;
//     st->top = -1;
//     st->arr = (int *)malloc((st->size) * sizeof(int));
//     int i = 0;
//     while (s[i] != '\0')
//     {
//         if (s[i] == '(')
//         {
//             push(st, i);
//         }
//         else if ((st->top != -1) && (s[i] == ')' && s[st->arr[st->top]] == '('))
//         {
//             // printf("popped");
//             pop(st);
//         }
//         else
//         {
//             push(st, i);
//         }
//         // printf("%d" , st->top);
//         i++;
//     }
//     printStack(st);

//     int max = i;

//     if (st->top == -1)
//     {
//         return max;
//     }
//     else
//     {
//         int start;
//         int end = i;
//         max = 0;

//         while (st->top != -1)
//         {
//             start = st->arr[st->top];
//             if (max < end - start - 1)
//             {
//                 max = end - start - 1;
//             }
//             end = start;
//             st->top -= 1;
//         }
//         if (end > max)
//         {
//             return end;
//         }
//     }

//     return max;
// }

//*************

int longestValidParentheses(char *s)
{
    int arr[30000];
    int top = -1;
    int i = 0;
    while (s[i] != '\0')
    {
        if ((top != -1) && (s[i] == ')' && s[arr[top]] == '('))
        {
            top -= 1;
        }
        else
        {
            top += 1;
            arr[top] = i;
        }
        i++;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }

    int max = 0;
    int start = 0;
    int end = i;
    while (top > -1)
    {
        start = arr[top];
        if (max < end - start - 1)
        {
            max = end - start - 1;
        }
        end = start;
        top--;
    }
    if (max < end)
    {
        max = end;
    }
    return max;
}

int main()
{
    printf("%d ", longestValidParenthesis("())"));
}