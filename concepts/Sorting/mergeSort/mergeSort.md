# Merge Sort algorithm

- **remember it with (divide & merge)**


---

## Pseudo code

    `merge(arr,low,mid,high)

    {

    temp=[];
    left=low;
    right=mid+1;
    while(left<=mid&&right<=high)
    {
        if(arr[left]<=arr[right])
        temp.add(arr[left]);
        left++;
        else
        temp.add(arr[right]);
        right++;
    }
    while(left<=mid)
    temp.add(arr[left]);
    left++;

    while(right<=high)
    temp.add(arr[right]);
    right++;

    for (i=low->high)
    arr[i]=temp[i-low]

    }`



    `mergeSort(arr,low,high)`

    `{`

    `mid=(low+high)/2;`

    `if(low>=high) return;`

    `mergeSort(arr,low,mid);`
    `mergeSort(arr,mid+1,high);`
    `merge(arr,low,mid,high);` 
    `}`