#include<bits/stdc++.h>

using namespace std;

#define ll long long


const int mod = 998244353;
int t;
int n;

int h[100100], nx[200200], to[200200], cnt;
ll dp[100100][3];

void add(int f, int t) {
	nx[++cnt] = h[f];
	h[f] = cnt;
	to[cnt] = t;	
}

void dfs(int loc, int fa) {
	ll pre3 = 1; // 2
	ll pre2 = 1; // 1,2
	ll pre1 = 1; // 0,1,2
	bool flag = 0;
	for(int i=h[loc]; i; i=nx[i])
		if(to[i] != fa) {
			flag = 1;
			dfs(to[i], loc);
			pre3 *= dp[to[i]][2];
			pre2 *= (dp[to[i]][2]+dp[to[i]][1])%mod;
			pre1 *= (dp[to[i]][0]+dp[to[i]][1]+dp[to[i]][2])%mod;
			pre3 %= mod;
			pre2 %= mod;
			pre1 %= mod;
		}
	if(flag == 0) {
		dp[loc][0] = 1;
		dp[loc][1] = 0;
		dp[loc][2] = 1;
	} else {
		dp[loc][0] = pre3;
		dp[loc][1] = (pre1 - pre3+mod) % mod;
		dp[loc][2] = pre2;
		dp[loc][0] %= mod;
		dp[loc][1] %= mod;
		dp[loc][2] %= mod;
	}
	return;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		cnt = 0;
		scanf("%d", &n);
		int u, v;
		for(int i=1; i<=n; i++) h[i] = 0;
		for(int i=1; i<=n; i++) dp[i][0] = dp[i][1] = dp[i][2] = 0;
		for(int i=1; i<n; i++) {
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		dfs(1, 1);
		printf("%lld\n", (dp[1][1]+dp[1][2])%mod);
	}
}
