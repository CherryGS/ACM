//By zuiyumeng  
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...); }
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl

#define _mp make_pair
typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;

#define Ms(a,b) memset((a),(b),sizeof(a))
#define Fo(i,a,b) for(LL i=(a),_=(b);i<=_;i++)
#define Ro(i,a,b) for(LL i=(b),_=(a);i>=_;i--)

#define pc putchar
#define nxtline() pc('\n')
void pot(LL x) { if (!x)return;pot(x / 10ll);pc('0' + x % 10ll); }
void out(LL x) { if (!x)pc('0');if (x < 0ll)pc('-'), x = -x;pot(x); }

// #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin)),p1==p2?EOF:*p1++)
// char buf[1<<21],*p1,*p2;
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}
const int N = 1e6 + 10;
typedef long long ll;
int a[N];
int b1[N], b2[N], b[N];
int pos, nb;
map<int, int> mp;
int main() {
	// freopen("my.in", "r", stdin);
	// freopen("my.txt", "w", stdout);
	// ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		mp.clear();
		ll n, d;int flag = 0;
		int pos1 = -0x3f3f3f3f, pos2 = -0x3f3f3f3f, nb1 = 0, nb2 = 0;
		cin >> n >> d;
		for (int i = 1;i <= n;i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		for (int i = 1;i <= n;i++) {
			if (mp[a[i]] == 1) {
				flag = 1;break;//这就是我们没有考虑到的情况，如果x只出现一次
				//那么按照顺序输出
			}
		}
		sort(a + 1, a + n + 1);
		if (d == 1 || flag == 1) {
			for (int i = 1;i <= n;i++)cout << a[i] << ' ';
			cout << endl;
			continue;
		}
		if (d >= n) {
			cout << -1 << endl;
			continue;
		}
		for (int i = n;i > 0;) {
			//cout<<i<<endl; // 尾 
			ll num = mp[a[i]];

			ll cha = (1ll * num - 1ll) * (1ll * d - 1ll) - (1ll * n - 1ll * i);//所需长度和已给长度的比较
			if (cha <= 0) {//后面够

				if (pos1 < (i - num + 1)) {
					pos1 = i - num + 1;
					nb1 = a[i];

				}
			}
			else {//后面不够 
				int head = i - num + 1;
				if (pos2 <= (head - cha) && (head > cha)) {
					pos2 = head - cha;//放头位置 
					nb2 = a[i];
				}
			}
			i -= num;
		}
		if (pos1 < 1 && pos2 < 1) {
			cout << "-1" << endl;
			continue;
		}
		if (pos1 > 0) {
			int num = mp[nb1], pos = pos1;int j = 1, cnt = 0;
			for (int i = 1;i <= n;i++) {
				if (a[j] == nb1) {
					j += num;
				}
				if (i == pos && cnt < num) {
					b1[i] = nb1;
					pos += d;cnt++;
				}
				else {
					b1[i] = a[j++];
				}
			}
		}
		if (pos2 > 0) {
			int num = mp[nb2], pos = pos2;int j = 1, cnt = 0;
			for (int i = 1;i <= n;i++) {
				if (a[j] == nb2) {
					j += num;
				}
				if (i == pos && cnt < num) {
					b2[i] = nb2;
					pos += d;cnt++;
				}
				else {
					b2[i] = a[j++];
				}
			}
		}
		if (pos1 < 1)
			for (int i = 1;i <= n;i++) {
				cout << b2[i] << ' ';
			}
		else if (pos2 < 1)
			for (int i = 1;i <= n;i++) {
				cout << b1[i] << ' ';
			}
		else {
			int f = 0;
			for (int i = 1;i <= n;i++) {
				if (b1[i] != b2[i]) {
					if (b1[i] > b2[i])f = 2;
					else f = 1;
					break;
				}
			}
			if (f == 1) {
				for (int i = 1;i <= n;i++) {
					cout << b1[i] << " ";
				}
			}
			else {
				for (int i = 1;i <= n;i++) {
					cout << b2[i] << " ";
				}
			}
		}
		cout << endl;
	}
	return 0;
}