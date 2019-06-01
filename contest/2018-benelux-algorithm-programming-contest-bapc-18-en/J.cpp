// 海伦公式: S=sqrt(p(p-a)(p-b)(p-c)), p=(a+b+c)/2;
// 海伦公式推广: 四边形版: S=sqrt((p-a)(p-b)(p-c)(p-d)), p=(a+b+c+d)/2;
#include<bits/stdc++.h>
using namespace std;
int main() {
	double a, b, c, d;
	double p;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	p = (a+b+c+d) / 2.0;
	double ans = sqrt((p-a)*(p-b)*(p-c)*(p-d));
	printf("%.10lf\n", ans);
	return 0;
}
