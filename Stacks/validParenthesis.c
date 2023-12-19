#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 10000
int top = -1;
char arr[size];

// push , pop , printStack , isValid

void push(char ele)
{
    if (top == size - 1)
    {
        printf("\nOverflow");
    }
    else
    {
        top += 1;
        arr[top] = ele;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        top -= 1;
    }
}

void printStack()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%c", arr[i]);
        arr[i] = '\0';
    }
    printf("\n");
}

bool isValid(char *s)
{
    if (s[0] == ')' || s[0] == '}' || s[0] == ']')
    {
        top = -1;
        return false;
    }
    else
    {
        int i = 0;
        while (s[i] != '\0')
        {
            if ((s[i] == '[') || (s[i] == '(') || (s[i] == '{'))
            {
                push(s[i]);
            }
            else if ((top != -1) && ((arr[top] == '[' && s[i] == ']') || (arr[top] == '(' && s[i] == ')') || (arr[top] == '{' && s[i] == '}')))
            {
                pop();
            }
            else
            {
                top = -1;
                return false;
            }
            i++;
        }

        if (top < 0)
        {
            top = -1;
            return true;
        }
        else
        {
            top = -1;
            return false;
        }
    }
}

int main()
{
    char str[1000] = "(())";
    scanf("%s", str);

    if (isValid(str))
    {
        printf("It is a Valid Parenthesis\n");
    }
    else
    {
        printf("It is not a Valid Parenthesis\n");
    }
}