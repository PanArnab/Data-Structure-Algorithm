#include <stdio.h>
#include <stdbool.h>
#define MAX 10
bool isCyclicUtil(int v, bool visited[], int parent, int graph[][MAX], int vertices) {
	int i;
    visited[v] = true;
    for (i = 0; i < vertices; i++) {
        if (graph[v][i]) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, v, graph, vertices)) {
                    return true;
                }
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}
bool isCyclic(int graph[][MAX], int vertices) {
	int i;
    bool visited[MAX] = { false };
    for (i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, -1, graph, vertices)) {
                return true;
            }
        }
    }
    return false;
}
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
    if (isCyclic(graph, vertices)) {
        printf("The graph contains a cycle.\n");
    } else {
        printf("The graph does not contain a cycle.\n");
    }
    return 0;
}
