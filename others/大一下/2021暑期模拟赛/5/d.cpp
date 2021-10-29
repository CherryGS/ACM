#include<bits/stdc++.h>
using namespace std;

#define ll long long

int t;
int n, m, q;
int bcj[200200];
int sum[200200];

struct road {
	int f, t;
	ll co;
	bool operator < (const road&a) const {
		return co > a.co;
	}
	void init() {
		scanf("%d%d%lld", &f, &t, &co);
        co = -co;
	}
}r[200200];

struct que {
	int id;
	ll k;
	ll ans;
	void init(int x) {
		id = x;
		scanf("%lld", &k);
        k = -k;
	}
}a[200200];

bool cmp1(const que&a, const que&b) {
	return a.k > b.k;
}

bool cmp2(const que&a, const que&b) {
	return a.id < b.id;
}

int fd(int x) {
	return bcj[x] == x? x: bcj[x] = fd(bcj[x]);
}

ll cacu(ll x) {
	return x*(x-1)/2;
}

int main() {
    scanf("%d%d", &n, &q);
    for(int i=1; i<n; i++) r[i].init();
    for(int i=1; i<=q; i++) a[i].init(i);
    for(int i=1; i<=n; i++) bcj[i] = i;
    for(int i=1; i<=n; i++) sum[i] = 1;
    sort(r+1, r+n);
    sort(a+1, a+1+q, cmp1);
    int l = 1;
    ll ans = 0;
    for(int i=1; i<=q; i++) {
        while(l <= n-1 && r[l].co >= a[i].k) {
            int u = fd(r[l].f);
            int v = fd(r[l].t);
            ++l;
            if(u == v) continue; 
            ans -= cacu(sum[u]) + cacu(sum[v]);
            sum[u] += sum[v];
            bcj[v] = u;
            ans += cacu(sum[u]);

        }
        a[i].ans = ans;
    }
    sort(a+1, a+1+q, cmp2);
    for(int i=1; i<=q; i++) {
        printf("%lld\n", a[i].ans);
    }
} 
/*
1
5 5 3
1 2 2
2 3 3
3 4 1
4 5 1
5 1 3
3
2
1
*/
