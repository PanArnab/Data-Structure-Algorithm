#include <stdio.h>
#define MAX 10
int countDegrees(int graph[][MAX], int vertices, int degree[]) {
    int i,j,oddCount = 0, evenCount = 0;
    for (i = 0; i < vertices; i++) {
        degree[i] = 0;  // Initialize degree of each vertex to 0
        for (j = 0; j < vertices; j++) {
            if (graph[i][j] == 1) {
                degree[i]++;  // Increment degree for each adjacent vertex
            }
        }
        if (degree[i] % 2 == 0) {
            evenCount++;  // Count even degree vertices
        } else {
            oddCount++;  // Count odd degree vertices
        }
    }
    printf("Number of odd degree vertices: %d\n", oddCount);
    printf("Number of even degree vertices: %d\n", evenCount);
    return oddCount;
}
int main() {
    int graph[MAX][MAX], vertices, edges, i, j, degree[MAX];
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    printf("Enter the adjacency matrix representation of the graph (0 for no edge, 1 for edge):\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    countDegrees(graph, vertices, degree);
    return 0;
}
