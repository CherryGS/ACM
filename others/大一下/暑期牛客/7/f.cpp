#include <stdio.h>
#include <stdlib.h>

#define N	300000

int max(int a, int b) { return a > b ? a : b; }

int *ej[N], eo[N], n;

void append(int i, int j) {
	int o = eo[i]++;

	if (o >= 2 && (o & o - 1) == 0)
		ej[i] = (int *) realloc(ej[i], o * 2 * sizeof *ej[i]);
	ej[i][o] = j;
}

int ta[N], tb[N], time;

void dfs1(int i) {
	int o;

	ta[i] = time++;
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];

		dfs1(j);
	}
	tb[i] = time;
}

void update(int *ft, int i, int n, int x) {
	while (i < n) {
		ft[i] += x;
		i |= i + 1;
	}
}

int query(int *ft, int i) {
	int x = 0;

	while (i >= 0) {
		x += ft[i];
		i &= i + 1, i--;
	}
	return x;
}

int ft1[N], ft2[N], k_;

void dfs2(int i, int k) {
	int o, a;

	if (query(ft2, tb[i] - 1) - query(ft2, ta[i] - 1) > 0)
		a = -1;
	else {
		if ((a = query(ft1, ta[i]) - 1) != -1) {
			update(ft1, ta[a], n, -(a + 1)), update(ft1, tb[a], n, a + 1);
			update(ft2, ta[a], n, -1);
		} else
			a = i, k++;
		update(ft1, ta[i], n, i + 1), update(ft1, tb[i], n, -(i + 1));
		update(ft2, ta[i], n, 1);
	}
	k_ = max(k_, k);
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];

		dfs2(j, k);
	}
	if (a != -1) {
		if (a != i) {
			update(ft1, ta[a], n, a + 1), update(ft1, tb[a], n, -(a + 1));
			update(ft2, ta[a], n, 1);
		} else
			k--;
		update(ft1, ta[i], n, -(i + 1)), update(ft1, tb[i], n, i + 1);
		update(ft2, ta[i], n, -1);
	}
}

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		static int pp[N];
		int i;

		scanf("%d", &n);
		for (i = 1; i < n; i++)
			scanf("%d", &pp[i]), pp[i]--;
		for (i = 0; i < n; i++)
			ej[i] = (int *) malloc(2 * sizeof *ej[i]), eo[i] = 0;
		for (i = 1; i < n; i++) {
			int p;

			scanf("%d", &p), p--;
			append(p, i);
		}
		time = 0, dfs1(0);
		for (i = 0; i < n; i++) {
			free(ej[i]);
			ej[i] = (int *) malloc(2 * sizeof *ej[i]), eo[i] = 0;
		}
		for (i = 1; i < n; i++)
			append(pp[i], i);
		k_ = 0, dfs2(0, 0);
		printf("%d\n", k_);
		for (i = 0; i < n; i++)
			free(ej[i]);
	}
	return 0;
}
