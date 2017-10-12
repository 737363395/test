#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
 
using namespace std;

bool check(char *s, int m) {
	for (int i = m >> 1; i >= 0; --i) if (s[m - i - 1] != s[i]) return false;
	return true;
}

void trans(char *s, char *t, int m) {
	for (int i = 0; i < m; ++i) t[i] = s[m - i - 1];
}

void add(char *s, char *t, int &m, int n) {
	int r = 0;
	for (int i = 0; i < m; ++i) {
		int p, q;
		p = s[i] - '0' < 10 ? s[i] - '0' : s[i] - 'A' + 10;
		q = t[i] - '0' < 10 ? t[i] - '0' : t[i] - 'A' + 10;
		s[i] = (p + q + r) % n;
		s[i] = s[i] < 10 ? s[i] = s[i] + '0' : s[i] = s[i] - 10 + 'A';
		r = (p + q + r) / n;
	}
	if (r) {
		s[m] = r < 10 ? r + '0' : r - 10 + 'A';
		++m;
	}
}
 
int main(){
	const int N = 128;
	char a[N], b[N], c[N];
	int n, m;
	scanf("%d", &n);
	scanf("%s", a);
	m = strlen(a);
	if (check(a, m)) {
		printf("STEP=0");
		return 0;
	}
	for (int i = 1; i <= 30; ++i) {
		trans(a, b, m);
		add(a, b, m, n);
		if (check(a, m)) {
			printf("STEP=%d\n",i);
			return 0;
		}
	}
	printf("Impossible!\n");
	return 0;
}
