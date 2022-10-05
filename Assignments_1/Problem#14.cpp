#include <iostream>
#include <unordered_map>
using namespace std;

void findPair(int x[], int n, int target)
{
	unordered_map<int, int> map;

	for (int i = 0; i < n; i++)
	{
		if (map.find(target - x[i]) != map.end())
		{
			cout << "Pair found (" << x[map[target - x[i]]] << ", "
				<< x[i] << ")\n";
			return;
		}

		map[x[i]] = i;
	}

	cout << "Pair not found" << endl;
}

int main()
{
	int x[] = { 8, 7, 2, 5, 3, 1 };
	int target = 10;

	//int nums[] = { 5, 2, 6, 8, 1, 9 };
	//int target = 12;

	int n = sizeof(x) / sizeof(x[0]);

	findPair(x, n, target);

	return 0;
}