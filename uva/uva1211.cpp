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
const int N = 110;

vector<int> ve;
double b, r, v, e, f;
// double dp[N][N];

double ti[11000];

void init(){
	ti[0] = 0;
	for(int i = 0; i < 10004; ++i){
		double tmp;
		if(i < r) tmp = 1/(v-f*(r-i));
		else tmp = 1/(v-e*(i-r));
		ti[i+1] = ti[i] + tmp;
	}
}

// O(N^2 * N)

double ff(int la, int x){
	if(dp[la][x] > -1e6) return dp[la][x];
	double res = 1e7;
	for(int i = 0; i <= la; ++i){
		if(i == la && la) continue;
		res = min(res, ff(i, la));
	}
	return dp[la][x] = res + b + ti[ve[x]-ve[la]];
}

int main () {
	int n;
	while(cin >> n){
		if(!n) break;
		ve.clear();
		ve.pb(0);
		for(int i = 0; i < n; ++i) {
			double x;
			cin >> x;
			ve.pb(x);
		}
		cin >> b >> r >> v >> e >> f;
		init();
		for(int i = 0; i <= n; ++i) for(int j = 0; j <= n; ++j) dp[i][j] = -1e7;
		dp[0][0] = -b;
		double ans = 1e7;
		for(int i = 0; i < n; ++i) ans =min(ans, ff(i, n));
		printf("%.4f\n", ans);
	}
}

// loop O(N^2)

/*
double dp[N];
int main () {
	int n;
	while(cin >> n){
		if(!n) break;
		ve.clear();
		ve.pb(0);
		for(int i = 0; i < n; ++i) {
			double x;
			cin >> x;
			ve.pb(x);
		}
		cin >> b >> r >> v >> e >> f;
		init();
		for(int i = 0; i <= n; ++i) dp[i] = 1e7;
		dp[0] = -b;
		for(int i = 0; i < n; ++i){
			for(int j = i+1; j <= n; ++j)
				dp[j] = min(dp[j], dp[i] + b + ti[ve[j]-ve[i]]);
		}
		double ans = dp[n];
		// for(int i = 0; i < n; ++i) ans =min(ans, ff(i, n));
		printf("%.4f\n", ans);
	}
}*/
