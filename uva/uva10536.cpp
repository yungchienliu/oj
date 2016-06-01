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

int dp[1<<16];
vector<int>op;

int f(int x){
	if(dp[x] != -1) return dp[x];
	int res = 0;
	for(auto i : op){
		if((i&x) != i) continue;
		if(f(i^x) == 0) {
			res = 1;
			break; 
		}
	}
	return dp[x] = res;
}

void init(){
	for(int i = 0; i < 16; ++i) op.pb(1<<i);
	for(int i = 0; i <= 12; i += 4){
		int tmp = 1<<i;
		for(int j = i+1; j <= i+2; ++j){
			tmp ^= (1<<j);
			op.pb(tmp);
		}
	}
	for(int i = 3; i <= 15; i += 4){
		int tmp = 1<<i;
		for(int j = i-1; j >= i-2; --j){
			tmp ^= (1<<j);
			op.pb(tmp);
		}
	}
	for(int i = 0; i < 4; ++i){
		int tmp = 1<<i;
		for(int j = i+4; j <= i+8; j+=4){
			tmp ^= (1<<j);
			op.pb(tmp);
		}
	}
	for(int i = 12; i < 16; ++i){
		int tmp = 1<<i;
		for(int j = i-4; j >= i-8; j-=4){
			tmp ^= (1<<j);
			op.pb(tmp);
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = 1;
	int tot = 1<<16;
	for(int i = 1; i < tot; ++i)
		f(i);
}

int main () {
	init();
	int n;
	scanf("%d", &n);
	for(int t = 0; t < n; ++t){
		char s[10];
		int mask = 0, ba;
		for(int i = 0; i < 4; ++i){
			ba = i*4;
			scanf("%s", s);
			for(int j = 0; j < 4; ++j)
				if(s[j] == '.') mask ^= (1<<(ba+j));
		}
		if(dp[mask])
			puts("WINNING");
		else puts("LOSING");
	}
}