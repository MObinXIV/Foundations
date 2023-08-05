// Solves the wasted space problem in counting sort
// Sort the numbers according to every digit in
#include <bits/stdc++.h>

using namespace std;
int getMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void countingSort(int arr[], int size, int div)
{
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
        count[(arr[i] / div) % 10]++;// get the current digit and hash it into the array
// Do the accumlative sum
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /*
    For each element arr[i]:
    Divide by div to get the specific digit
    Mod 10 to get the digit value 0-9
    Use this value to index into the count array
    Decrement the count (since we are going backwards)
    Store the element arr[i] in the output array at the correct position based on the count
    */
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / div) % 10] - 1] = arr[i];
        count[(arr[i] / div) % 10]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}
void radixSort(int arr[], int size)
{
    int m = getMax(arr, size);

    for (int div = 1; m / div > 0; div *= 10)
        countingSort(arr, size, div);
}
int main()

{
    int arr[5] = {4, 1, 3, 5, 6};
    radixSort(arr, 5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
}