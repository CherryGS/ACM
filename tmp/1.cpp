#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1e5 + 5;

int s[N],c[N];
int n, k;
double b[N];

bool check(double x)
{
    for (int i = 1; i <= n; i ++)
        b[i] = s[i] * c[i] - x * s[i];
    sort(b + 1, b + n + 1);
    double sum = 0;
    for (int i = k + 1; i <= n; i ++)
        sum += b[i];
    return sum >= 0;
}
int main()
{
    cin >> n >> k;
    
    for (int i = 1; i <= n; i ++)
        cin >> s[i];
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    
    double l = 0, r = 1000;
    while (r - l > 1e-6)
    {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%0.5lf", r);
    return 0;
}