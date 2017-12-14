#include <cstdlib>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
long long solve(long long a, long long b) {
	long long s;
	if (a == b) return a << 2;
	if (a < b) swap(a, b);
	if (!b) return 0;
	return solve(b, a - b) + (b << 2);
}
 
int main() {
	long long a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", solve(a, b));
	return 0;
}
