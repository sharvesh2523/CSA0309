#include <stdio.h>
#include <limits.h>

#define SIZE 100
#define INF INT_MAX

int findMinKey(int key[], int mstSet[], int n) {
    int min = INF, min_index;

    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void primMST(int graph[SIZE][SIZE], int n) {
    int parent[SIZE]; // Store MST
    int key[SIZE];    // Key values
    int mstSet[SIZE]; // MST set

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;      // Start from vertex 0
    parent[0] = -1;  // Root has no parent

    for (int count = 0; count < n - 1; count++) {
        int u = findMinKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int n, graph[SIZE][SIZE];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    primMST(graph, n);

    return 0;
}
