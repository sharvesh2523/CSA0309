#include <stdio.h>
#define MAX 100

void DFS(int adj[MAX][MAX], int visited[MAX], int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for(int i=0; i<n; i++) {
        if(adj[v][i] && !visited[i])
            DFS(adj, visited, i, n);
    }
}

int main() {
    int n, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int adj[MAX][MAX] = {0};
    int visited[MAX] = {0};
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (u v):\n");
    for(int i=0; i<edges; i++) {
        int u,v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("DFS Traversal: ");
    DFS(adj, visited, start, n);
    printf("\n");
    return 0;
}
