#include<iostream>
#include<algorithm>
using namespace std;

int a[5000005],temp[5000005];

void Sort(int l,int r)
{
	int i,j;
	if(l == r)
	{
		return;
	}
	int mid = (l + r) / 2;
	Sort(l,mid);
	Sort(mid+1,r);
	i = l;
	j = mid+1;
	int k = l;
	while(i <= mid && j <= r)
	{
		if(a[i] < a[j])
		{
			temp[k++] = a[i];
			i++;
		}
		else
		{
			//sum += mid-i+1;
			temp[k++] = a[j];
			j++;
		}
	}
	while(i <= mid)
    {
		temp[k++] = a[i++];
    }
	while(j <= r)
    {
		temp[k++] = a[j++];
    }
	for(int i=l;i <= r;i++)	
    {
		a[i] = temp[i];
    }
}

int main()
{
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	Sort(1,n);
	for(int i = 1;i <= n;i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}