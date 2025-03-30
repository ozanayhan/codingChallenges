#include <stdio.h>
#include <math.h>

// Function to calculate the mean of the data
float calculateMean(float data[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

// Function to calculate the standard deviation of the data
float calculateStandardDeviation(float data[], int size) {
    float mean = calculateMean(data, size);
    float sumSquaredDifferences = 0.0;

    for (int i = 0; i < size; i++) {
        sumSquaredDifferences += pow(data[i] - mean, 2);
    }

    return sqrt(sumSquaredDifferences / (size - 1)); // Sample standard deviation
}

int main() {
    int n;

    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Standard deviation requires at least two data points.\n");
        return 1;
    }

    float data[n];

    // Input the data points
    printf("Enter the data points:\n");
    for (int i = 0; i < n; i++) {
        printf("Data point %d: ", i + 1);
        scanf("%f", &data[i]);
    }

    // Calculate and display the standard deviation
    float stdDeviation = calculateStandardDeviation(data, n);
    printf("The standard deviation of the data is: %.2f\n", stdDeviation);

    return 0;
}