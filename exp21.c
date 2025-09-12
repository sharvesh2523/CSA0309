#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int queue[SIZE], front = -1, rear = -1;
int visited[SIZE];

// Enqueue function
void enqueue(int v) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

// Dequeue function
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// BFS function
void bfs(int graph[][SIZE], int n, int start) {
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[SIZE][SIZE];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(graph, n, start);

    return 0;
}
