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
const int N = 510;
typedef pair<int,int> PII;
#define mp make_pair

int n, a[N], m, b[N];
PII fr[N][N];

int main () {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> b[i];
	}
	int dp[N][N] = {};
	for(int i = 1; i <= n; ++i){
		int Max = 0, fx = 0, fy = 0;
		for(int j = 1; j <= m; ++j){
			if(a[i] == b[j]){
				dp[i][j] = Max + 1;
				fr[i][j] = mp(fx, fy);
			}
			else 
				dp[i][j] = dp[i-1][j];
			if(a[i] > b[j]) 
				if(dp[i-1][j] > Max){
					Max = dp[i-1][j];
					fx = i-1; fy = j;
				}
		}
	}
	int ans = 0, px, py;
	for(int i = 1; i <= m; ++i) if(dp[n][i] > ans){
		ans = dp[n][i];
		px = n;
		py = i;
	}
	vector<int>ve;
	while(px && py){
		if(a[px] == b[py]){
			ve.pb(a[px]);
			PII& e = fr[px][py];
			px = e.first;
			py = e.second;
		}
		else {
			--px;
		}
	}
	cout << ans <<endl;
	if(ans){
		for(int i = (int)ve.size()-1; i >= 0; --i){
			if(i != (int)ve.size()-1) putchar(' ');
			cout<<ve[i];
		}
		puts("");
	}
}
