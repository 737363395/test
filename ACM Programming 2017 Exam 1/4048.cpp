#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
const int N = 100100;
 
struct data {
	int x, y;
};
 
data a[N];
int d[N];
 
bool comp(const data &u, const data &v) {
	return u.x < v.x;
}
 
int main() {
	int n, l = 1, r, sum = 0, ans;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i].x);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].y);
		sum += a[i].y;
	}
	ans = sum;
	sort(a + 1, a + n + 1, comp);
	memset(d, 0, sizeof(d));
	while (l <= n) {
		int t, p, q;
		sum -= a[l].y;
		r = l;
		while (r < n && a[r + 1].x == a[l].x) {
			++r;
			sum -= a[r].y;
		}
		p = r - l + 1;
		q = max(l - 1 - (r - l), 0);
		t = sum;
		for (int i = 1; i <= 200; ++i) {
			if (!q) break;
			else if (d[i] > q) {
				t += i * q;
				q = 0;
			} else {
				t += i * d[i];
				q -= d[i];
			}
		}
		ans = min(ans, t);
		for (int i = l; i <= r; ++i) ++d[a[i].y];
		l = r + 1;
	}
	printf("%d\n", ans);
	return 0;
}
