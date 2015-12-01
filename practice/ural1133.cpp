#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
int main()
{
    int a1, fi, a2, fj, n;
    scanf( "%d%d%d%d%d",&a1,&fi,&a2,&fj,&n);
    if (a2 < a1)
    {
        int temp;
        temp = a1; a1 = a2; a2 = temp;
        temp = fi; fi = fj; fj = temp;
    }
    LL a, b, c, left, right, mid;
    left = -3000000000LL; right = 3000000000LL;
    while (left +1< right)
    {
        mid = (left + right) / 2;
        a= fi; b = mid;
        for (int i = a1 + 2;i <= a2;i++)
        {
            c = a + b;
            a = b;
            b = c;
            if (c > 8000000000LL || c < -8000000000LL) break;
        }
        if (b < fj) left = mid;
        else if(b == fi)
                {
                     right=mid;
                     break;
                 }
        else right = mid;
    }
    LL ans = right;
    a = fi; b = ans;
    if (n >= a1 + 1)
    {
        for (int i = a1 + 2;i <= n;i++)
        {
            c = a+ b;
            a = b;
            b = c;
        }
        cout << b << endl;
    }
    else
    {
        for (int i = a1 - 1;i >= n;i--)
        {
            c = b - a;
            b = a;
            a = c;
        }
        cout << a << endl;
    }
}