#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int n, m, k;
bool mp[202][202];
int val[202][202];
int sc[202][202][2];
int dp[202][202];

void debug() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cout << val[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	for(int j=1; j<=m; j++) {
		for(int i=0; i<=k; i++)
			cout << sc[j][i][0] << ' ';
			cout << endl;
	}
	cout << endl;
	for(int j=1; j<=m; j++) {
		for(int i=0; i<=k; i++)
			cout << sc[j][i][1] << ' ';
			cout << endl;
	}
	cout << endl;
}

int main() {
	cin >> t;
	while(t--) {
		cin >> n >> m >> k;
		char ch;
		int in;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				mp[n+1][j] = 1;
				cin >> in >> ch;
				val[i][j] = in;
				if(ch == 'Y') mp[i][j] = 1;
				else mp[i][j] = 0;
			}
		}
		for(int j=1; j<=m; j++) {
			int rt = 0;
			for(int i=n; i>=1; i--) {
				if(mp[i][j]) {
					sc[j][rt][1] = val[i][j] + (mp[i+1][j] ? sc[j][rt][1] : sc[j][rt-1][0]);
				} else {
					++rt;
					sc[j][rt][0] = val[i][j] + (mp[i+1][j] ? sc[j][rt-1][1] : sc[j][rt-1][0]);
				}
			}
		}
		debug();
		for(int j=1; j<=m; j++) {
			for(int i=0; i<=k; i++) {
				for(int l=i; l>=0; l--) {
					dp[j][i] = max(dp[j][i], dp[j-1][i-l] + sc[j][l][0]);
					if(l != k) dp[j][i] = max(dp[j][i], dp[j-1][i-l] + sc[j][l][1]);
				}
				dp[j][i] = max(dp[j][i], dp[j-1][i]);
			}
		}
		cout << dp[1][1] << endl;
		cout << dp[m][k] << endl;
	}	
	return 0;
}