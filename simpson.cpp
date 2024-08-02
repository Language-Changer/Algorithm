#include <iostream>
using namespace std;

double a,b,c,d;
const double esp = 1e-10;
const int depth = 20;

double f(double x)
{
    return (c*x + d) / (a*x + b);
}

double simpson(double l, double r)
{
    return (r-l) / 6*(f(r) + f(l) + 4*f((l + r)/2));
}

double asr(double l, double r, double ans, int step)
{
    double mid = (l + r) / 2;
    double funl = simpson(l, mid);
    double funr = simpson(mid, r);
    if (abs(funl + funr - ans) <= esp && step >= depth)
        return funl + funr;
    return asr(l, mid, funl, step+1) + asr(mid, r, funr, step+1);
}

signed main()
{
    double l,r;
    cin >> a >> b >> c >> d;
    cin >> l >> r;
    printf("%0.15f\n", asr(l, r, simpson(l, r), 1));
    return 0;
}