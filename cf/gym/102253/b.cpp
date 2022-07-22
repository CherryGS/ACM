#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef const ll& cll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int sum[26][101100];
string s[100100];
int val[26];
bool vis[26];

bool cmp(cint x, cint y) {
    for(int i=100100; i>=0; i--) {
        if(sum[x][i] != sum[y][i]) { return sum[x][i] < sum[y][i]; }
    }
    return false;
}

void solve(cint T) {
    n = 0;
    cin >> n;
    if(n == 0) { return; }
    memset(sum, 0, sizeof sum);
    memset(vis, 0, sizeof vis);
    for(int i=1; i<=n; i++) { cin >> s[i]; }
    for(int i=1; i<=n; i++) {
        vis[s[i][0]-'a'] = 1;
        int le = s[i].size();
        for(int j=0; j<le; j++) {
            ++sum[s[i][le-j-1]-'a'][j];
        }
    }
    for(int i=0; i<26; i++) {
        for(int j=0; j<=100100; j++) {
            sum[i][j+1] += sum[i][j] / 26;
            sum[i][j] %= 26;
        }
    }
    vector<int> id;
    for(int i=0; i<26; i++) { id.push_back(i); }
    sort(id.begin(), id.end(), cmp);

    for(int i=0; i<26; i++) { val[id[i]] = i; }
    if(vis[id[0]] == 1) {
        for(int i=0; i<26; i++) {
            if(vis[id[i]] == 0) { 
                for(int j=0; j<i; j++) {
                    val[id[j]] = val[id[j+1]];
                }
                val[id[i]] = 0;
                break;
            }
        }
    }

    ll ans = 0, p = 1;
    for(int j=0; j<=100100; j++) {
        for(int i=0; i<26; i++) {
                ans = (ans + 1ll * p * val[i] % mod1 * sum[i][j] % mod1) % mod1;
        }
        p = (p * 26) % mod1;
    }
    cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=100;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}