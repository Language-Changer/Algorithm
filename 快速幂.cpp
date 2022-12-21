#include<iostream>
using namespace std;

long long power(long long a,long long b,long long p)
{
	long long t = 1;
	while(b > 0)
	{
		if(b & 1)
		{
			t = t * a % p;
		}
		a = a * a % p;
		b >>= 1;
	}
	return t;
}

int main()
{
	int t;
	cin >> t;
	for (int i=1;i<=t;i++)
	{
		long long a, b, p;
		cin >> a >> b >> p;
		cout << power(a,b,p) << endl;
	}
	return 0;
}