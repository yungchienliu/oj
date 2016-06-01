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

int main () {
	int n, tt = 0;
	while(~scanf("%d", &n)){
		if(!n) break;
		int a[20];
		vector<int>ve;
		for(int i = 0; i < n; ++i) scanf("%d", a+i);
		for(int i = 0; i < n; ++i)
			for(int j = i+1; j < n; ++j)
				for(int k = j+1; k < n; ++k)
					if(a[i]+a[j]+a[k] >= 20) 
						ve.pb((1<<i)+(1<<j)+(1<<k));
		int ans = 0;
		int dp[1<<15]={};
		for(auto i : ve)
			for(int j = (1<<n)-1; j >= i; --j) 
				if((i&j) == i){
					dp[j] = dp[i^j] + 1;
					ans = max(ans, dp[j]);
				}
		printf("Case %d: %d\n", ++tt, ans);
	}
}