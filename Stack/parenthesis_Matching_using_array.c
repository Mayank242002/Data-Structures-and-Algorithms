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
int main()
{
    char exp[] = "((a+b)*(c-d))";

    if (isBalance(exp))
        printf("balanced");
    else
        printf("not balanced");
}