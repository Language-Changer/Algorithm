#include<fstream>
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

long long nn,cnt;

void dfs(int n,string a,string b,string c)
{
    //cnt++;
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