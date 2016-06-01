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

int n, m, sum, a[110];

int main () {
	while(~scanf("%d%d", &n, &m)){
		sum = 0;
		int tot = n+m;
		for(int i = 0; i < tot; ++i){
			scanf("%d", a+i);
			sum += a[i];
		}
		if(m < n) swap(n,m);
		bool dp[12000][55] = {};
		dp[6000][0] = 1;
		for(int i = 0; i < tot; ++i)
			for(int j = n; j > 0; --j)
				for(int k = 11111; k > 900; --k){
					if(dp[k-a[i]][j-1]) dp[k][j] = 1;
				}
		int Max = -1e6, Min = 1e6;
		for(int i = 900; i <= 11111; ++i) if(dp[i][n]){
			int tmp = (i-6000) * (sum-i+6000);
			Max = max(Max, tmp);
			Min = min(Min, tmp);
		}
		printf("%d %d\n", Max, Min);
	}
}