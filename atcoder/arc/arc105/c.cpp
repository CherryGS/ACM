#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&

int n, m;
int w[10];
int mx[100001][20];
bool mp[10];
int cnt;
int res[10];
int to[20];
int aaa = 0x7fffffff;

struct br {
    int len, wei;
    bool operator < (const br & a) const {
        return wei < a.wei;
    }
} a[1000100];

int binary_ca(cint st) {
    int mid, l = 1, r = m;
    while(l < r) {
        mid = (l+r) >> 1;
        if(a[mid].wei >= st) r = mid;
        else l = mid + 1;
    }
    int key = 0;
    for(int i = 17; i; i--)
        if(to[i] <= mid) {
            key = i;
            break;
        }
    cout << mid << " -- " << key << " -- " << to[key] << endl;
    cout << mx[1][key] << " --- " << mx[mid - to[key] + 1][key] << endl;
    return max(mx[1][key], mx[mid - to[key] + 1][key]);
}

void cacul() {
    int ans = 0;
    // for(int i = n; i >= 1; i--) cout << "--" << w[res[i]] << endl;
    for(int i = n; i > 1; i--) {
        ans += binary_ca(w[res[i]] + w[res[i-1]]);
    }
    aaa = min(ans, aaa);
}

void dfs() {
    if(cnt == n) {
        cacul();
    }
    for(int i = 1; i <= n; i++)
        if(!mp[i]) {
            mp[i] = 1;
            res[++cnt] = i;
            dfs();
            --cnt;
            mp[i] = 0;
        }
    return;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= m; i++) cin >> a[i].len >> a[i].wei;
    sort(a+1, a+1+m);
    to[0] = 1;
    for(int i = 1; i <= 17; i++) to[i] = to[i-1] << 1;
    for(int i = 1; i <= m; i++) mx[i][0] = a[i].wei;
    for(int i = 1; i <= 17; i++)
        for(int j = 1; j <= m; j++) 
            mx[j][i] = max(mx[j][i-1], mx[j+to[i-1]][i-1]);
    for(int i = 1; i <= n; i++) {
        mp[i] = 1;
        res[++cnt] = i;
        dfs();
        mp[i] = 0;
    }
    cout << aaa;
    return 0;
}