#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000  // Vector size
#define SCALAR 10.098 // Scalar value

int main() {
    double *arr = (double *)malloc(N * sizeof(double));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize array
    for (long long i = 0; i < N; i++) arr[i] = i;

    // Sequential addition
    double start = omp_get_wtime();
    for (long long i = 0; i < N; i++) arr[i] += SCALAR;
    double end = omp_get_wtime();
    printf("Sequential Time: %f seconds\n", end - start);

    // Parallel addition
    start = omp_get_wtime();
    #pragma omp parallel for
    for (long long i = 0; i < N; i++) arr[i] += SCALAR;
    end = omp_get_wtime();
    printf("Parallel Time: %f seconds\n", end - start);

    free(arr);
    return 0;
}

