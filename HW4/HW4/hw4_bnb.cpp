#include <iostream>
#include <queue>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

  
struct Element
{
    int v;
    float w;
};
  
struct Node
{
    int level, profit, bound;
    float w;
};

bool cmp(Element a, Element b)
{
    double r1 = (double)a.v / a.w;
    double r2 = (double)b.v / b.w;
    return r1 > r2;
}
  
// Returns bound of profit in subtree rooted with u.
int bound(Node u, int n, int W, Element arr[])
{
    if (u.w >= W) return 0;
    int profit_bound = u.profit;
    int j = u.level + 1;
    int totw = u.w;

    while ((j < n) && (totw + arr[j].w <= W))
    {
        totw    += arr[j].w;
        profit_bound += arr[j].v;
        j++;
    }

    if (j < n)
        profit_bound += (W - totw) * arr[j].v / arr[j].w;
  
    return profit_bound;
}
  
// Returns maximum profit we can get with capacity W
int knapsack(int W, Element arr[], int n)
{
    sort(arr, arr + n, cmp);
    queue<Node> Q;
    Node u, v;
  
    u.level = -1;
    u.profit = u.w = 0;
    Q.push(u);

    int maxProfit = 0;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
  
        if (u.level == -1)
            v.level = 0;
  
        if (u.level == n-1)
            continue;
        v.level = u.level + 1;
        v.w = u.w + arr[v.level].w;
        v.profit = u.profit + arr[v.level].v;
        if (v.w <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W, arr);

        if (v.bound > maxProfit)
            Q.push(v);

        v.w = u.w;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }
  
    return maxProfit;
}
  
int main(int argc, char *argv[])
{    
    int n, M;
    float w;
    int v;
    cin >> n >> M;
    Element arr[n];

    
    for(int i = 0; i <n; i++){
        cin >> v >> w;
        // cout << v << " " << w << "\n";
        arr[i] = {v, w};
    }
    //cout << "Finished Reading file\n";
    //auto start = high_resolution_clock::now();
    
    cout << "Maximum possible profit = "
         << knapsack(M, arr, n) << "\n";
    
    //auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(stop - start);
    //cout << "Time taken by program is : " << duration.count() <<  " microseconds\n";

    return 0;
}