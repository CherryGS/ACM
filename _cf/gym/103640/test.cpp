#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double db;
typedef long double ld;
 
#define IL inline
#define pb push_back
#define mk make_pair
#define dbg1(x) cout << #x << " = " << x << ", "
#define dbg2(x) cout << #x << " = " << x << endl
 
template<typename Tp> IL void read(Tp &x) {
  x = 0; int f = 1; char ch=getchar();
  while(!isdigit(ch)) { if( ch == '-') f=-1; ch=getchar();}
  while(isdigit(ch)) { x = x * 10 + ch-'0'; ch=getchar();}
  x *= f;
}
 
int buf[42];
template<typename Tp> IL void write(Tp x) {
  int p = 0;
  if(x < 0) { putchar('-'); x=-x;}
  if(x == 0) { putchar('0'); return;}
  while(x) {
    buf[++p] = x % 10;
    x /= 10;
  }
  for(int i=p;i;i--) putchar('0'+buf[i]);
}
 
const int N = 100000 + 5;
const int M = 262144;
const db PI = acos(-1.0);
 
int n, n1, n2;
int aa[N], bb[N];
int sa[N], sb[N], fa[N], fb[N];
ll sc[N], fc[M];
vector<ll> maxv, minv;
 
struct cp {
  db x, y;
  cp(db x=0.0, db y=0.0):x(x), y(y) {}
  IL cp operator + (const cp& o) const { return cp(x+o.x, y+o.y);}
  IL cp operator - (const cp& o) const { return cp(x-o.x, y-o.y);}
  IL cp operator * (const cp& o) const { return cp(x*o.x-y*o.y, x*o.y+y*o.x);}
  IL cp operator * (const db& p) const { return cp(x*p, y*p);}
  IL cp operator / (const db& p) const { return cp(x/p, y/p);}
  IL cp operator ! () const { return cp(x, -y);}
};
IL cp polar(const db& rho, const db& theta) { return cp(rho * cos(theta), rho * sin(theta));}
int rev[M];
cp eps[M], ieps[M], fft_a[M], fft_b[M], fft_c[M];
IL void initeps() {
  for(int i=0;i<N;i++) eps[i] = polar(1.0, 2 * PI * i / N);
  ieps[0] = eps[0] = 1;
  for(int i=1;i<N;i++) ieps[i] = eps[N - i];
}
IL void cal_rev(int degA, int degB, int& lim, int &p) {
  lim = 1; p = 0;
  while(lim <= ((degA + degB) >> 1)) { lim <<= 1; p++;}
  for(int i=0;i<lim;i++) rev[i] = (rev[i >> 1] >> 1) | ((i&1) << (p-1));
}
IL void trans(cp *x, cp *w, int n) {
  for(int i=0;i<n;i++) if(i < rev[i]) swap(x[i], x[rev[i]]);
  for(int i=2;i<=n;i<<=1) {
    int l = i >> 1, d = N / i;
    for(int j=0;j<n;j+=i) {
      for(int k=0;k<l;k++) {
	cp t = x[j+k+l] * w[d * k];
	x[j+k+l] = x[j+k] - t;
	x[j+k] = x[j+k] + t;
      }
    }
  }
}
IL void dft(cp *x, int n) { trans(x, eps, n);}
IL void idft(cp *x, int n) { trans(x, ieps, n); for(int i=0;i<n;i++) x[i] = x[i] / n;}
 
IL int polymul(ll *C, int *A, int *B, int degA, int degB) {
  int lim, lglim;
  cal_rev(degA, degB, lim, lglim);
  for(int i=0;i<=degA;i++) (i & 1 ? fft_a[i>>1].y : fft_a[i>>1].x) = A[i];
  for(int i=degA+1;i<lim;i++) (i & 1 ? fft_a[i>>1].y : fft_a[i>>1].x) = 0;
  for(int i=0;i<=degB;i++) (i & 1 ? fft_b[i>>1].y : fft_b[i>>1].x) = B[i];
  for(int i=degB+1;i<lim;i++) (i & 1 ? fft_b[i>>1].y : fft_b[i>>1].x) = 0;
  dft(fft_a, lim); dft(fft_b, lim);
  int d = N / lim;
  for(int i=0;i<lim;i++) {
    int j = (lim - 1) & (lim - i);
    fft_c[i] = (fft_a[i] * fft_b[i] * 4 - (fft_a[i] - !fft_a[j]) * (fft_b[i] - !fft_b[j]) * (eps[d*i]+cp(1, 0))) * 0.25;
  }
  idft(fft_c, lim);
  for(int i=0;i<=degA+degB;i++) C[i] = (i & 1 ? fft_c[i>>1].y : fft_c[i>>1].x) + 0.5;
  return degA + degB;
}
 
void solve(int *a, int *b, vector<ll>& ans) {
  // get the maximum of sum a_i * b_i
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  int l = 1e9, r = 0;
  for(int i=1;i<=n;i++) {
    int sign = 0;
    if(a[i] >= 0) sign ^= 1;
    if(b[i] >= 0) sign ^= 1;
    if(sign) l = min(l, i), r = max(r, i);
  }
  //dbg1(l); dbg2(r);
  n1 = n2 = 0;
  for(int i=1;i<=n;i++) {
    if(l <= i && i <= r) {
      fa[n1] = a[i];
      fb[n1] = b[i];
      n1++;
    }
    else {
      n2++;
      sa[n2] = a[i];
      sb[n2] = b[i];
    }
  }
  for(int i=1;i<=n2;i++) {
    sc[i] = 1ll * sa[i] * sb[i];
  }
  sort(sc + 1, sc + 1 + n2, [](ll x, ll y) { return x > y;});
  ll sum = 0;
  for(int i=1;i<=n2;i++) {
    sum += sc[i];
    ans.pb(sum);
    // dbg1(i); dbg1(sc[i]); dbg2(sum);
  }
  
  if(l <= r) {
    if(fa[0] < 0) sort(fa, fa + n1, [](int x, int y) {return x > y;});
    else sort(fb, fb + n1, [](int x, int y) { return x > y;});
 
    if(fa[0] < 0) for(int i=0;i<n1;i++) fa[i] = -fa[i];
    else for(int i=0;i<n1;i++) fb[i] = -fb[i];
 
    //for(int i=0;i<n1;i++) { dbg1(i); dbg2(fa[i]);}
    //for(int i=0;i<n1;i++) { dbg1(i); dbg2(fb[i]);}
    
    polymul(fc, fa, fb, n1 - 1, n1 - 1);
    for(int i=0;i<n1;i++) {
      //dbg1(i); dbg2(fc[i]);
      ans.pb(sum - fc[i]);
    }
  }
}
 
int main() {
#ifdef LOCAL
  freopen("test.in", "r", stdin);
#endif
  initeps();
  read(n);
  for(int i=1;i<=n;i++) read(aa[i]);
  for(int i=1;i<=n;i++) read(bb[i]);
  solve(aa, bb, maxv);
 
  for(int i=1;i<=n;i++) aa[i] = -aa[i];
  solve(aa, bb, minv);
  for(int i=0;i<minv.size();i++) minv[i] = -minv[i];
  for(int i=0;i<n;i++) {
    write(minv[i]); putchar(32); write(maxv[i]); putchar(10);
  }
  return 0;
}