#include<time.h>
#include<stdlib.h>
#include<fstream>
#include<iostream>
#define int long long

signed main()
{
    int num,MAX_VALUE;
    std::cin >> num >> MAX_VALUE;
    srand(time(0));
    std::ofstream outfile;
    outfile.open("number.out");
    outfile << num << std::endl;
    for(int i=1;i <= num;i++)
    {
        outfile << rand() % (MAX_VALUE + 1) << ' ';
    }
    outfile.close();
    return 0;
}
