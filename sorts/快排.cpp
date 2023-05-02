#include<iostream>
using namespace std;

int n;
int a[10010];

void quieck_sort(int a[],int left,int right)
{
	int i,j,t,temp;
	if(left > right)
	{
		return;
	}
	temp = a[left];
	i = left;
	j = right;
	while(i != j)
	{
		while(a[j] >= temp && i < j)
		{
			j--;
		}
		while(a[i] <= temp && i < j)
		{
			i++;
		}
		if(i < j)
		{
			swap(a[i],a[j]);
		}
	}
	a[left] = a[i];
	a[i] = temp;
	quieck_sort(a,left,i-1);
	quieck_sort(a,i+1,right);
}

int main()
{
	cin >> n;
	for(int i=1;i <= n;i++)
	{
		cin >> a[i];
	}
	quieck_sort(a,1,n);
	for(int i=1;i <= n;i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}
