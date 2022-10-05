#include <iostream>
#include <algorithm>
using namespace std;

struct job
{
	int start, finish;
};

bool Compare(job s1, job s2)
{
	return (s1.finish < s2.finish);
}

void print_max_job(job arr[], int n)
{
	sort(arr, arr + n, Compare);

	int i = 0;
	cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

	for (int j = 1; j < n; j++)
	{
		if (arr[j].start >= arr[i].finish)
		{
			cout << "(" << arr[j].start << ", "<< arr[j].finish << "), ";
			i = j;
		}
	}
}

int main()
{
	job arr[] = { {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14} };
	int n = sizeof(arr) / sizeof(arr[0]);
	print_max_job(arr, n);
	return 0;
}
