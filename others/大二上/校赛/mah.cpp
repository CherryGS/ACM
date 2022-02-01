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

int n, m, cnt;
char s[2];
char out[1001];
char in[1001];

struct card {
    int v;
    card(char&s, char&t) {
        v = s - '0';
        v += (t == 'T' ? 0 : (t == 't' ? 1 : (t == 'W' ? 2: 3))) * 10;
    }
    void init(char &s, char &t) {
        v = s - '0';
        v += (t == 'T' ? 0 : (t == 't' ? 1 : (t == 'W' ? 2: 3))) * 10;
    }
    bool operator < (const card&a) const {
        return v < a.v;
    }
    bool operator == (const card&a) const {
        return v == a.v;
    }
};

bool check1(vector<card> & s) {
    // 诈和
    for(card &k : s)
        if(k.v == 35) return 1;
    return 0;
}

bool check2(vector<card> & s, int val) {
    // 是否坎
    int c[3] = {0, 0, 0};
    int t = 0;
    for(int i=0; i<s.size(); i++) {
        if(i && ~(s[i] == s[i-1])) {
            ++ c[(t+1)%3];
            t = 0;
        } else ++ t;
    }
    val -= c[1];
    c[2] += c[1];
    val -= c[2] - 1;
    if(val < 0) return 0;
    return 1;
}

bool check3(vector<card> & s, int val) {
    // 是否句
    
}

void solve(cint T) {
    cin >> n >> m >> s;
    cin >> out >> in;
    vector<card> ot, ins;
    for(int i=0; i<n; i+=2) ot.push_back(card(out[i], out[i+1]));
    for(int i=0; i<m; i+=2) {
        if(in[i] == s[0] && in[i+1] == s[1]) ++cnt;
        else ins.push_back(card(in[i], in[i+1]));
    }
    sort(ot.begin(), ot.end());
    sort(ins.begin(), ins.end());
    if(check1(ins)) cout << "ZH" << endl;
    else {

    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}