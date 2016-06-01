‪
#pragma c++ optimize("O2")
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

ll h(int& x){
	ll res = 0;
	unsigned int tmp = 0;
	int tot = sqrt(x);
	for(int i = 1; i <= tot; ++i){
		tmp += x/i;
		int a = x/i, b = x/(i+1);
		// if( a > b )
		// 	res += (a - b) * i;
		if(x/i > x/(i+1))
			tmp += (x/i - x/(i+1)) * i;
		res += tmp; tmp = 0;
	}
	if(x/tot == tot) res -= tot;
	return res;
}

int main () {
	int t;
	scanf("%d", &t);
	while(t--){
		 int x;
		scanf("%d", &x);
		if(!x) { puts("0"); continue; }
		printf("%lld\n", h(x));
	}
}