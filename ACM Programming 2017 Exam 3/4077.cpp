#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
const int N = 50005;
 
int a[N], b[N], almin[N], almax[N], blmin[N], blmax[N], armin[N], armax[N], brmin[N], brmax[N];
 
bool comp(int u[2], int v[2]) {
	return u[0] * log(2) + u[1] * log(3) > v[0] * log(2) + v[1] * log(3);
}
 
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i], &b[i]);
	almin[0] = blmin[0] = armin[n + 1] = brmin[n + 1] = N;
	almax[0] = blmax[0] = armax[n + 1] = brmax[n + 1] = 0;	
	for (int i = 1; i <= n; ++i) {
		almin[i] = min(almin[i - 1], a[i]);
		almax[i] = max(almax[i - 1], a[i]);
		blmin[i] = min(blmin[i - 1], b[i]);
		blmax[i] = max(blmax[i - 1], b[i]);
	}
	for (int i = n; i; --i) {
		armin[i] = min(armin[i + 1], a[i]);
		armax[i] = max(armax[i + 1], a[i]);
		brmin[i] = min(brmin[i + 1], b[i]);
		brmax[i] = max(brmax[i + 1], b[i]);		
	}
	for (int i = 1; i <= n; ++i) {
		int gcd = i - 1, lcm = n - i;
		if (!lcm) printf("%d %d ", almin[n], blmin[n]);
		else if (lcm == 1) {
			int ans[2] = {0, 0}, temp[2];
			for (int j = 1; j <= n; ++j) {
				temp[0] = max(a[j], min(almin[j - 1], armin[j + 1]));
				temp[1] = max(b[j], min(blmin[j - 1], brmin[j + 1]));
				if (comp(temp, ans)) {
					ans[0] = temp[0];
					ans[1] = temp[1];
				}
			}
			printf("%d %d ", ans[0], ans[1]);
		} else printf("%d %d ", almax[n], blmax[n]);
		if (!gcd) printf("%d %d\n", almax[n], blmax[n]);
		else if (gcd == 1) {
			int ans[2] = {N, N}, temp[2];
			for (int j = 1; j <= n; ++j) {
				temp[0] = min(a[j], max(almax[j - 1], armax[j + 1]));
				temp[1] = min(b[j], max(blmax[j - 1], brmax[j + 1]));
				if (comp(ans, temp)) {
					ans[0] = temp[0];
					ans[1] = temp[1];
				}
			}
			printf("%d %d\n", ans[0], ans[1]);
		} else printf("%d %d\n", almin[n], blmin[n]);
	}
	return 0;
}
