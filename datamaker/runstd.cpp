#include<bits/stdc++.h>
using namespace std;
char c[500];
const char *a;
string s;
string s1;
int main()
{
	int l = 1, r = 30;
    string name = "easy";
	for(int i=l;i<=r;i++){
		itoa(i,c,10);
		s=(string)"std < " + name +c+(string)".in > " + name +c+(string)".out";
		a=s.c_str();
        cout << i << endl;
		if(system(a)) break;
		cout<<"Ok,"<<i<<endl;
	}
}
