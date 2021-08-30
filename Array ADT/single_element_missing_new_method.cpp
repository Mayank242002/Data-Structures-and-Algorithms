#include <iostream>
using namespace std;
struct Array
{
    int *A;
    int size;
    int length;
};

void SingleMissingNumber1(struct Array *arr)
{
    int low = arr->A[0];      // take the 1st elelmt of the array
    int difference = low - 0; // the difference should be constant if not then add the index & diffence to get missing number

    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] - i != difference)
        {
            cout << "Missing element is " << i + difference;
            break;
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
    SingleMissingNumber1(&arr);
    return 0;
}