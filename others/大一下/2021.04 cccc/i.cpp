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

int n, m, s;
string ans;
char l[101][1001];
int cnt[101];
char sta[101];
int ct;

int main() {
    cin >> n >> m >> s;
    for(int i=1; i<=n; i++) {
        cin >> l[i];
    }
    while(1) {
        int x;
        cin >> x;
        if(x == -1) break;
        if(x == 0 && ct) { ans += sta[ct]; --ct; }
        if(x != 0 && cnt[x] != m) {
            if(ct == s) { ans += sta[ct]; --ct; }
            ++cnt[x];
            sta[++ct] = l[x][cnt[x]-1];
        }
        // cout << ans << ' ' << x << ' ' << cnt[x] << endl;
    }
    cout << ans << endl;
    return 0;
}