#include <string.h>
#include <stdio.h>
#include <stdlib.h>

long max(long x, long y) {
    if (x>y) return x;
    return y;
}

long del_dist(char* a, char* b) {
    const long MLEN = 256;
    size_t alen = strnlen(a, MLEN);
    size_t blen = strnlen(b, MLEN);
    long deleted;
    long added;
    long changed;
    long D[MLEN][MLEN];
    for (long i = 0; i < MLEN; i++) {
        for (long j = 0; j < MLEN; j++) {
            D[i][j] = -1;
        }
    }

    D[0][0] = 0;
    for (long i = 1; i < alen+1; i++) {
        D[i][0] = i;
    }
    for (long j = 1; j < blen+1; j++) {
        D[0][j] = j;
    }

    for (long i = 1; i < alen+1; i++) {
        for (long j = 1; j < blen+1; j++) {
            if (a[i-1] == b[j-1]) D[i][j] = D[i-1][j-1] + 1;
            else D[i][j] = max(D[i][j-1], D[i-1][j]); 
        }
    }
    return D[alen][blen];
}

int main() {
    printf("%ld\n", del_dist("kekw", "we"));
    /* printf("%ld\n", del_dist("democrats", "republicans")); */
    return 0;
}