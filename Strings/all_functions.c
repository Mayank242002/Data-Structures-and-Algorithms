#include <stdio.h>
#define MAX 50

int length_array(char *);

void change_case(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
}
void vowels_consonants(char *str, int *vcount, int *ccount)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            (*vcount)++;
        else if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
            (*ccount)++;
    }
}
void compare(char *str1, char *str2)
{
    int i, j;
    for (i = 0, j = 0; str1[i] != '\0' && str2[j] != '\0'; i++, j++)
    {
        if (str1[i] != str2[j])
            break;
    }
    if (str1[i] == str2[j])
        printf("equal");
    else if (str1[i] < str2[j])
        printf("smaller");
    else
        printf("greater");
}
void palindrome(char *str)
{
    int i, j = length_array(str) - 1;
    for (i = 0; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            printf("not palindrome");
            break;
        }
    }
    if (i >= j)
        printf("palindrome");
}
int words(char *str)
{
    int i, word = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' && str[i - 1] != ' ')
            word++;
    }
    return word + 1;
}
void reverse(char *str)
{
    int i, j = length_array(str) - 1;
    for (i = 0; i < j; i++, j--)
    {
        int temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
void duplicate1(char *str) //using hash table
{
    int H[26] = {0};
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        H[str[i] - 97]++;
    }
    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            printf("\n%c occurs %d times", i + 97, H[i]);
        }
    }
}

void duplicate2(char *str)
{
    int H = 0, x = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        x = 1;
        x = x << str[i] - 97;
        if ((x & H) > 0)
            printf("\n%c is duplicate", str[i]);
        else
            H = x | H;
    }
}
void anagram(char *str1, char *str2)
{
    int i, H[26] = {0};
    for (i = 0; str1[i] != '\0'; i++)
    {
        H[str1[i] - 97]++;
    }
    for (i = 0; str1[i] != '\0'; i++)
    {
        H[str2[i] - 97]--;
        if (H[str2[i] - 97] < 0)
        {
            printf("not anagram");
            break;
        }
    }
    if (str2[i] == '\0')
        printf("anagram");
}
int main()
{
    char str[MAX], str2[MAX];
    gets(str);
    gets(str2);

    int N = length_array(str);
    int vcount = 0, ccount = 0;
    printf("length of the string is %d", N);

    duplicate2(str);
    anagram(str, str2);

    return 0;
}

int length_array(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
    }
    return i;
}
