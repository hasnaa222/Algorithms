#include<iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
	int count = 0;
	int key, j;
	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
			count++;
		}
		arr[j + 1] = key;
	}
	cout << "Number of swap = " << count << endl;
}

int main()
{
	int size;
	cout << "Enter size of array" << endl;
	cin >> size;
	int arr[size];
	cout << "Enter numbers: ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	insertionSort(arr, size);

	return 0;

}