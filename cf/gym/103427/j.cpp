#include <bits/stdc++.h>

using namespace std;

int t;
char a[4], b[4];
int r[4];

int dfs(int step, int x) {
	if(step == 4) return 0;
	int ans = 1000;
    for(int i=0; i<10; i++) {
        r[step] = (r[step] + i) % 10;
        int s1 = min(r[step], max(0, r[step]+x));
        int s2 = min(10-r[step], max(0, 10-r[step]-x));
    //	cout << s1 << " ---- " << s2 << ' ' << x << endl;
        ans = min(ans, dfs(step+1, -r[step]) + s1 + i);
        ans = min(ans, dfs(step+1, 10-r[step]) + s2 + i);
        r[step] = (r[step] - i + 10) % 10;
    }
	return ans;
}

int main() {
//	freopen("1.in", "r", stdin);
	cin >> t;
	while(t--) {
		for(int i=0; i<4; i++) cin >> a[i];
		for(int i=0; i<4; i++) cin >> b[i];
		for(int i=0; i<4; i++) r[i] = (b[i] - a[i] + 10) % 10;
//		for(int i=0; i<4; i++) cout << r[i] << ' ';
//		cout << endl;
		cout << dfs(0, 0) << endl;
	}
}
/*
1
2 6 0 5
*/