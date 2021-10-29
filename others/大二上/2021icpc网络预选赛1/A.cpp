#include <bits/stdc++.h>
using namespace std;

#define LL long long
LL k, n;

struct stu { 
	LL id, tim, las; 
	bool operator < (const stu&a) const { return tim == a.tim ? id < a.id : tim < a.tim; } 
	void init(LL x) {
		id = x;
		cin >> tim >> las;
	}
};

stu val[100100];

#define ls (loc<<1)
#define rs ((loc<<1)|1)
LL node[100100<<3];

LL query(LL l, LL r, LL dl, LL dr, LL loc, LL co) {
	if(l > r) return -1;
	if(l == r) return l;
	LL mid = (l+r) >> 1;
	LL n1 = -1, n2 = -1;
	if(dl <= mid && node[ls] <= co) n1 = query(l, mid, dl, dr, ls, co);
	if(n1 == -1 && dr >= mid+1 && node[rs] <= co) n2 = query(mid+1, r, dl, dr, rs, co);
	if(n1 == -1) return n2;
	return n1;
}

void update(LL l, LL r, LL ds, LL loc, LL co) {
	if(l > r) return;
	if(l == r) {
		node[loc] = co;
		return;
	}
	LL mid = (l+r) >> 1;
	if(ds <= mid) update(l, mid, ds, ls, co);
	else update(mid+1, r, ds, rs, co);
	node[loc] = min(node[ls], node[rs]);
}

LL ans[100100];

int main() {
	ios::sync_with_stdio(false);
	cin >> k >> n;
	for(LL i=0; i<n; i++) {
		val[i].init(i);
	}
	sort(val, val+n);
	for(LL i=0; i<n; i++) {
		LL n1 = -1, n2 = -1;
		n1 = query(0, k-1, i%k, k-1, 1, val[i].tim);
		if(n1 != -1) {
			ans[n1]++;
			update(0, k-1, n1, 1, val[i].tim + val[i].las);
		}
		else {
			n2 = query(0, k-1, 0, i%k-1, 1, val[i].tim);
			if(n2 != -1) {
				ans[n2]++;
				update(0, k-1, n2, 1, val[i].tim + val[i].las);
			}
		}
//		cout << i << ' ' << n1 << ' ' << n2 << endl;
	}
	LL mx = 0, mxid=1;
	for(LL i=0; i<=k-1; i++) {
//		cout << ans[i] << ' ';
		if(ans[i] > mx) {
			mx = ans[i];
			mxid = i;
		}
	}
	bool flag = 0;
	for (LL i = 0; i < k; ++ i){
		if (ans[i] == mx) { 
			if(!flag) flag = 1;
			else putchar(' ');
			printf("%lld", i);
		}
	}
	return 0;
}
/*
3 5
1 5
2 2
3 4
4 3
6 3
*/
