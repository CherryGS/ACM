#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
int a[100100];
ll sum, det, sum_a, pre_det, pre_ans;
int acnt, id;
int q[300100][101], cnt[300100], l;
int mp[10000010];
map<int, int> e, s;

void deal(int r, cint d) {
    int m;
    if(r==1) return;
    if(!(r%2)) {
        q[d][++cnt[d]] = 2;
        while(!(r%2)) r /= 2;
    }
    int k;
    while(r > 1) {
        k = mp[r];
        if(k!=0) q[d][++cnt[d]] = k;
        else {q[d][++cnt[d]] = r; return;}
        while(!(r%k)) r /= k; 
    }
}

bool check(cint r) {
    for(; id<=cnt[r]; id++)
        if(e.find(q[r][id]) != e.end()) {return 1;} 
    return 0;
}

void del(cint r) {
    for(int i=1; i<=cnt[r]; i++) {
        --e[q[r][i]];
        if(!e[q[r][i]]) e.erase(q[r][i]);
    }
}

void add(cint r) {
    for(int i=1; i<=cnt[r]; i++)
        ++e[q[r][i]];
}

void init() {
    int r = 1e7;
    for(int i=3; i*i <= r; i+=2) {
        if(!mp[i])
            for(int j=i*i; j <= r; j+=i) {
                if(!mp[j]) mp[j] = i;
            }
    }
}

int main() {
    init();
    scanf("%d", &t);
    while(t--) {
        sum_a = sum = 0;
        l = 0;
        pre_det = 0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            sum_a = (sum_a+a[i]) % mod;
            pre_det = (pre_det + ((i-l)*a[i])%mod ) % mod;
            sum = (pre_det+sum) % mod;

            if(!s[a[i]]) s[a[i]] = ++acnt,deal(a[i], s[a[i]]);
            while(!e.empty()) {
                if(check(s[a[i]])) del(s[a[++l]]);
                else break;
                pre_det = (pre_det - sum_a + mod) % mod;
                sum = ((sum-sum_a) + mod ) % mod;
                sum_a = (sum_a-a[l]+mod) % mod;
            }
            id=1;
            add(s[a[i]]);
        }
        // for(int i=1; i<=acnt; i++) {
        //     cout << "num : " << i << endl;
        //     for(int j=1; j<=cnt[i]; j++)
        //         cout << q[i][j] << '-';
        //     cout << endl; 
        // }
        printf("%lld\n", sum);
        if(t) e.clear();
    }
    return 0;
}