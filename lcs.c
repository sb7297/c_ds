// finds length of longest common subsequence between two strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lcs_len(const char* xs, const char* ys,
            size_t xs_len, size_t ys_len)
{
    /* int left_len; int right_len; */
    /* if (xs_len == 0 || ys_len == 0) return 0; */
    /* else if (xs[xs_len-1] == ys[ys_len-1]) { */
    /*     return 1 + lcs_len(xs, ys, xs_len-1, ys_len-1); */
    /* } */
    /* else { */
    /*     left_len  = lcs_len(xs, ys, xs_len-1, ys_len); */
    /*     right_len = lcs_len(xs, ys, xs_len, ys_len-1); */
    /*     return ((left_len > right_len) ? left_len : right_len); */
    /* } */
    int D[xs_len+1][ys_len+1];
    int left_len;
    int right_len;

    for (int i = 0; i < xs_len+1; i++) {
        D[i][0] = 0;
    }
    for (int i = 0; i < ys_len+1; i++) {
        D[0][i] = 0;
    }

    for (int i = 1; i < xs_len+1; i++) {
        for (int j = 1; j < ys_len+1; j++) {
            if (xs[i-1] == ys[j-1]) {
                D[i][j] = 1 + D[i-1][j-1];
                printf("%c", xs[i-1]);
            }
            else {
                left_len  = D[i-1][j];
                right_len = D[i][j-1];
                D[i][j] = (left_len > right_len) ? left_len : right_len;
            }
        }
    }
    
    printf("\n");

    return D[xs_len][ys_len];
}

int minDistance(char * a, char * b){
    int la = strnlen(a, 500); int lb = strnlen(b, 500);
    int lz = lcs_len(a, b, la, lb);
    return la + lb - 2*lz;
}

int main() {
    const char* xs = "sea";
    const char* ys = "eat";
    printf("%d\n", minDistance(xs, ys));
}