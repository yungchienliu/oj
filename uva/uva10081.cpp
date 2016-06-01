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

double dp[110][10];
int n, k;

int main () {
	while(cin >> k >> n){
		for(int i = 0; i <= k; ++i) dp[1][i] = 1.0/(k+1);
		for(int i = 2; i <= n; ++i){
			for(int j = 0; j<=k; ++j){
				double res = dp[i-1][j]/(k+1);
				if(j) res += dp[i-1][j-1]/(k+1);
				if(j!=k) res += dp[i-1][j+1]/(k+1);
				dp[i][j] = res;
			}
		}
		double ans = 0;
		for(int i = 0; i <= k; ++i) ans += dp[n][i];
		printf("%.5f\n", ans*100.0);
	}
}