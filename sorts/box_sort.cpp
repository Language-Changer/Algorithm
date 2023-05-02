#include <iostream>
using namespace std;

int a[5000010];
int box[100010];

int main()
{
    int n;
    cin >> n;
    for(int i=1;i <= n;i++)
    {
        int x;
        cin >> x;
        box[x]++;
    }
    
    int cur=0;
    for(int i=1;i <= 100000;i++)
    {
        for(int j=1;j <= box[i];j++)
        {
            cur++;
            a[cur]=i;
        }
    }
    for(int i=1;i <= n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}