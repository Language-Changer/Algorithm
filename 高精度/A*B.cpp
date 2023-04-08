#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

string a;
long long b;
int c[1005],e[1006];

int main()
{
	cin >> a >> b;
	for(int i=0;i < a.size();i++) c[a.size()-i] = a[i] - '0';
	for(int i=1;i <= 1000;i++)
	{
		e[i] += c[i] * b;
		e[i+1] += e[i] / 10;
		e[i] = e[i] % 10;
	}
	int i;
	for(i=1006;i > 0;i--) if(e[i]) break;
	for(int j=i;j >= 1;j--) cout << e[j];
    return 0;
}
