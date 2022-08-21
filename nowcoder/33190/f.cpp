#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define LL long long
#define pi acos(-1.0)
using namespace std;

const int MAXN = 1e3 + 10;
LL N;
double ans;
struct circle {
    double x, y;
    double r;
} c[MAXN];

struct seg {
    double l, r;
} s[MAXN * 5];
double thita1, thita2;
inline LL read()
{
    LL x = 0, w = 1; char ch = 0;
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            w = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * w;
}

double dis(int i, int j)
{
    return sqrt((c[i].y - c[j].y) * (c[i].y - c[j].y) + (c[i].x - c[j].x) * (c[i].x - c[j].x));
}

bool con(int i, int j, double d)
{
    if(d + c[i].r <= c[j].r) {
        return true;
    }
    return false;
}

bool cmp(seg a, seg b)
{
    if(a.l == b.l) {
        return a.r >= b.r;
    }
    return a.l < b.l;
}

void cal(int i)
{
    int tot = 0;
    for(int j = i + 1; j <= N; j++) {
        double d = dis(i, j);
        if(con(i, j, d)) {
            return;
        }
        double l, r;
//        cout<<d<<endl;
        if(d <= c[i].r + c[j].r && !con(j, i, d)) {
            thita1 = atan2(c[j].y - c[i].y, c[j].x - c[i].x);
            thita2 = acos((d * d + c[i].r * c[i].r - c[j].r * c[j].r) / (2 * d * c[i].r));
    //    cout<<thita1<<" "<<thita2<<endl;
            l = thita1 - thita2, r = thita1 + thita2;
        //    printf("%.3lf %.3lf\n", l, r);
            if(l < 0) {
                l = l + 2 * pi;
            }
            if(r < 0) {
                r = r + 2 * pi;
            }
            if(l > r) {
                s[tot].l = l;
                s[tot++].r = 2 * pi;
                s[tot].l = 0;
                s[tot++].r = r;
            } else {
                s[tot].l = l;
                s[tot++].r = r;
            }
        }
    }
    sort(s, s + tot, cmp);
    double len = 0, cnt = 0;
    for(int j = 0; j < tot; j++) {
//        cout<<s[j].l<<" "<<s[j].r<<endl;
        if(s[j].l > cnt) {
            len += s[j].l - cnt;
        }
        cnt = max(cnt, s[j].r);
    }
    len += 2 * pi - cnt;
    ans += len * c[i].r;
    //cout<<len<<endl;
}
int main()
{
    N = read();
    for(int i = 1; i <= N; i++) {
        scanf("%lf%lf%lf", &c[i].x, &c[i].y, &c[i].r);
    }
    for(int i = 1; i <= N; i++) {
        cal(i);
    }
    printf("%.6lf\n", ans);
    return 0;
}

/*

2

1 0 0

1 1 0
*/