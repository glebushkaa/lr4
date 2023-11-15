#include <math.h>
#include <stdio.h>

// Function to calculate factorial
double factorial(int n) {
    if (n == 0 || n == 1) return 1.0;
    return n * factorial(n - 1);
}

// Function to calculate the right part
double calculateSeries(double x, double epsilon, int maxSteps, int *numSteps) {
    double result = 0.0;
    double term;
    *numSteps = 0;

    for (int n = 1;; ++n) {
        term = ((n + 1) * pow(x, n + 2)) / factorial(n + 2);
        result += term;
        *numSteps += 1;

        if (fabs(term) < epsilon || *numSteps >= maxSteps) break;
    }

    return result;
}

int main() {
    double x, epsilon;
    int maxSteps;

    // Get input values from the user with validation
    do {
        printf("Enter the value of x: ");
        scanf("%lf", &x);

        if (x < -10 || x > 10) {
            printf("Invalid x. X must be in range of -10 to 10.\n");
            continue;
        }

        printf("Enter the epsilon value (e.g., 1e-6): ");
        scanf("%lf", &epsilon);

        printf("Enter the maximum number of steps: ");
        scanf("%d", &maxSteps);

        if (epsilon <= 0 || maxSteps <= 0) {
            printf("Invalid input. Epsilon and maxSteps must be positive.\n");
        }
    } while (epsilon <= 0 || maxSteps <= 0 || x < -10 || x > 10);

    // Calculate the right part
    int numSteps;
    double seriesResult = calculateSeries(x, epsilon, maxSteps, &numSteps);

    // Calculate the actual value of the function
    double exactValue = 1 + (x - 1) * exp(x) - (x * x) / 2;

    // Output the results
    printf("\nApproximated value of f(x): %lf\n", seriesResult);
    printf("Number of steps: %d\n", numSteps);
    printf("Exact value of f(x): %lf\n", exactValue);
    printf("Absolute difference: %lf\n", fabs(seriesResult - exactValue));

    return 0;
}