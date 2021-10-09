#include <stdio.h>
#include <string.h>

int test_sequence(char *s1, char *s2)
{
    int i = 0, j = 0;
    while (s1[i] != '\0')
    {
        while ((s1[i] != s2[j]) && s2[j] != '\0')
        {
            j++;
        }
        if (s2[j] == '\0')
            break;
        i++;
        j++;
    }
    if (s1[i] == '\0')
        return 1;
    else
        return 0;
}

int main()
{
    char s1[100000], s2[100000];
    printf("enter first string");
    gets(s1);
    printf("enter second string");
    gets(s2);
    int p;
    if (strlen(s1) > strlen(s2))
        p = test_sequence(s2, s1);
    else
        p = test_sequence(s1, s2);

    if (p)
        printf("POSITIVE");
    else
        printf("NEGATIVE");
}