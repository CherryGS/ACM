#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ls (loc<<1)
#define rs ((loc<<1)|1)
#define cint const int&
const int inf_int = 0x3f3f3f3f;

int node[100100<<4];
int laz[100100<<4];

void build(cint l, cint r, cint loc) {
	if(l == r) {
		node[loc] = inf_int;
		laz[loc] = inf_int;
		return;
	}
	laz[loc] = inf_int;
	int mid = (l+r) >> 1;
	build(l, mid, ls);
	build(mid+1, r, rs);
	node[loc] = min(node[ls], node[rs]);
}

void push(cint loc) {
	laz[ls] = min(laz[ls], laz[loc]);
	laz[rs] = min(laz[rs], laz[loc]);
	node[ls] = min(node[ls], laz[loc]);
	node[rs] = min(node[rs], laz[loc]);
	laz[loc] = inf_int;
}

void update(cint l, cint r, cint dl, cint dr, cint loc, cint co) {
	if(l > r) return;
	if(dl <= l && dr >= r) {
		node[loc] = min(node[loc], co);
		laz[loc] = min(laz[loc], co);
		return;
	}
	if(laz[loc] < inf_int) push(loc);
	int mid = (l+r) >> 1;
	if(dl <= mid) update(l, mid, dl, dr, ls, co);
	if(dr >= mid+1) update(mid+1, r, dl, dr, rs, co);
	node[loc] = min(node[ls], node[rs]);
}

int query(cint l, cint r, cint ds, cint loc) {
	if(l>r) return -1;
	if(l == r) return node[loc];
	int mid = (l+r) >> 1;
	int ans;
	if(laz[loc] < inf_int) push(loc);
	if(ds <= mid) ans = query(l, mid, ds, ls);
	else ans = query(mid+1, r, ds, rs);
	node[loc] = min(node[ls], node[rs]);
	return ans;
}

ll cacu(ll x) {
	if(!x) return 0;
	return (x*(x-1)) / 2;
}

int main()
{
	int T;
	scanf("%d", &T);	
	int id = 0;
	while(T--) {
		++id;
		int n,m;
		scanf("%d%d", &n, &m);
		int l, r, w;
		ll ans = 0;
		build(1, n-1, 1);
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d", &l, &r, &w);	
			ans += cacu(r-l+1) * w;
			update(1, n-1, l, r-1, 1, w);
		}
		ll rss = 0;
		bool flag = 0;
		for(int i=1; i<n; i++) {
			int rr = query(1, n-1, i, 1);
			if(rr >= inf_int) {
				flag = 1;
				break;
			}
			rss += rr;
		}
		printf("Case #%d: ", id);
 		if(flag) printf("Gotta prepare a lesson");
		else printf("%lld", ans -rss);
		if(T) putchar('\n');
	}
	return 0;	
}
