#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int n = 0, t = 0;
int a[200200], b[200200];
int r1 = 0, r2 = 0;
int ans = 0;
int st = 0;
// a -> r1 < 0
// b -> r2 > 0

int check1(int s)
{
    int l = 1, r = r2, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (b[mid] > s)
            r = mid - 1;
        else
            l = mid + 1;
    }

    if (b[r] > s)
        return 0;
    return r;
}

int check2(int s)
{
    int l = 1, r = r1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (a[mid] < s)
            l = mid + 1;
        else
            r = mid - 1;
    }

    if (abs(a[l]) > abs(s)) return 0;
    return l;
}

int main()
{
    int f;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> f;
        if (f < 0)
            a[++r1] = f;
        else if (f > 0)
            b[++r2] = f;
        else
            st++;
    }

    for (int i = 1; i <= r1; i++)
        if (abs(a[i]) <= t)
            ans = max(ans, r1 - i + 1);

    for (int i = 1; i <= r2; i++)
        if (b[i] <= t)
            ans = max(ans, i);

    //枚举小于0
    if (r2 && r1)
        for (int i = 1; i <= r1; i++)
        {
            int x = t + 2 * a[i];
            if (x >= b[1])
            {
                int e = check1(x);
                if (e)
                    ans = max(ans, r1 - i + 1 + e);
            }
        }

    //枚举大于0
    if (r2 && r1)
        for (int i = 1; i <= r2; i++)
        {
            int x = t - 2 * b[i];
            if (x >= abs(a[r1]))
            {
                int e = check2(-x);
                if (e)
                    ans = max(ans, i + r1 - e + 1);
            }
        }

    cout << ans + st;
    return 0;
}