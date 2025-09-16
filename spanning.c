#include <stdio.h>
#include <limits.h>
#define MAX 100

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index = -1;
    for(int v=0; v<n; v++) {
        if(mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX] = {0};

    for(int i=0; i<n; i++)
        key[i] = INT_MAX;

    key[0] = 0;
    parent[0] = -1;

    for(int count=0; count<n-1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        for(int v=0; v<n; v++) {
            if(graph[u][v] && mstSet[v]==0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edge \tWeight\n");
    for(int i=1; i<n; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int n;
    printf("Enter number of
