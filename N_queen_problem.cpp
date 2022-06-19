#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
void out(int x[], int n)
{
	cnt++;
	cout << "Arrangement number: " << cnt << '\n';
	cout << "Queens location are:\n";
	for (int i = 0; i < n; i++)
	{
		cout << i+1 << " " << x[i]+1 << '\n';
	}
}

bool poss(int k, int idx, int x[])
{
	for (int i = 0; i < k; i++)
		if (x[i] == idx)return 0;
		else if (abs(x[i] - idx) == abs(i - k))return 0;
	return 1;
}

void queens(int k, int n, int x[])
{
	for (int i = 0; i < n; i++)
	{
		if (poss(k, i, x))
		{
			x[k] = i;
			if (k == n - 1)out(x, n);
			else queens(k + 1, n, x);
		}
	}
}

int main()
{
	cout << "Enter the number of queens: ";
	int n;
	cin >> n;
	int x[n];
	for (int i = 0; i < n; i++)x[i] = 0;
	if (n == 1)
	{
		cout << "Combination 1:\n0 0";
		return 0;
	}
	if (n <= 3)
	{
		cout << "No possible arrangement possible.\n";
		return 0;
	}
	queens(0, n, x);
	cout << cnt;
	return 0;
}