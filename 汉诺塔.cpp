#include<fstream>
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

//nn:几层。
//cnt:进行几次操作。
long long nn,cnt;

void dfs(int n,string a,string b,string c)
{
    if(n == 1)
    {
        //cnt++;
        cout << "From " << a << " to " << c << '.' << endl;
        return;
    }
    dfs(n-1,a,c,b);
    dfs(1,a,b,c);
    dfs(n-1,b,a,c);
}

int main()
{
    cin >> nn;
    dfs(nn,"the first pole","the second pole","the third pole");
    //cout << cnt;
}
