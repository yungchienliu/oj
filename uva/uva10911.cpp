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
const int N = 16;

double dis[N][N], X[N], Y[N];

int main () {
	int n, tt = 0;
	while(~scanf("%d", &n)){
		if(!n) break;
		char ch[100];
		n *= 2;
		for(int i = 0; i < n; ++i) {
			scanf("%s %lf %lf", ch, X+i, Y+i);
		}
		for(int i = 0; i < n; ++i)
			for(int j = i; j < n; ++j){
				if(i==j) dis[i][j] = 0;
				dis[i][j] = dis[j][i] = hypot(X[i]-X[j],Y[i]-Y[j]);
			}
		double dp[1<<N] = {};
		for(int i = 1; i < (1<<n); ++i) dp[i] = 1e8;
		for(int i = 0; i < (1<<n); ++i){
			for(int x = 0; x < n; ++x) if(i&(1<<x)) 
				for(int y = 0; y < n; ++y) if(i&(1<<y)){
					dp[i] = min(dp[i], dp[i^(1<<x)^(1<<y)]+dis[x][y]);
				//	cout << i <<endl;
				}
		}
		printf("Case %d: %.2f\n", ++tt, dp[(1<<n)-1]);
	}
}