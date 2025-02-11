#include <stdio.h>
#include <omp.h>

int main() {
    long long num_terms = 10000000; 
    double pi = 0.0, start, end;

    // Sequential Calculation
    start = omp_get_wtime();
    for (long long i = 0; i < num_terms; i++) {
        double term = 1.0 / (2 * i + 1);
        if (i % 2 == 1) term = -term; 
        pi += term;
    }
    pi *= 4;
    end = omp_get_wtime();
    printf("Sequential Calculation:\n");
    printf("Estimated Pi: %.6f\n", pi);
    printf("Time taken: %.6f seconds\n\n", end - start);

    // Parallel Calculation
    pi = 0.0;
    start = omp_get_wtime();
    #pragma omp parallel for reduction(+:pi)
    for (long long i = 0; i < num_terms; i++) {
        double term = 1.0 / (2 * i + 1);
        if (i % 2 == 1) term = -term; 
        pi += term;
    }
    pi *= 4;
    end = omp_get_wtime();
    printf("Parallel Calculation:\n");
    printf("Estimated Pi: %.6f\n", pi);
    printf("Time taken: %.6f seconds\n", end - start);

    return 0;
}
