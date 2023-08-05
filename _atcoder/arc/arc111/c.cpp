#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int a[200200], b[200200], p[200200];
struct node {
    int id, val;
    void init(cint x, cint y) {
        id = x; val = y;
    }
    bool operator < (const node&a) const {
        return val < a.val;
    }
} s[200200];

int idt[200200];
int ans[200200][2], cnt;
int nx[200200], la[200200];

void cut(cint loc) {
    la[nx[loc]] = la[loc];
    nx[la[loc]] = nx[loc];
}

void NO() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    bool flag = 0;
    cin >> n;
    for(int i=1; i<=n; i++) {cin >> a[i];}
    for(int i=1; i<=n; i++) {cin >> b[i];}
    for(int i=1; i<=n; i++) {cin >> p[i];}
    for(int i=1; i<=n; i++) {if(a[i] <= b[p[i]] && i != p[i]) flag = 1;}
    if(flag) NO();
    for(int i=1; i<=n; i++) s[i].init(i, a[i]);
    sort(s+1, s+1+n);
    for(int i=1; i<=n; i++) idt[s[i].id] = i;
    nx[0] = 1; la[n+1] = n;
    for(int i=1; i<=n; i++) nx[i] = i+1, la[i] = i-1;
    while(la[n+1] != 0) {
        flag = 1;
        int r = la[n+1];
        if(p[s[r].id] == s[r].id) cut(r);
        else {
            // cout << "r : " << r << endl << s[r].id << ' ' << s[r].val << endl;
            int my = p[s[r].id];
            cut(idt[my]);
            ans[++cnt][0] = s[r].id;
            ans[cnt][1] = my;
            swap(p[s[r].id], p[my]);
            if(p[my] == s[r].id) cut(r);
        }
    }
    cout << cnt << endl;
    for(int i=1; i<=cnt; i++)
        cout << ans[i][0] << ' ' << ans[i][1] << endl;

    return 0;
}