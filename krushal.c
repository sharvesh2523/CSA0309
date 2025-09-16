#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Edge structure
struct Edge {
    int src, dest, weight;
};

// Graph structure
struct Graph {
    int V, E;
    struct Edge edges[MAX];
};

// Subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Find set of an element
int find(struct Subset subsets[], int i) {
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union of two sets
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight - b1->weight;
}

// Kruskal's algorithm
void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[MAX];
    int e = 0;
    int i = 0;

    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compare);

    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    for(int v=0; v<V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while(e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if(x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Edge \tWeight\n");
    for(int j=0; j<e; j++)
        printf("%d - %d \t%d\n", result[j].src, result[j].dest, result[j].weight);

    free(subsets);
}

int main() {
    struct Graph graph;
    printf("Enter number of vertices: ");
    scanf("%d", &graph.V);
    printf("Enter number of edges: ");
    scanf("%d", &graph.E);

    printf("Enter edges (source destination weight):\n");
    for(int i=0; i<graph.E; i++) {
        scanf("%d %d %d", &graph.edges[i].src, &graph.edges[i].dest, &graph.edges[i].weight);
    }

    KruskalMST(&graph);

    return 0;
}
