#include<iostream>
using namespace std; 
void uuru(int *p){
	while(1){ //这个循环用于输入数据 ,第一步； 
		cin>>*p;
		if(*p==-1){//用-1来结束输入； 
			break;
		}
		p++;
	}
}
void iais(int *p){
	int i=1,j=1;
	while(*p != -1){
		if(*p==-2){
			(*p)++;
			continue; 
		}//如果某数据已被证实是重复数据，则在这里跳过； 
		while(*(p+i) != -1){
			if(*p==*(p+i)){
				j++;
				*(p+i) = -2;
			}
			i++;
		}
		if(j!=1){
			cout<<"数据"<<*p<<"出现重复，重复次数为"<<j<<endl;
		}
		i=1; j=1;
		p++;
	}
}
int main(){
	using namespace std;
	int a;
	uuru(&a);
	iais(&a);
	cout<<1<<endl;
	return 0;
}
