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

vector<int>ve;
int va[100];

int main () {
	int n, tt = 0;
	while(~scanf("%d", &n)){
		ve.clear();
		if(!n) break;
		for(int i = 0, x, y, z; i < n; ++i){
			scanf("%d%d%d%d", &x, &y, &z, va+i);
			--x; --y; --z;
			ve.pb((1<<x)+(1<<y)+(1<<z));
		}
		int dp[1<<9];
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for(int i = 0; i < n; ++i){
			for(int j = (1<<9)-1; j >= 0; --j){
				if((ve[i]&j) != ve[i]) continue;
				if(dp[ve[i]^j] < 0) continue;
				dp[j] = max(dp[j], dp[ve[i]^j]+va[i]);
			}
		}
		printf("Case %d: %d\n", ++tt, dp[(1<<9)-1]);
	}
}