#include <stdio.h>

// define a function binarySearch that takes an array A, the size of the array N, and the target element to search for.
int binarySearch(int A[], int N, int target)
{ // initialise left and right
    int left = 0;
    int right = N - 1;

    while (left <= right) // continues as long as left is less than or equal to right
    {
        int mid = (left + right) / 2;

        if (A[mid] == target)
        {
            return mid; // if the element at index mid is equal to the target element, we have found the target element and we return the index mid.
        } // end if

        else if (A[mid] < target)
        {
            left = mid + 1; // if the element at index mid is less than the target element, we update left to mid + 1 to search the right half of the subarray.
        } // end else if

        else
        {
            right = mid - 1;
        } // end else

    } // end while

    return -1;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9, 11};
    int N = sizeof(A) / sizeof(A[0]);
    int target = 7;

    int index = binarySearch(A, N, target);

    if (index == -1)
    {
        printf("Target element not found.\n");
    } // end if

    else
    {
        printf("Target element found at index %d.\n", index);
    } // end else

    return 0;
} // end main
