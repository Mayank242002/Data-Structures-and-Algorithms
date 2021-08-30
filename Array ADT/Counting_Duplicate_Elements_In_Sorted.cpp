#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Count_Find_duplicate(struct Array *arr)
{
    int i;
    for (i = 0; i < arr->length - 1; i++)
    {
        if (arr->A[i] == arr->A[i + 1]) // if the consequtive term of the array is equal
        {
            int j = i + 1; // set j one next to i and increment as long as both are equal
            while (arr->A[j] == arr->A[i])
                j++;
            cout << arr->A[i] << " is duplicate element and appering for " << j - i << " Times"; // j-i will give total number of duplicate element
            i = j - 1;                                                                           // set i before one before j
        }
    }
}

int main()
{
    struct Array arr;
    int no;
    cout << "Enter the size of the array " << endl;
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;
    cout << "Enter the size of the array" << endl;
    cin >> no;
    cout << "Enter the elements of the array " << endl;
    for (int i = 0; i < no; i++)
        cin >> arr.A[i];
    arr.length = no;
    Count_Find_duplicate(&arr);

    // Display(arr);
    return 0;
}
// Time complexity is O(n)
// Here while loop is negligible as compared to for loop