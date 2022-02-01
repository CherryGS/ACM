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
int a[20][20];

bool check(int i,int j){ 
	int k=0;
	for(k=0; k<n; k++)if(a[i][k]!=a[j][k]) break;
	if(k==n) return 1;
	else return 0;
}


void solve(cint T) {
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) cin>>a[i][j];
	}
	int sum;          
	for(int i=0; i<n; i++) {  
		sum=0;
		for(int j=0; j<n; j++) if(check(i,j)) sum++;
		if(sum > n/2){  
			sum=i;    
			break;
		}
	}
	for(int i=0; i<n; i++)
		if(a[sum][i]==1) cout << i+1 << " ";

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
