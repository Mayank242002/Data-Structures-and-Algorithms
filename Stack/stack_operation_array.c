#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int Top;
    int *s;
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
int main()
{
    struct Stack st;
    printf("enter the size of the stack");
    scanf("%d", &st.size);
    st.s = (int *)malloc(st.size * sizeof(int));
    st.Top = -1;

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);

    printf("top=%d\n", peek(st, 2));
    display(st);
}