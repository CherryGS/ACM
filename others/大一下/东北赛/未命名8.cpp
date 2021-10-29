#include <bits/stdc++.h>
#define LL long long
using namespace std;
char str[3000];
map<string, char> m;
int main (){
	m["q"]=
m["iu"]='q';
m["f"]=
m["en"]='f';
m["w"]=
m["ei"]='w';
m["g"]=
m["eng"]='g';
m["e"]='e';
m["h"]=
m["ang"]='h';
m["r"]=
m["uan"]='r';
m["j"]=
m["an"]='j';
m["t"]=
m["ue"]='t';
m["k"]=
m["uai"]=
m["ing"]='k';
m["y"]=
m["un"]='y';
m["l"]=
m["uang"]=
m["iang"]='l';
m["u"]=
m["sh"]='u';
m["z"]=
m["ou"]='z';
m["i"]=
m["ch"]='i';
m["x"]=
m["ia"]=
m["ua"]='x';
m["o"]=
m["uo"]='o';
m["c"]=
m["ao"]='c';
m["p"]=
m["ie"]='p';
m["v"]=
m["zh"]=
m["ui"]='v';
m["a"]='a';
m["b"]=
m["in"]='b';
m["s"]=
m["ong"]=
m["iong"]='s';
m["n"]=
m["iao"]='n';
m["d"]=
m["ai"]='d';
m["m"]=
m["ian"]='m';
	while (scanf("%[^\n]", str) != EOF){
		getchar();
		LL j = 0;
		str[strlen(str)] = '\n';
		while (1){
			LL i = j;
			while (str[j] != ' ' && str[j] != '\n'){
				++ j;
			}
			if (j - i == 1){
				printf("%c%c", str[i], str[i]);
			}
			else if (j - i == 2){
				printf("%c%c", str[i], str[i + 1]);
			}
			else{
				for (LL k = i; k < j; ++ k){
					string s = "";
					for (LL o = k; o < j; ++ o)
						s += str[o];
					if (m.find(s) != m.end()){
						// i - k-1
						string ss = "";
						for (LL r = i; r < k; ++ r)
							ss += str[r];
						// k - j-1
						if (ss != "")
							printf("%c%c", m[ss], m[s]);
						else
							printf("%c%c", str[i], m[s]);
						break;
					}
				}
			}
			if (str[j] == '\n'){
				printf("\n");
				break;	
			}
			else{
				printf(" ");
			}
			++ j;
		}
	}
}
