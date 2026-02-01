#include <iostream>
using namespace std;

int main() {
    int n = 10;
    
    // Example 1: Single loop - O(n)
    // Steps: 1, n+1, n
    for (int i = 0; i < n; i++) {
        cout << i;  // n
    }
    cout << endl;
    // Total steps = 1 + n + 1 + n + n = 3n + 2
    // Time Complexity = O(n)
    
    
    // Example 2: Two sequential loops - O(n)
    // Steps: 1, n+1, n
    for (int i = 0; i < n; i++) {
        cout << i;  // n
    }
    cout << endl;
    
    // Steps: 1, n+1, n
    for (int j = 0; j < n; j++) {
        cout << j;  // n
    }
    cout << endl;
    // Total steps = 2(1 + n + 1 + n + n) = 6n + 4
    // Time Complexity = O(n)
    
    
    // Example 3: Nested loops - O(n²)
    // Steps: 1, n+1, n
    for (int i = 0; i < n; i++) {
        // n(1, n+1, n)
        for (int j = 0; j < n; j++) {
            cout << i + j;  // n(n)
        }
        cout << endl;
    }
    // Total steps = 1 + n + 1 + n + n(1 + n + 1 + n + n)
    //             = 3n² + 4n + 2
    // Time Complexity = O(n²)
    
    
    // Example 4: Nested loops (triangular) - O(n²)
    // Steps: 1, n+1, n
    for (int i = 0; i < n; i++) {
        // n(1 + n(n+1)/2 + n(n-1)/2)
        for (int j = 0; j < i; j++) {
            cout << i + j;  // n(n(n-1)/2)
        }
        cout << endl;
    }
    // Total steps = 3n² + 5n + 4
    // Time Complexity = O(n²)
    
    
    // Example 5: Logarithmic loop (multiply by 2) - O(log n)
    // Steps: 1, log n + 1, log n
    for (int i = 1; i <= n; i *= 2) {
        cout << i;  // log n
    }
    cout << endl;
    // Total steps = 3 log n + 2
    // Time Complexity = O(log n)
    
    
    // Example 6: Logarithmic loop (divide by 2) - O(log n)
    // Steps: 1, log n + 1 + 1, log n + 1
    for (int i = n; i > 0; i /= 2) {
        cout << i;  // log n + 1
    }
    cout << endl;
    // Total steps = 1 + log n + 2 + log n + 1 + log n + 1
    //             = 3 log n + 5
    // Time Complexity = O(log n)
    
    
    // Example 7: Triple nested loops - O(n³)
    // Steps: 1, n+1, n
    for (int i = 0; i < n; i++) {
        // n(1, n+1, n)
        for (int j = 0; j < n; j++) {
            // n*n(1, n+1, n)
            for (int k = 0; k < n; k++) {
                cout << i + j + k;  // n*n*n
            }
            cout << endl;
        }
        cout << endl;
    }
    // Total steps = 1 + n + 1 + n + n(1 + n + 1 + n) + n²(1 + n + 1 + n) + n³
    //             = 3n³ + 4n² + 4n + 2
    // Time Complexity = O(n³)
    
    
    // Example 8: Nested loop + sequential loop - O(n²)
    // Steps: 1, n+1, n
    for (int i = 0; i < n; i++) {
        // n(1, n+1, n)
        for (int j = 0; j < n; j++) {
            cout << i + j;  // n(n)
        }
        cout << endl;
    }
    
    // Steps: 1, n+1, n
    for (int k = 0; k < n; k++) {
        cout << k;  // n
    }
    cout << endl;
    // Total steps = 1 + n + 1 + n + n(1 + n + 1 + n + n) + 1 + n + 1 + n + n
    //             = 3n² + 7n + 4
    // Time Complexity = O(n²)
    
    
    // Example 9: Logarithmic outer, linear inner - O(n log n)
    // Steps: 1, log n + 1, log n + 1
    for (int i = 1; i < n; i *= 2) {
        // log n(1, n+1, n)
        for (int j = 0; j < n; j++) {
            cout << i + j;  // log n(n)
        }
        cout << endl;
    }
    // Total steps = 1 + log n + 1 + log n + 1 + log n(1 + n + 1 + n) + log n(n)
    //             = 3n log n + 4 log n + 2
    // Time Complexity = O(n log n)
    
    
    // Example 10: Square root loop - O(√n)
    // Steps: 1, √n + 1, √n
    for (int i = 0; i * i < n; i++) {
        cout << i;  // √n
    }
    cout << endl;
    // Total steps = 1 + √n + 1 + √n + √n = 3√n + 2
    // Time Complexity = O(√n)
    
    
    // Example 11: While loops (nested) - O(n²)
    int i = 0;      // 1
    int j = 0;      // 1
    while (i < n) { // n + 1
        while (j < n) { // n(n + 1)
            cout << i + j;  // n(n)
            j++;            // n(n)
        }
        i++;  // n
    }
    // Total steps = 2 + n + 1 + n² + n + n² + n² + n
    //             = 3n² + 2n + 4
    // Time Complexity = O(n²)
    
    return 0;
}