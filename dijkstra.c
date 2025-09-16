#include <stdio.h>
#include <limits.h>
#define MAX 100

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for(int v=0; v<n; v++) {
        if(!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int src, int n) {
    int dist[MAX];
    int visited[MAX] = {0};

    for(int i=0; i<n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for(int count=0; count<n-1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;
        for(int v=0; v<n; v++) {
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printf("Vertex\tDistance from Source\n");
    for(int i=0; i<n; i++)
        printf("%d\t\t%d\n", i, dist[i]);
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int graph[MAX][MAX] = {0};
    printf("Enter adjacency matrix:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);
    dijkstra(graph, src, n);
    return 0;
}
