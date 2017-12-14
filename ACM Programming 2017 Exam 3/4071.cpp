#include <cstdlib>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
const long long M = 1e9 + 7;
 
struct matrix {
	long long a, b, c, d;
};
 
matrix operator * (const matrix &u, const matrix &v) {
	return (matrix) {(u.a * v.a % M + u.b * v.c % M) % M, (u.a * v.b % M + u.b * v.d % M) % M,
					(u.c * v.a % M + u.d * v.c % M) % M, (u.c * v.b % M + u.d * v.d % M) % M};
}
 
matrix power(const matrix &x, long long y) {
	if (!y) return (matrix) {1, 0, 0, 1};
	else {
		matrix t = power(x, y >> 1);
		t = t * t;
		if (y & 1) return t * x;
		else return t;
	}
}
 
int main() {
	long long n;
	matrix m;
	scanf("%lld", &n);
	m = power((matrix){1, 1, 1, 0}, n);
	printf("%lld\n", m.a);
	return 0;
}
