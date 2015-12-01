#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;
LL x,y,t;
bool check()
{
    for (y=2;y*y<=x;++y)
        if (x%y == 0)
            return false;
    return true;
}
int main()
{
    int i,n;
    srand((unsigned)time(NULL));
    cin >> n;
    if (n)  cin >> t;
    else  t=0LL;
    do
    {
        for (x=t,i=n+1;i<=12;++i)
            x=(x<<1)+(x<<3)+(LL)((rand()&15)%10);
    }while (!check());
    cout.width(12);
    cout.fill('0');
    cout << x << endl;
    return 0;
}
//by