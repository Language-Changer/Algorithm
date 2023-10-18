#include<iostream>
#define int long long
const int N = 1e5+10;

signed main(void)
{
    int n;
    double avg = 0, S = 0;
    std::cin >> n;
    for(int i=0;i < n;i++)
    {
        double x;
        std::cin >> x;
        avg += x;
        S += x * x;
    }
    avg /= n;
    S -= n * avg * avg;
    S /= n;
    printf("%f\n",S);
    return 0;
}
