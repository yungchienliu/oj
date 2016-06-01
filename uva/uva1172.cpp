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
typedef pair<int, int> PII;
#define mp make_pair
#define ff first
#define ss second
const int MAXN = 1010;

struct A{
	string x, y;
	int v;
	A(){}
	A(string a, string b, int c): x(a), y(b), v(c) {}
};

vector<A>N, S;
PII bit[MAXN];
int n, m;

void update(int x, PII v){
	x += 1;
	for(;x <= m; x += x&-x){
		bit[x] = max(bit[x], v);
	}
}

PII query(int x){
	if(x == -1) return mp(0,0);
	x += 1;
	PII res = mp(0,0);
	for(;x>0;x-=x&-x) res = max(res, bit[x]);
	return res;
}

// O(N^2 logN)

int main () {
	int t;
	cin >> t;
	while(t--){
		N.clear();
		S.clear();
		cin >> n;
		for(int i = 0; i < n; ++i){
			string a, b;
			int v;
			cin >> a >> b >> v;
			N.pb(A(a,b,v));
		}
		cin >> m;
		for(int i = 0; i < m; ++i){
			string a, b;
			int v;
			cin >> a >> b >> v; 
			S.pb(A(a,b,v));
		}
		for(int i = 1; i <= m; ++i) bit[i] = mp(0,0);
		for(int i = 0; i < n; ++i){
			for(int j = m-1; j >= 0; --j){
				A& e = S[j];
				if(e.y == N[i].y){
					PII tmp = query(j-1);
					tmp.ff += N[i].v + e.v;
					--tmp.ss;
					update(j, tmp);
				}
			}
		}		
		PII ans = query(m-1);
		cout << ans.ff << ' ' << -ans.ss <<endl;
	}
}


// O(N^2)
PII dp[MAXN][MAXN];
		for(int i = 0; i < MAXN; ++i) for(int j = 0; j < MAXN; ++j) dp[i][j] = mp(0,0);
		for(int i = 0; i < n; ++i) 
			for(int j = 0; j< m; ++j){
				A& e = S[j];
				if(e.y == N[i].y)
					dp[i+1][j+1] = mp(dp[i][j].ff + N[i].v + e.v, dp[i][j].ss-1);
				
				dp[i+1][j+1] = max(dp[i+1][j+1],max(dp[i+1][j], dp[i][j+1]));
			}
		cout << dp[n][m].ff << ' ' << -dp[n][m].ss<<endl;