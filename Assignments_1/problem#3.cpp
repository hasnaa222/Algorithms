//problem#3
 #include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10;
int arr[maxn];
//Count Inversions (Merge Sort)
int MergeSort(int arr[], int temp[], int l, int r);
int merge(int arr[], int temp[], int l, int mid,int r);

int mergeSort(int arr[], int arr_size)
{
    int temp[arr_size];
    return MergeSort(arr, temp, 0, arr_size - 1);
}
int MergeSort(int arr[], int temp[], int l, int r)
{
    int mid, inv_count = 0;
    if (r > l) {
        mid = (r + l) / 2;
        inv_count += MergeSort(arr, temp, l, mid);
        inv_count += MergeSort(arr, temp, mid + 1, r);
        inv_count += merge(arr, temp, l, mid + 1, r);
    }
    return inv_count;
}
int merge(int arr[], int temp[], int l, int mid,int r)
{
    int i, j, k;
    int inv_count = 0;
    i = l;
    j = mid;
    k = l;
    while ((i <= mid - 1) && (j <= r)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (i = l; i <= r; i++)
        arr[i] = temp[i];
    return inv_count;
}
//_____________________

//MAIN FUNCTION
int main(){
    int n; cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }

    int ans = mergeSort(arr, n);
    cout << " Number of inversions are " << ans;
    //________________
    return 0;
}