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
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}
int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
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
            if (pre(infix[i]) > pre(stacktop(st)))
                push(&st, infix[i++]);
            else
                postfix[j++] = pop(&st);
        }
    }
    while (!isEmpty(st))
        postfix[j++] = pop(&st);
    postfix[j] = '\0';
    return postfix;
}
int Eval(char *postfix)
{
    struct Stack st;
    st.size = strlen(postfix);
    st.Top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));

    int i = 0, x1 = 0, x2 = 0, r = 0;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isoperand(postfix[i]))
            push(&st, postfix[i] - '0');
        else
        {
            x2 = pop(&st);
            x1 = pop(&st);
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            }
            push(&st, r);
        }
    }
    return pop(&st);
}

int main()
{
    char *exp = "3*5+6/2-4";
    char *postfix = convert(exp);
    printf("%s", postfix);
    printf("\nResult=%d", Eval(postfix));

    return 0;
}