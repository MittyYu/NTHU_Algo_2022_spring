#include <iostream>
#include <queue>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int max(int a, int b) { return (a > b) ? a : b; }
 
// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
 
    // Base Case
    if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
 
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max( val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}

int main()
{
    int n, M;
    cin >> n >> M;
    int val[n];
    int wt[n];
    int v, w;
    for(int i = 0; i < n; i++){
        cin >> v >> w;
        val[i] = v;
        wt[i] = w;
    }
    cout << "Finished Reading file\n";
    auto start = high_resolution_clock::now();
    cout << "Maximum possible profit = "
         << knapSack(M, wt, val, n) << "\n";
    
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "Time taken by program is : " << duration.count() <<  " microseconds\n";
    return 0;
}