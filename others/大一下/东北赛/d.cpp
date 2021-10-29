#include <bits/stdc++.h>

using namespace std;
#define lson (loc<<1)
#define rson ((loc<<1)|1)
#define ll long long
#define cint const int&

const int mod = 998244353;
int t;
int n, m;
ll a[100100];

bool isok[100100<<5];
ll node[100100<<5];
int num[100100<<5];	

ll lowbit(ll x) { return x&-x; }

bool check(ll x) {
	return x == lowbit(x);
}

void build(cint l, cint r, cint loc) {
	if(l == r) {
		node[loc] = a[l];
		isok[loc] = check(a[l]);
		return ;
	}
	int mid = (l+r) >> 1;
	num[loc] = 0;
	build(l, mid, lson);
	build(mid+1, r, rson);
	isok[loc] = (isok[lson] && isok[rson]);
	node[loc] = (node[lson] + node[rson]) % mod;
} 

ll ksm(ll bs, ll x) {
	ll ans = 1;
	while(x) {
		if(x&1) ans = (ans*bs) % mod;
		bs = (bs*bs) % mod;
		x >>= 1;
	}
	return ans;
}

void push(cint loc) {
	num[lson] += num[loc];
	num[rson] += num[loc];
	ll s = ksm(2, num[loc]);
	node[lson] = ( node[lson] * s ) % mod;
	node[rson] = ( node[rson] * s ) % mod;
	num[loc] = 0;
}

void update(cint l, cint r, cint dl, cint dr, cint loc) {
	int mid = (l+r) >> 1;
	if(dl <= l && dr >= r) {
		if(!isok[loc]) {
			if(l == r) {
				node[loc] = node[loc] + lowbit(node[loc]);
				if(check(node[loc])) isok[loc] = 1;
				return;
			}
			if(!isok[lson]) update(l, mid, dl, dr, lson);
			else {
				node[lson] = (node[lson]*2) % mod;
				num[lson]++;
			}
			if(!isok[rson]) update(mid+1, r, dl, dr, rson);
			else {
				node[rson] = (node[rson]*2) % mod;
				num[rson]++;
			}
			isok[loc] = (isok[lson] && isok[rson]);
			node[loc] = (node[lson] + node[rson]) % mod;
		} else {
			node[loc] = (node[loc]*2) % mod;
			num[loc]++;
		}
		return;
	}
	if(num[loc]) push(loc);
	if(dl <= mid) update(l, mid, dl, dr, lson);
	if(dr >= mid+1) update(mid+1, r, dl, dr, rson);	
	node[loc] = (node[lson] + node[rson]) % mod;
	isok[loc] = (isok[lson] && isok[rson]);
}

ll query(cint l, cint r, cint dl, cint dr, cint loc) {
	if(l >= dl && r <= dr) {
		return node[loc];
	}
	if(num[loc]) push(loc);
	int mid = (l+r) >> 1;
	ll sum = 0;
	if(dl <= mid) sum += query(l, mid, dl, dr, lson);
	if(dr >= mid+1) sum += query(mid+1, r, dl, dr, rson);
	node[loc] = (node[lson] + node[rson]) % mod;
	return sum % mod;  
}

void debug() {
	for(int i=1; i<=n; i++)
		cout << query(1, n, i, i, 1) << ' ';
		cout << endl;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		build(1, n, 1);
		scanf("%d", &m);
		int opt, l, r;
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d", &opt, &l, &r);
			if(opt == 1) {
				update(1, n, l, r, 1);
//				debug();
			} else {
				printf("%lld\n", query(1, n, l, r, 1));
			}
		}
	}	
} 
/*
1
10
4 3 5 7 2 9 8 5 4 1 
4 
1 4 7
2 4 8
1 4 8
2 3 6
*/
