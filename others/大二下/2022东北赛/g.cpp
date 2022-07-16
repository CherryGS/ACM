#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

struct node {
    ll t;
    int num, val;
};

int n, m, t1, t2;
int a[1000100];
int cnt;

inline int get_tp(int tp, int t) {
    tp -= t;
    int k = t2 - t1 + 1;
    tp=(((tp-t1)%k)+k)%k;
    return tp+t1;
}
int rdi(){
   int s=0;
   int ff=1;
   char w=getchar();
   while(!isdigit(w)) 
    ff^=w=='-',w=getchar();
    while(isdigit(w))
        s=s*10+w-'0',w=getchar();
    return ff?s:-s;
}
ll rdl(){
   ll s=0;
   int ff=1;
   char w=getchar();
   while(!isdigit(w)) 
    ff^=w=='-',w=getchar();
    while(isdigit(w))
        s=s*10+w-'0',w=getchar();
    return ff?s:-s;
}
int main() {
    freopen("1.in", "r", stdin);
    n = rdi(), m = rdi(), t1 = rdi(), t2 = rdi();
    for(int i=1; i<=n; i++) { a[i] = rdi(); }
    queue<node> q;
    for(int i=n; i>=1; i--) { q.push({0, 1, a[i]}); }
    int t, k;
    ll now = 0;
    for(int i=1; i<=m; i++) {
        t = rdi(), k = rdi();
        now += t;
        ll ans = 0;
        int kk = k;
        while(!q.empty() && k) {
            auto &r = q.front();
            int rs = min(k, r.num);
            int tp = get_tp(r.val, now - r.t);
            // if(i == 2) { cout << r.t << ' ' << r.num << ' ' << r.val << ' ' << tp << endl; }
            r.num -= rs;
            k -= rs;
            ans += 1ll * rs * tp;
            if(r.num == 0) { q.pop(); }
        }
        if(k) {
            ans += 1ll*k*t2;
        }
        q.push({now, min(kk, n), t2});
        // cout << " --- ";
        cout << ans << '\n';
    }
}