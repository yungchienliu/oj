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
const int N = 22;

int n, m;
ll dp[22][22][2];

void init(){
	memset(dp, -1, sizeof(dp));
}

ll f(int low, int high, int head){
	if(dp[low][high][head] != -1) return dp[low][high][head];
	if(!low && !high) return dp[low][high][head] = 1;
	if(!head && !low && high) return dp[low][high][head] = 0;
	if(head && low && !high) return dp[low][high][head] = 0;
	ll res = 0;
	if(!head){
		for(int i = 1; i <= low; ++i){
			res += f(i-1, low-i+high, 1);
		}
	}
	else{
		for(int i = 1; i <= high; ++i){
			res += f(i-1+low, high-i, 0);
		}
	}
	return dp[low][high][head] = res;
}

int main () {
	init();
	while(~scanf("%d%d", &n, &m)){
		ll ans = 0;
		if(n <= 3) ans = 1;
		else if(m == 1){
			n -= 3;
			for(int i = 1; i <= n; ++i) ans += f(i-1, n-i, 0);
		}
		else{
			ans = f(m-1, n-m, 0);
		}
		printf("%lld\n", ans);
	}
}