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
const int inf = 0x3f3f3f3f;

struct A{
	int co, da;
	A(){}
	A(int a, int b): co(a), da(b) {}
};

int n;
vector<A>ve;

int main () {
	while(~scanf("%d", &n)){
		if(!n) break;
		ve.clear();
		for(int i = 0, x, y; i < n; ++i) {
			scanf("%d%d", &x, &y);
			ve.pb(A(x,y));
		}
		int dp[110][110];
		memset(dp, 0x3f, sizeof(dp));
		dp[0][ve[0].da] = ve[0].co;
		for(int i = 1; i < n; ++i){
			for(int j = 0; j <= n; ++j){
				if(dp[i-1][j] != inf){
					if(j)
						dp[i][min(j-1+ve[i].da, n)] = min(dp[i][min(j-1+ve[i].da, n)], dp[i-1][j]+ve[i].co/2);
					dp[i][min(j+ve[i].da, n)] = min(dp[i][min(j+ve[i].da, n)], dp[i-1][j]+ve[i].co);
				}
			}
		}
		int ans = inf;
		for(int i = 0; i <= n; ++i) ans = min(ans, dp[n-1][i]);
		printf("%d\n", ans);
	}
}