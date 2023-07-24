#include<iostream>
using namespace std;
int n,m;
int kmp_next[20000010];
string a;
//void get_next(){
//	int l=-1,r=0;
//	kmp_next[0]=-1;
//	while(r<a.length()){
//		if(l==-1||a[l]==a[r]){
//			kmp_next[++r]=++l;
//		}
//		else
//			l=kmp_next[l];
//	}
//}
void get_next(){
	int j=-1;
	int i=0;
	kmp_next[i]=-1;
	while(i<a.length()){
		while(j!=-1&&a[i]!=a[j]){
			j=kmp_next[j];
		}
		kmp_next[++i]=++j;
	}
}
int main(){
	
	cin>>a;
	a+="#";
	get_next();
	int ans=0;
	for(int i=1;i<a.length();i++){
		ans^=i-kmp_next[i];
	}
	cout<<ans;
	return 0;
}