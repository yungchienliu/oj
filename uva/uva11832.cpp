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

const int s = 42000;
bool dp[45][s+40001];
vector<int>v;
int n, tar, sum, L, R;

void f(int x){
	for(int i = 0; i < n; ++i){
		if(i == x) continue;
		bool tmp[s+40001] = {};
		for(int j = R; j >= L; --j)
			if(dp[x][j])
				tmp[j-v[i]] = tmp[j+v[i]] = 1;
		for(int j = R; j >= L; --j) 
			dp[x][j] = tmp[j];
	}
}

int main () {
	while(~scanf("%d%d", &n, &tar)){
		if(!n && !tar) break;
		v.clear();
		sum = 0;
		for(int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			v.pb(x);
			sum += x;
		}
		L = s-sum; R = s+sum;
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i <= n; ++i) dp[i][s] = 1;
		for(int i = 0; i <= n; ++i) f(i); 
		// for(int i = 0; i <= 9; ++i) cout << dp[0][s+i] <<' '; cout <<endl;
		if(!dp[n][s+tar]) puts("*");
		else{
			for(int i = 0; i < n; ++i){
				bool pos = 0, neg = 0;
				if(dp[i][s+tar-v[i]]) pos = 1;
				if(dp[i][s+tar+v[i]]) neg = 1;
				if(pos && neg) putchar('?');
				else if(pos) putchar('+');
				else putchar('-');
			}
			puts("");
		}
	}
}