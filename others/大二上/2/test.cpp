#include<bits/stdc++.h>

using namespace std;

map<char,int> st;
int tot=0;

int main(){
	int l;
	cin>>l;
	string s;
	cin>>s;
	for(int i=0;i<l;i++){
		st[s[i]]++;//统计各个字符的个数
	}
	map<char,int>::iterator  it;//auto蓝桥杯官网不能用
	for(it = st.begin();it!=st.end();it++){
		if(it->second % 2 == 1){
			tot++;
		} 
	}
	if(tot>=2){//两个以上的奇数字符就不能组成字符串
		cout<<"Impossible"<<endl;
	}
	else{
		int ans = 0;//计数
		int res = l;//长度
			for(int i=0;i<(l+1)/2;i++){//半个字符串遍历
				int j;
				for(j=res-1;j>i;j--){//寻找另一半
					if(s[i] == s[j]){
						while(j<res-1){//放在对的地方
							swap(s[j],s[j+1]);
							j++;
							ans++;
						}
						res--;//找到了下次就缩短查找长度
						break;
					}
				}
				if(i==j)//说明是奇数串！
				 ans += abs((l-1)/2 - i);//不知道单个字符在左还是右，所以用绝对值。
			  }
			  cout<<ans<<endl;
			}
	return 0;
}