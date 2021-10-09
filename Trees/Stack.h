

struct Stack
{
    int size;
    int Top;
    struct Node **s;
};
void push(struct Stack *st, struct Node *x)
{
    if (st->Top == st->size - 1)
        printf("stack overflow");
    else
    {
        st->Top++;
        st->s[st->Top] = x;
    }
}
struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;
    if (st->Top == -1)
        printf("stack underflow");
    else
    {
        x = st->s[st->Top];
        st->Top--;
    }
    return x;
}

int isEmptystack(struct Stack st)
{
    if (st.Top == -1)
        return 1;
    else
        return 0;
}
void createstack(struct Stack *st, int size)
{
    st->size = size;
    st->s = (struct Node **)malloc(st->size * sizeof(struct Node *));
    st->Top = -1;
}
