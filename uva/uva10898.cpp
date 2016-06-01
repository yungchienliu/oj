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

struct A{
	int a[7], co;
	A(){}
};

int pri[7], n, now[7], ans;
vector<A>ve;

int dfs(){
	// for(int i = 0; i < n; ++i) cout << now[i] << ' ' ; cout <<endl;
	int res = 0;
	for(int i = 0; i < n; ++i) res += now[i]*pri[i];
	for(auto i : ve){
		int ok = 0;
		for(int j = 0; j < n; ++j) if(now[j] < i.a[j]) {ok = 1; break;}
		if(ok) continue;
		for(int j = 0; j < n; ++j) now[j] -= i.a[j];
		res = min(res, dfs()+i.co);
		for(int j = 0; j < n; ++j) now[j] += i.a[j];
	}
	return res;
}

int main () {
	while(~scanf("%d", &n)){
		ve.clear();
		for(int i = 0; i < n; ++i)
			scanf("%d", pri+i);
		A tmp;
		int ba;
		scanf("%d", &ba);
		for(int i = 0; i < ba; ++i){
			for(int j = 0; j < n; ++j)
				scanf("%d", &tmp.a[j]);
			scanf("%d", &tmp.co);
			ve.pb(tmp);
		}
		int q;
		scanf("%d", &q);
		while(q--){
			for(int i = 0; i < n; ++i)
				scanf("%d", now+i);
			ans = dfs();
			printf("%d\n", ans);
		}
	}
}