#include <bits/stdc++.h>

using namespace std;

void countingSort(vector<int> &input_array, int s, int r)
{
    vector<int> output_array(s);
    vector<int> count_array(r);

    // initialize all elements to 0 in count array
    for (int i = 0; i < r; i++)
    {
        count_array[i] = 0;
    }

    // to take a count of all elements in the input array
    for (int i = 0; i < s; i++)
    {
        count_array[input_array[i]]++;
    }

    // cumulative count of count array to get the
    // positions of elements to be stored in the output array
    for (int i = 1; i < r; i++)
    {
        count_array[i] += count_array[i - 1];
    }

    // Placing input array in output array in proper order , such that the output is a sorted array
    for (int i = 0; i < s; i++)
    {
        output_array[count_array[input_array[i]] - 1] = input_array[i];
        count_array[input_array[i]]--;
    }

    // Copy the sorted array back to the original array
    input_array = output_array;
}
