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
typedef pair<int, int> PII;
const int INF = 1e9;
const int N = 1003;
#define pb push_back
#define fi first
#define se second
int n, L, C, ti[N], pre[N];
PII dp[N];

// PII f(int x){
// 	int len;
// 	if(dp[x].fi != -1) return dp[x];
// 	PII res = {INF, INF};
// 	for(int i = 0; i < x; ++i){
// 		len = pre[x-1]; if(i) len-=pre[i-1];
// 		if(len > L)continue;
// 		PII tmp = f(i);
// 		++tmp.fi;
// 		int rem = L - len;
// 		if(rem > 0 && rem <= 10) tmp.se -= C;
// 		else if(rem > 10) {
// 			rem -= 10;
// 			tmp.se += rem * rem;
// 		}
// 		res = min(res, tmp);
// 	}
// 	return dp[x] = res;
// }

// int main () {
// 	int t = 0, fir = 0;
// 	while(~scanf("%d", &n), n){
// 		if(fir) puts("");
// 		else fir = 1;
// 		scanf("%d%d", &L, &C);
// 		for(int i = 0; i < n; ++i) scanf("%d", ti+i);
// 		pre[0] = ti[0];
// 		for(int i = 1; i < n; ++i) pre[i] = pre[i-1]+ti[i];
// 		for(int i = 0; i <= n; ++i) dp[i] = {-1,-1};
// 		dp[0] = {0,0};
// 		PII ans = f(n);
// 		printf("Case %d:\n", ++t);
// 		printf("Minimum number of lectures: %d\n", ans.fi);
// 		printf("Total dissatisfaction index: %d\n", ans.se);
// 	}
// }

int main () {
	int t = 0, fir = 0;
	while(~scanf("%d", &n), n){
		if(fir) puts("");
		else fir = 1;
		scanf("%d%d", &L, &C);
		for(int i = 0; i < n; ++i) scanf("%d", ti+i+1);
		for(int i = 1; i <= n; ++i) dp[i] = {INF, INF};
		dp[0] = {0,0};
		for(int i = 1; i <= n; ++i){
			int sum = 0;
			for(int j = i; j <= n; ++j){
				sum += ti[j];
				if(sum > L) break;
				int rem = L-sum;
				PII tmp = dp[i-1]; ++tmp.fi;
				if(rem > 0 && rem <= 10) tmp.se -= C;
				else if(rem > 10) {
					rem -= 10;
					tmp.se += rem*rem;
				}
				dp[j] = min(dp[j], tmp);
			}
		}
		printf("Case %d:\n", ++t);
		printf("Minimum number of lectures: %d\n", dp[n].fi);
		printf("Total dissatisfaction index: %d\n", dp[n].se);
	}
}