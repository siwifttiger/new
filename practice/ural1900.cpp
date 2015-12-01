#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 500 + 10;

int n, k, num[MAXN][MAXN];
int sum[MAXN][MAXN], dp[MAXN][MAXN];
int top, stack[MAXN], prev[MAXN][MAXN];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = n; j > i; --j)
        {
            sum[i][j] = num[i][j] + sum[i - 1][j] + sum[i][j + 1] - sum[i - 1][j + 1];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            for (int l = 0; l < i; ++l)
            {
                int temp = dp[l][j - 1] + sum[i][i + 1] - sum[l][i + 1];
                if (temp >= dp[i][j])
                {
                    dp[i][j] = temp;
                    prev[i][j] = l;
                }
            }
        }
    }
    int index = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (dp[i][k] > dp[index][k])
        {
            index = i;
        }
    }
    int ans = dp[index][k];
    for (int i = k; i >= 1; --i)
    {
        stack[top++] = index;
        index = prev[index][i];
    }
    printf("%d\n", ans);
    for (int i = k - 1; i >= 0; --i)
    {
        if (i < k - 1)
        {
            putchar(' ');
        }
        printf("%d", stack[i]);
    }
    putchar('\n');
    return 0;
}
