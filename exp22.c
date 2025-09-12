#include <stdio.h>

#define SIZE 100

int visited[SIZE];

// DFS function
void dfs(int graph[][SIZE], int n, int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}

int main() {
    int n, graph[SIZE][SIZE], start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(graph, n, start);

    return 0;
}
