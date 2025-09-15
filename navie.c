#include <stdio.h>

#define V 4
int tsp(int graph[V][V], int mask, int pos, int dp[V][1 << V]) {
    if (mask == (1 << V) - 1)
        return graph[pos][0]; // return to start
    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    int ans = 1e9;
    for (int city = 0; city < V; city++) {
        if (!(mask & (1 << city))) {
            int newAns = graph[pos][city] +
                         tsp(graph, mask | (1 << city), city, dp);
            if (newAns < ans) ans = newAns;
        }
    }
    return dp[pos][mask] = ans;
}

int main() {
    int graph[V][V] = {{0, 20, 42, 25},
                       {20, 0, 30, 34},
                       {42, 30, 0, 10},
                       {25, 34, 10, 0}};
    int dp[V][1 << V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < (1 << V); j++)
            dp[i][j] = -1;

    int ans = tsp(graph, 1, 0, dp);
    printf("Minimum cost of TSP: %d\n", ans);
    return 0;
}
