#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void  Rearrange_array(int arr[],int arraySize)
{


    map<int, int> MyHash;
    for (int i=0; i<arraySize; i++)
    {
        MyHash[arr[i]]++;
    }
    for (int i=0; i<arraySize; i++)
    {
        int count = MyHash[arr[i]];
        for (int j=0; j<count; j++){ /// print the elements count times
            cout<<arr[i]<<" ";
            MyHash.erase(arr[i]);
        }

    }
    cout<<endl;
}

int main()
{
    ///test_case_1
    int arr[] = {1, 2, 3, 1, 2, 1};
    int arraySize = sizeof(arr)/sizeof(arr[0]);
    Rearrange_array(arr,arraySize);
    ///test_case_2
    int arr_[] = {5, 4, 5, 5, 3, 1, 2, 2, 4};
    int arraySize_ = sizeof(arr_)/sizeof(arr_[0]);
    Rearrange_array(arr_,arraySize_);

    return 0;
}
