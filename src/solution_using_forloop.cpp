#include <iostream>
using namespace std;

int main() {
    // variables to measure program execution time
    time_t start, end; 
    time(&start);
    // n : input size
    // print : whether to print output for each query (1) or not (0)
    int n, print;
    cin >> n >> print;

    // arr: the input array
    int arr[n];
    // reading and printing input array (if printing is enabled)
    if (print) cout << "[ ";
    for (int i=0; i<n; i++) { cin >> arr[i]; if (print) cout << arr[i] << ", "; }
    if (print) cout << "]" << endl;

    // reading a query and finding the max in the range
    for (int i=0; i<n; i++) {
        // take 2 endpoints for query range
        // q_start: endpoint1 from input
        // q_end:   endpoint2 from input
        // a:       actual start (lesser of q_start, q_end)
        // b:       actual end   (greater of q_start, q_end)
        int q_start, q_end, a, b, max=-1;
        cin >> q_start >> q_end;
        a = q_start > q_end ? q_end: q_start;
        b = q_start > q_end ? q_start: q_end;
        // checking the max value from a to b in the array
        for (int i=a; i<=b; i++) {
            max = max < arr[i] ? arr[i] : max;
        }
        // print the range and max value (if printing is enabled)
        if (print) cout << "[" << a << "," << b << "] = " << max << endl;
    }
    time(&end);
    // calculate and print the time taken
    double time_taken = double(end - start);
    cout.precision(17);
    cout << "Time taken by program is : "
         << time_taken << " sec " << endl;
    return 0;
}