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
    int totalEdges = vertices * (vertices - 1) / 2; // Total edges in a complete graph
    int edgeCount = 0;
    for (i = 0; i < vertices; i++) {
        for (j = i + 1; j < vertices; j++) {
            if (graph[i][j] == 1) {
                edgeCount++;
            }
        }
    }
    if (edgeCount == totalEdges) {
        printf("The graph is complete.\n");
    } else {
        printf("The graph is not complete.\n");
    }
    return 0;
}
