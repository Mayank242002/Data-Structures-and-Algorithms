int exper(int m, int n)
{
    if (n == 0)
        return 1;
    return exper(m, n - 1) * m;
}
int exper1(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return exper1(m * m, n /
                                 2);
    return m * exper1(m * m, (n - 1) / 2);
}
int main()
{
    int r = exper1(9, 3);
    printf("%d ", r);
    return 0;
}