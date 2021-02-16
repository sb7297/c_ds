#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int edit_dist(const char* a, const char* b) {
    const int MLEN = 256;
    size_t alen = strnlen(a, MLEN);
    size_t blen = strnlen(b, MLEN);
    int deleted;
    int added;
    int changed;
    int D[MLEN][MLEN];
    for (int i = 0; i < MLEN; i++) {
        for (int j = 0; j < MLEN; j++) {
            D[i][j] = -1;
        }
    }

    D[0][0] = 0;
    for (int i = 1; i < alen+1; i++) {
        D[i][0] = i;
    }
    for (int j = 1; j < blen+1; j++) {
        D[0][j] = j;
    }

    for (int i = 1; i < alen+1; i++) {
        for (int j = 1; j < blen+1; j++) {
            changed = D[i-1][j-1] + ((a[i] == b[j]) ? 0 : 1);
            deleted = D[i-1][j] + 1;
            added = D[i][j-1] + 1;
            if (changed <= deleted && changed <= added) {
                D[i][j] = changed;
            }
            else if (deleted <= changed && deleted <= added) {
                D[i][j] = deleted;
            }
            else {
                D[i][j] = added;
            }
        }
    }
    return D[alen][blen];
}

int main() {
    printf("%d\n", edit_dist("kaojgnnvaoof", "ggkakpgwa"));
    return 0;
}
