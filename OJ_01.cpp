#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

inline bool IntersectsCircle(double x0, double y0, double r, double x1, double y1, double x2, double y2) {
	double dist = fabs(x0*(y2 - y1) - y0 * (x2 - x1) + x2 * y1 - x1 * y2) / sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	if (r < dist) return 0;
	else {
		double dS1 = (x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1), dS2 = (x0 - x2)*(x0 - x2) + (y0 - y2)*(y0 - y2);
		if (dS1 < r * r && dS2 < r * r) return 0;
		if (dS1 <= r * r || dS2 <= r * r) return 1;
		else {
			if (((x0 - x1)*(x2 - x1) + (y0 - y1)*(y2 - y1)) * ((x1 - x2)*(x0 - x2) + (y1 - y2)*(y0 - y2)) <= 0.)
				return 0;
			else return 1;
		}
	}
}


int main() {
	int n;
	scanf("%d", &n);
	bool line[3];
	double r, x0, y0, x1, y1, x2, y2, x3, y3;
	char* res = new char[n];
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf", &r, &x0, &y0, &x1, &y1, &x2, &y2, &x3, &y3);
		line[0] = IntersectsCircle(x0, y0, r, x1, y1, x2, y2);
		line[1] = IntersectsCircle(x0, y0, r, x2, y2, x3, y3);
		line[2] = IntersectsCircle(x0, y0, r, x1, y1, x3, y3);
		if (!(line[0] || line[1] || line[2]))
			res[i] = '0';
		else res[i] = '1';
	}
	for (int i = 0; i < n; i++) {
		printf("%c", res[i]);
		if (i < n - 1) printf("\n");
	}
}