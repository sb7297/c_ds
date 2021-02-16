#include <stdio.h>
#include <stdlib.h>

int binom_coeff(int n, int k) {
	/* if (k == 0) return 1; */
	/* if (n == 0) return 0; */
	/* return binom_coeff(n-1, k) + binom_coeff(n-1, k-1); */
	int D[n+1][k+1];
	for (int j = 0; j < k+1; j++) {
		D[0][j] = 0;
	}
	for (int i = 0; i < n+1; i++) {
		D[i][0] = 1;
	}

	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < k+1; j++) {
			D[i][j] = D[i-1][j] + D[i-1][j-1];
		}
	}
	
	return D[n][k];
}

int main(int argc, char** argv) {
	if (argc >= 3) {
		int n = atoi(argv[1]);
		int k = atoi(argv[2]);
		printf("%d\n", binom_coeff(n, k));
	}
}
