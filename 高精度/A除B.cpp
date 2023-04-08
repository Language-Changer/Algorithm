#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long c[1005],e[1006];
long long b;
string a;

int main()
{
	cin >> a >> b;
	for(int i=0;i < a.size();i++) c[a.size()-i] = a[i] - '0';
	for(int i=1000;i >= 1;i--)
	{
		e[i] = c[i] / b;
		c[i-1] += c[i] % b * 10;
	}
	int i;
	for(i=1000;i > 0;i--) if(e[i]) break;
	for(int j=i;j >= 1;j--) cout << e[j];
    return 0;
}
