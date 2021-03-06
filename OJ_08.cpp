#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int N;
	double ipt[4][3];
	double X, Y, x1, x2, y1, y2, q11, q12, q21, q22;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf %lf %lf", &ipt[i][0], &ipt[i][1], &ipt[i][2]);
	}
	scanf("%lf %lf", &X, &Y);
	x1 = ipt[0][0]; y1 = ipt[0][1]; q11 = ipt[0][2];
	for (int i = 1; i < 4; i++) {
		if (ipt[i][0] != x1 && ipt[i][1] != y1) {
			x2 = ipt[i][0]; y2 = ipt[i][1];
		}
	}
	for (int i = 1; i < 4; i++) {
		if (ipt[i][0] == x1 && ipt[i][1] != y1) q12 = ipt[i][2];
		if (ipt[i][0] != x1 && ipt[i][1] == y1) q21 = ipt[i][2];
		if (ipt[i][0] != x1 && ipt[i][1] != y1) q22 = ipt[i][2];
	}
	double opt = 0.;
	if (N == 4) {
		double denominator = (x2 - x1)*(y2 - y1);
		opt = (q11 * (X - x2)*(Y - y2) + q21 * (X - x1)*(y2- Y) + q12 * (x2-X)*(Y - y1) + q22 * (X - x1)*(Y - y1)) / denominator;
	}
	printf("%.10lf", opt);
	return 0;
}