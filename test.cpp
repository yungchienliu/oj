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
	bitset<4>b = 0;
	b |= 2;
	for(int i = 0; i < 4; ++i ) cout << (b|i)<<endl;
}