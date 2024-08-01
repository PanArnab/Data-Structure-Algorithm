#include <stdio.h>
#define MAX 10
int main() {
    int graph[MAX][MAX], vertices, edges, i, j;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    printf("Enter the adjacency matrix representation of the graph (0 for no edge, 1 for edge):\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    edges = 0;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            if (graph[i][j] == 1) {
                edges++;
            }
        }
    }
    printf("Number of vertices: %d\n", vertices);
    printf("Number of edges: %d\n", edges / 2);  // Divide by 2 since graph is undirected
    return 0;
}
