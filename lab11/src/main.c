#include "lib.c"
#define N 3

int main(void){
    int arr[][N] = {{9, 2, 3},
                    {4, 5, 6},
                    {7, 8, 1}};

    int *diag = get_diagonal(N, *arr);
    sort(N, diag);
    free(diag);
    return 0;
}
