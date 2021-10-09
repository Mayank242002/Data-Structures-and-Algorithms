#include <iostream>
using namespace std;
struct Array
{
    int *A;
    int size;
    int length;
};

// Finding duplicate for unsorted array
void Count_duplicate_unsorted(struct Array *arr)
{

    for (int i = 0; i < arr->length - 1; i++)
    {
        int count = 1; // intializing count as 1
        if (arr->A[i] != -1)
        { // if element is already checkd then dont go for checking the elements
            for (int j = i + 1; j < arr->length; j++)
            {
                if (arr->A[i] == arr->A[j]) // if duplicate element is found
                {
                    count++;        // increament the count
                    arr->A[j] = -1; // and mark element as -1 so that next time it won't confuse
                }
            }
            if (count > 1) // if count is greater then i.e there is duplicate element
                cout << arr->A[i] << " is appearing for " << count << " Times" << endl;
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
    Count_duplicate_unsorted(&arr);
    return 0;
}