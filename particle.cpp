#include <iostream>
using namespace std;

int tar[5];

bool dfs(int a, int b, int c, int type, int depth)
{
    // Test
    // cerr << a << ' ' << b << ' ' << c << ' ' << type << ' ' << depth << endl;

    // Out of limit
    if (a < 0 || b < 0 || c < 0) return 0;
    if (depth > (tar[1]+tar[2]+tar[3])) return 0;
    // if (type == 1 && (a > tar[1] || b > tar[2] || c > tar[3])) return 0;
    // if (type == 3 && b + 1 > tar[2]) return 0;

    // True way
    if (a == tar[1] && b == tar[2] && c == tar[3])
    {
        cout << "Totally " << depth-1 << ':' << endl;
        return 1;
    }

    // DFS
    if (dfs(a-1, b+1, c+1, 1, depth+1))
    {
        cout << "B and C becomes A;" << endl;
        return 1;
    }
    else if(dfs(a+1,b+1,c-1, 1,depth+1))
    {
        cout << "A and B becomes C;" << endl;
        return 1;
    }
    else if(dfs(a+1,b-1,c+1, 1,depth+1))
    {
        cout << "A and C becomes B;" << endl;
        return 1;
    }
    else if(dfs(a+2,b-1,c, 2,depth+1))
    {
        cout << "A and A becomes B;" << endl;
        return 1;
    }
    else if(dfs(a,b+1,c, 3,depth+1))
    {
        cout << "B and B becomes B;" << endl;
        return 1;
    }
    else if(dfs(a,b-1,c+2, 2,depth+1))
    {
        cout << "C and C becomes B;" << endl;
        return 1;
    }
    return 0;
}

int main()
{
    for (int i=1;i <= 3;i++) cin >> tar[i];
    int rem;
    cin >> rem;
    if (!dfs(1*(rem==1), 1*(rem==2), 1*(rem==3), 0, 1)) cout << "None!" << endl;
    return 0;
}