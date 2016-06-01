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
const int N = 25;

int a[N], sum, n, ok = 0;
bool vis[N];

void dfs(int p, int x, int cnt){
	if(ok) return;
	if(cnt == 3){
		ok = 1; 
		return;
	}
	if(x == sum){
		dfs(0, 0, cnt+1);
		return;
	}
	for(int i = p; i < n; ++i){
		if(vis[i])continue;
		if(x + a[i] > sum) continue;
		vis[i] = 1;
		dfs(i+1, x+a[i], cnt);
		vis[i] = 0;
	}
}

int main () {
	int t;
	scanf("%d", &t);
	while(t--){
		sum = 0;
		ok = 0;
		scanf("%d", &n);
		int M =0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", a+i);
			M = max(M, a[i]);
			sum += a[i];
		}
		if(sum % 4 || M > sum/4) {
			puts("no");
			continue;
		}
		sum /= 4;
		memset(vis, 0, sizeof(vis));
		dfs(0, 0, 0);
		if(ok) puts("yes");
		else puts("no");
	}
}