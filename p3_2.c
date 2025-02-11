#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

void matrixAddition(int size, int num_threads) {
    double *mat1 = (double *)malloc(size * size * sizeof(double));
    double *mat2 = (double *)malloc(size * size * sizeof(double));
    double *additionmat = (double *)malloc(size * size * sizeof(double));

    double start = omp_get_wtime();

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < size * size; i++) {
        mat1[i] = rand() % 10;
        mat2[i] = rand() % 10;
        additionmat[i] = mat1[i] + mat2[i];
    }

    double end = omp_get_wtime();
    printf("\nExecution Time: %f seconds | Size: %d | Threads: %d\n", end - start, size, num_threads);

    free(mat1);
    free(mat2);
    free(additionmat);
}

int main() {
    int size = 230;
    for (int threads = 2; threads <= 8; threads += 2) {
        matrixAddition(size, threads);
    }
    return 0;
}

