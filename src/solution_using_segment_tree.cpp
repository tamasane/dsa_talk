#include <iostream>
#include <cmath>
using namespace std;

int getMax(int* st, int s, int e, int l, int r, int x);
int buildST(int arr[], int* st, int l, int r, int x);

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
    for (int i=0; i<n; i++) { cin >> arr[i]; if(print) cout << arr[i] << ", "; }
    if (print) cout << "]" << endl;

    // calculating the size of segment tree
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *st = new int[max_size];

    // building the segment tree
    buildST(arr, st, 0, n-1, 0);

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

        // get max value from segment tree
        max = getMax(st, 0, n-1, a, b, 0);
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

/**
 * buildST - Builds the segment tree.
 * @params
 * arr: the input array
 * st: pointer to allocated memory to store segment tree
 * l: start of segment in input array
 * r: end of segment in input array
 * x: node position in the segment tree
 */

int buildST(int arr[], int* st, int l, int r, int x) {
    // if segment is of 1 length, 
    // store the value of the segment 
    // element at node position x
    if (l==r) {
       st[x] = arr[l];
       return st[x];
    }
    // otherwise create a sub segment by 
    // finding the mid of current segment
    int mid = l + (r-l) / 2;
    // the node value x will have the maximum
    // of the two segments
    st[x] = max(buildST(arr, st, l, mid, 2*x+1),buildST(arr, st, mid+1, r, 2*x+2));
    return st[x];
}

/**
 * getMax - Takes a segment tree as input and returns
 *          the maximum value for the given query range 
 * @params
 * st : the constructed segment tree
 * s  : the starting range of segment
 * e  : the ending range of segment
 * l  : the starting range of query
 * r  : the ending range of query
 * x  : the current node position [=max of current segment]
*/
int getMax(int *st, int s, int e, int l, int r, int x) {
    // if the segment range is within query range
    // then return the node value
    if (l <= s && r >= e) return st[x];
    // if the segment and query ranges are separate
    // then return -1
    if (e < l || s > r) return -1;
    // if the segment is bigger than query range
    // then divide the segment 
    int mid = s + (e-s)/2;
    // the answer is maximum of the two division of segments
    return max(getMax(st, s, mid, l, r, 2*x+1), getMax(st, mid+1, e, l, r, 2*x+2));
}