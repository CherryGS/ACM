#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ls (loc<<1)
#define rs ((loc<<1)|1)
#define cint const int&
const int inf_int = 0x3f3f3f3f;

multiset<int> e;
vector<int> q[2][100100];

inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	T = read();	
	int id = 0;
	while(T--) {
		++id;
		int n,m;
		n = read(), m = read();
		for(int i=1; i<=n; i++) q[0][i].clear(), q[1][i].clear();
		int l, r, w;
		ll ans = 0;
		for(int i=1; i<=m; i++) {
			l = read(), r = read(), w = read();
			ans += (ll)(r-l+1) * (ll)(r-l) / 2ll * (ll)w;
			q[0][l].push_back(w);
			q[1][r].push_back(w);
		}
		e.clear();
		ll rss = 0;
		bool flag = 0;
		for(int i=1; i<n; i++) {
			for(int k: q[0][i]) {
				e.insert(k);
			}
			for(int k: q[1][i]) {
				e.erase(e.find(k));
			}
			if(e.size() == 0) {
				flag = 1;
				break;
			}
			rss += *e.begin();
		}
		cout << "Case #"<< id << ": ";
 		if(flag) cout << "Gotta prepare a lesson";
		else cout << ans - rss;
		if(T) cout << '\n';
	}
	return 0;	
}
