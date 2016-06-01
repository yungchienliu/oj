#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

typedef long long ll;
#define pb push_back
const int N = 1000000;


struct A{
	int a[100];
	A(){
		memset(a, 0, sizeof(a));
	}
	A(A& x){
		memset(a, 0, sizeof(a));
		for(int i = 0; i < 100; ++i) a[i] = x.a[i];
	}
	A(int x){
		memset(a, 0, sizeof(a));
		int fl = 0;
		while(x){
			a[fl++] = x % N;
			x /= N;
		}
	}
	A operator+(A& x){
		for(int i = 0; i < 99; ++i){
			a[i] += x.a[i];
			a[i+1] += a[i] / N;
			a[i] %= N;
		}
		return *this;
	}
};

A dp[110][10010];

void out(A& x){
	int fl = -1;
	for(int i = 99; i >= 0; --i){
		if(x.a[i]) { fl = i; break; }
	}
	if(fl == -1) { puts("0"); return;}
	cout << x.a[fl];
	for(int i = fl-1; i >= 0; --i){
		printf("%06d", x.a[i]);
	}
	puts("");
}

int main () {
	int t;
	string a, b;
	cin >> t;
	while (t--){
		cin >> a >> b;
		for(int i = 0; i < b.length(); ++i) for(int j = 0; j < a.length(); ++j) dp[i][j] = A();
		for(int i = 0; i < a.length(); ++i) if(a[i] == b[0]) dp[0][i] = A(1); else dp[0][i] = A(0);
		for(int i = 1; i < b.length(); ++i){
			A tmp;
			for(int j = 0; j < a.length(); ++j){
				if(b[i] == a[j]) dp[i][j] = dp[i][j] + tmp;
				tmp = tmp + dp[i-1][j];
			}
		}
		A ans;
		for(int i = 0; i < a.length(); ++i) ans = ans + dp[b.length()-1][i];
		out(ans);
	}
}