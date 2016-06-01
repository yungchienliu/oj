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


bool dp[1010][15] = {};
bool is[310] = {};
vector<int>ve;
bitset<310>w[1010][15], w2[1010][15];

void init(){
	for(int i = 2; i*i <= 300; ++i){
		if(is[i]) continue;
		for(int j = i*i; j <= 300; j+=i) is[j] = 1;
	}
	for(int i = 2; i < 300; ++i) if(!is[i]) ve.pb(i);
	dp[0][0] = 1;
	for(int i = 0; i < 1010; ++i) for(int j = 0; j < 15; ++j){
		w[i][j] = 0; w2[i][j] = 0;
	}
	bitset<310>x, y;
	for(auto i : ve)
		for(int j = 1; j <= 14; ++j)
			for(int k = 1000; k >= i; --k)
				if(dp[k-i][j-1]){
					if(i == 2 && w[k-i][j-1][i]) continue;
					if(w[k-i][j-1][i] && w2[k-i][j-1][i])
						continue;
					x = w[k-i][j-1];
					y = w2[k-i][j-1];
					if(w[k-i][j-1][i]) y[i] = 1;
					else x[i] = 1;
					if(!dp[k][j]){
						w[k][j] = x; w2[k][j] = y;
						dp[k][j] = 1; continue;
					}
					else{
						if((w[k][j]^x).count()){
							for(int ii = 0; ii < 65; ++ii) if(x[i] != w[k][j][i]){
								if(x[i]){
									w[k][j] = x;
									w2[k][j] = y;
									break;
								}
							}
						}
						else{
							for(int ii = 0; ii < 65; ++ii) if(y[i] != w2[k][j][i]){
								if(y[i]){
									w[k][j] = x;
									w2[k][j] = y;
									break;
								}
							}
						}
					}
				}
}

int main () {
	init();
	int n, k, tt = 0;
	while(~scanf("%d%d", &n, &k)){
		printf("Case %d:\n", ++tt);
		if(!n && !k) break;
		if(!dp[n][k]) {
			puts("No Solution.");
			continue;
		}
		vector<int>ans;
		for(int i = 0; i < 310; ++i) {
			if(w[n][k][i]) ans.pb(i);
			if(w2[n][k][i]) ans.pb(i);
		}
		printf("%d", ans[0]);
		for(int i = 1; i < ans.size(); ++i) printf("+%d", ans[i]);
		puts("");
	}
}