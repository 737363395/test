#include <cstdlib>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
const int N = 500500;
const int M = 1001000;
 
struct edge {
	int t, next;
};
 
int h[N], s[N];
edge e[M];
 
void addedge(int u, int v) {
	++h[0];
	e[h[0]] = (edge) {v, h[u]};
	h[u] = h[0];
}
 
void dfs(int cur, int pre) {
	for (int i = h[cur]; i != -1; i = e[i].next)
		if (e[i].t != pre) {
			dfs(e[i].t, cur);
			s[cur] += s[e[i].t];
		}
}
 
int solve(int cur, int pre) {
	int sum = 0;
	for (int i = h[cur]; i != -1; i = e[i].next)
		if (e[i].t != pre)
			sum += min(s[e[i].t], s[0] - s[e[i].t]) + solve(e[i].t, cur);
	return sum;
}
 
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; ++i) {
		h[i] = -1;
		s[i] = 0;
	}
	for (int i = m << 1; i; --i) {
		int t;
		scanf("%d", &t);
		s[t] = 1;
	}
	s[0] = m << 1;
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs(1, 0);
	printf("%d\n", solve(1, 0));
	return 0;
}
