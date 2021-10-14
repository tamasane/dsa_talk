#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    int n, print;
    cin >> n >> print;
    cout << n << " " << print <<endl;
    srand(time(0));
    for (int i=0; i<n; i++) cout << rand() % n << endl;
    for (int i=1; i<n+1; i++) cout << rand() % n/2  << " " << rand() % n << endl;
    return 0;
}