#include <stdio.h>
#define SIZE 10

int hash(int key)
{
    return key % SIZE;
}

int probe(int HT[], int key)
{
    int index = hash(key);
    int i = 0;
    while (HT[(index + i * i) % SIZE] != 0)
    {
        i++;
    }
    return (index + i * i) % SIZE;
}
void insert(int HT[], int key)
{
    int index = hash(key);
    if (HT[index] != 0)
    {
        index = probe(HT, key);
    }
    HT[index] = key;
}

int Search(int HT[], int key)
{
    int index = hash(key);
    int i = 0;
    while (HT[(index + i * i) % SIZE] != key)
    {
        i++;
    }
    return (index + i * i) % SIZE;
}

int main()
{
    int HT[10] = {0};
    insert(HT, 10);
    insert(HT, 20);
    insert(HT, 35);
    insert(HT, 45);
    insert(HT, 55);
    printf("%d ", Search(HT, 55));
}