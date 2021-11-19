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

const int M=1e6+5;
int nxt[M];
char s[M];
char r[101];
int n, q;

void getnext(char *p,int len){
    int i,j;
    i=0,j=nxt[0]=-1;
    while(i<len){
        while(j!=-1&&p[i]!=p[j]) j=nxt[j];
        nxt[++i]=++j;
    }
}

bool kmp(char *s,char *p){
    int len1,len2,i,j;
    i=j=0;
    len1=strlen(s);
    len2=strlen(p);
    getnext(p,len2);
    while(i<len1){
        while(j!=-1&&s[i]!=p[j]) j=nxt[j];
        i++,j++;
        if(j==len2)
            return 1;
    }
    return 0;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> n >> q;
        cin >> s;
        for(int i=1; i<=q; i++) {
            cin >> r;
            cout << kmp(s, r) << '\n';
        }
    }
    return 0;
}

