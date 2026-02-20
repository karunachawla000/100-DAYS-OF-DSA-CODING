#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    int is_identity = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                if(matrix[i][j] != 1)
                    is_identity = 0;
            }
            else {
                if(matrix[i][j] != 0)
                    is_identity = 0;
            }
        }
    }

    if(is_identity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
