#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    int n, print;
    cin >> n >> print;
    // Print the number n as size of array and number of queries.
    // The print variable is also printed in input so that  
    // solution code knows whether to print results for each query or not.
    cout << n << " " << print <<endl;
    // Set the seed value to current time.
    srand(time(0));
    // Print n random numbers in range [0, n-1], one per line.
    for (int i=0; i<n; i++) cout << rand() % n << endl;
    // Print n range queries in format [a b], one per line.
    for (int i=1; i<n+1; i++) cout << rand() % n/2  << " " << rand() % n << endl;
    return 0;
}