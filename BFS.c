#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if(rear == MAX-1)
        printf("Queue overflow\n");
    else {
        if(front == -1) front = 0;
        queue[++rear] = v;
    }
}

int dequeue() {
    if(front == -1)
        return -1;
    int v = queue[front++];
    if(front > rear)
        front = rear = -1;
    return v;
}

int isEmpty() {
    return front == -1;
}

void BFS(int adj[MAX][MAX], int visited[MAX], int start, int n) {
    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal: ");
    while(!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);
        for(int i=0; i<n; i++) {
            if(adj[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
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
    BFS(adj, visited, start, n);
    return 0;
}
