#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

const int N = 200200;

int f[N];
map <int, int> t;
set <int> a[N];

int get(int x) {
	if (!f[x]) return x;
	else {
		f[x] = get(f[x]);
		return f[x];
	}
}

int main() {
	int n, m = 0, c = 0;
	scanf("%d", &n);
	t.clear();
	memset (f, sizeof(f), 0);
	for (int i = 1; i < N; ++i) a[i].clear();
	for (int i = 1; i <= n; ++i) {
		int x, y, z, p;
		bool g = true;
		scanf("%d%d%d", &x, &y, &p);
		if (t.find(x) == t.end()) {
			++m;
			t[x] = m;
		}
		if (t.find(y) == t.end()) {
			++m;
			t[y] = m;
		}
		x = get (t[x]);
		y = get (t[y]);
		if (p) {
			if (a[x].size() < a[y].size()) swap(x, y);
			for (set <int> :: iterator j = a[y].begin(); j != a[y].end(); ++j)
				if (get(*j) == x) {
					g = false;
					break;
				}
			if (g && x != y) {
				f[y] = x;
				for (set <int> :: iterator j = a[y].begin(); j != a[y].end(); ++j) a[x].insert(*j);
				a[y].clear();
			}
		} else {
			if (x == y) g = false;
			else {
				a[x].insert(y);
				a[y].insert(x);
			}
		}
		printf(g ? "YES\n" : "NO\n");
	}
	return 0;
}
