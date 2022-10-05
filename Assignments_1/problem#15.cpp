#include <iostream>
#include<bits/stdc++.h>
using namespace std;

///Problem#15
///find the minimum index of a repeating element with Hashing
void  minimum_index_of_repeating(int arr[], int size)
{
    int flag = -1;
    set<int> myHash;
    for (int i= size - 1; i >= 0; i--)
    {
        if (myHash.find(arr[i]) != myHash.end())
            {
            flag = i;
            }

        else
            myHash.insert(arr[i]);
    }
    if (flag != -1)
        cout << "The minimum index of the repeating element is : " << flag<< endl;
    else
        cout <<endl<< "Invalid Input"<<endl;
}
int main()
{
    int size_of_arr1 = 7;
    int arr1[] = {5, 6, 3, 4, 3, 6, 4};

    minimum_index_of_repeating(arr1, size_of_arr1);

    //////////////////////////////////////////////

    int size_of_arr2 = 6;
    int arr2[] = {1, 2, 3, 4, 5, 6 };
    minimum_index_of_repeating(arr2, size_of_arr2);


    return 0;
}
