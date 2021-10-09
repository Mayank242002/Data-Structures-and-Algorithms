#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct Stack
{
    int size;
    int Top;
    char *s;
};
void push(struct Stack *st, int x)
{
    if (st->Top == st->size - 1)
        printf("stack overflow");
    else
    {
        st->Top++;
        st->s[st->Top] = x;
    }
}
int pop(struct Stack *st)
{
    int x = -1;
    if (st->Top == -1)
        printf("stack underflow");
    else
    {
        x = st->s[st->Top];
        st->Top--;
    }
    return x;
}
int peek(struct Stack st, int pos)
{
    int x = -1;
    if (st.Top - pos + 1 < 0 && st.Top - pos + 1 > st.size - 1)
        printf("invalid position");
    x = st.s[st.Top - pos + 1];
    return x;
}
int stacktop(struct Stack st)
{
    if (st.Top == -1)
        return -1;
    else
        return st.s[st.Top];
}
int isEmpty(struct Stack st)
{
    if (st.Top == -1)
        return 1;
    else
        return 0;
}
int isFull(struct Stack st)
{
    if (st.Top == st.size - 1)
        return 1;
    else
        return 0;
}
void display(struct Stack st)
{
    for (int i = st.Top; i >= 0; i--)
    {
        printf("%d ", st.s[i]);
        printf("\n");
    }
}
int isBalance(char *exp)
{
    int i;
    struct Stack st;
    st.size = strlen(exp);
    st.Top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(&st, exp[i]);
        else if (exp[i] == ')')
        {
            if (isEmpty(st))
                return false;
            pop(&st);
        }
    }
    return isEmpty(st) ? true : false;
}
int isoperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
        return 0;
    else
        return 1;
}
int Outstackpre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
}
int Instackpre(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
}
char *convert(char *infix)
{
    struct Stack st;
    st.size = strlen(infix);
    st.Top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));
    char *postfix = (char *)malloc((st.size + 1) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isoperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (Outstackpre(infix[i]) > Instackpre(stacktop(st)))
                push(&st, infix[i++]);
            else if (Outstackpre(infix[i]) == Instackpre(stacktop(st)))
            {
                pop(&st);
                i++;
            }
            else
                postfix[j++] = pop(&st);
        }
    }
    while (!isEmpty(st))
        postfix[j++] = pop(&st);
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char *exp = "((a+b)*c)-d^e^f";
    char *postfix = convert(exp);
    printf("%s", postfix);
    return 0;
}