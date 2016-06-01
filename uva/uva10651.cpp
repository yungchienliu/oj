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

int dp[1<<12];

int f(int mask){
	if(dp[mask] != -1) return dp[mask];
	int res = 0;
	for(int i = 0; i < 12; ++i) if( (mask&(1<<i)) ) ++res;
	for(int i = 0; i < 12; ++i){
		if((mask&(1<<i)) == 0) continue;
		if(i>=2 && (mask&(1<<(i-1))) && (mask&(1<<(i-2)))==0 )
			res = min(res, f(mask^(1<<i)^( 1<<(i-1) )^( 1<<(i-2) )));
		if(i<=9 && ( mask&(1<<(i+1)) ) && ( mask&(1<<(i+2)) ) == 0 )
		 	res = min(res, f( mask^(1<<i)^( 1<<(i+1) )^( 1<<(i+2) )));
	}
	return dp[mask] = res;
}

void init(){
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	int tot = (1<<12);
	for(int i = 0; i < tot; ++i){
		f(i);
	}
}

int main () {
	init();
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		char ch[15];
		scanf("%s", ch);
		int tmp = 0;
		for(int i = 0; i < 12; ++i) if(ch[i] == 'o') tmp += (1<<i);
		printf("%d\n", dp[tmp]);
	}
}