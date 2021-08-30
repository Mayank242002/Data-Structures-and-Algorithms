#include <stdio.h>
#define SIZE 10

int hash(int key)
{
    return key % SIZE;
}
int hash2(int key)
{
    return (7 - (key % 7));
}

int probe(int HT[], int key)
{
    int index = hash(key);
    int index2 = hash2(key);
    int i = 0;
    while (HT[(index + i * index2) % SIZE] != 0)
    {
        i++;
    }
    return (index + i * index2) % SIZE;
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
    int index2 = hash2(key);
    int i = 0;
    while (HT[(index + i * index2) % SIZE] != key)
    {
        i++;
    }
    return (index + i * index2) % SIZE;
}

int main()
{
    int HT[10] = {0};
    insert(HT, 5);
    insert(HT, 25);
    insert(HT, 15);
    insert(HT, 35);
    insert(HT, 75);
    insert(HT, 95);

    printf("%d ", Search(HT, 95));
}