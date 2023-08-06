#include <iostream>
#include <vector>

using namespace std;

int getMax(vector<int> arr)
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(vector<int> &arr, int div)
{
    vector<int> output(arr.size());
    vector<int> count(10, 0);

    int originalSize = arr.size();

    for (int i = 0; i < originalSize; i++)
    {
        int temp = arr[i];
        if (temp < 0)
            temp = ~temp;
        else
            temp = temp;
        count[(temp / div) % 10]++; // get the current digit and hash it into the array
    }

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
    for (int i = originalSize - 1; i >= 0; i--)
    {
        int temp = arr[i];
        if (temp < 0)
            temp = ~temp;
        else
            temp = temp;
        output[count[(temp / div) % 10] - 1] = temp;
        count[(temp / div) % 10]--;
    }

    for (int i = 0; i < originalSize; i++)
        arr[i] = output[i];
}

void radixSort(vector<int> &arr)
{
    int m = getMax(arr);

    for (int div = 1; m / div > 0; div *= 10)
        countingSort(arr, div);
}
