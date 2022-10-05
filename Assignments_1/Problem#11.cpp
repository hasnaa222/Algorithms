#define maxLen 10
#include<iostream>
#include<cmath>
using namespace std;

int dp[maxLen];

bool v[maxLen];


int maxSum(int arr[], int i, int n)
{
	if (i >= n)
		return 0;

	if (v[i])
		return dp[i];
	v[i] = 1;

	dp[i] = max(maxSum(arr, i + 1, n),
		arr[i] + maxSum(arr, i + 2, n));
	return dp[i];
}

int main()
{
	//int arr[] = { -2, -3, -1 };
	//int arr[] = { 3,7,4,6,5 };
	int arr[] = { 3,5,-7,8,10 };
	int n = sizeof(arr) / sizeof(int);

	cout << maxSum(arr, 0, n);

	return 0;
}