#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
int a[300300];
bool mp[300300];
int st[300300][20];
int lg[101];

void pre() {
    lg[1] = 0;
    lg[2] = 1;
    for(int i=3; i < 20; i++) lg[i] = lg[i/2] + 1;
}

bool check(cint x) {
    int sum=0;
    int r = lg[x];
    for(int i=1; i<=n-x+1; i++) mp[i] = 0;
    for(int i=1; i+x-1<=n; i++) {
        int mx = min(st[i][r], st[i+x-(1<<r)][r]) ;
        if(mx > n-x+1) return 0;
        if(!mp[mx]) {
            mp[mx]=1;
            ++sum;
        }
    }
    if(sum == n-x+1) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    pre();
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i], st[i][0] = a[i];
        for(int j=1; j<20; j++)
            for(int i=1; i+(1<<j)-1 <= n; i++) {
                st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
            }

        int l=2, r=n+1, mid;
        while(l<=r) {
            mid = (l+r) >> 1;
            if(check(mid)) r = mid-1;
            else l = mid+1;
        }
        if(!check(l)) ++l;
        cout << check(1);
        for(int i=2; i<=n; i++)
            if(i<l) cout << '0';
            else cout << '1';
        cout << endl;
    }
    return 0;
}