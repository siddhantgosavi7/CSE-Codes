#include<stdio.h>


int main() {
    int mat[5][4] = {{2, 5, -1, -1}, {1, 5, 3, 4}, 
    {2, 4, -1, -1}, {5, 2, 3, -1},  {1, 4, 2, -1}};

    int n = sizeof(mat) / sizeof(mat[0]), m =sizeof(mat[0]) / sizeof(mat[0][0]);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == -1) printf("0 ");
            else printf("1 ");
        }
        printf("\n");
    }

    return 0;
}