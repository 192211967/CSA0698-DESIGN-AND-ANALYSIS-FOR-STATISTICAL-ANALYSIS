#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

/* Function to print the Hamiltonian Circuit */
void printSolution(int path[]) {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); // To form the cycle
}

/* Check if the vertex v can be added to the Hamiltonian Circuit */
bool isSafe(int v, int graph[V][V], int path[], int pos) {
    // Check if the vertex is adjacent to the previously added vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

/* Recursive utility function to solve the Hamiltonian Circuit problem */
bool hamCycleUtil(int graph[V][V], int path[], int pos) {
    // Base case: If all vertices are in the path, return true if there's an edge from last to the first vertex
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices to add to the Hamiltonian Circuit
    for (int v = 1; v < V; v++) { // Start from vertex 1 (0 is the starting vertex)
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamCycleUtil(graph, path, pos + 1) == true)
                return true;

            // If adding vertex v doesn't lead to a solution, remove it (backtrack)
            path[pos] = -1;
        }
    }
    return false;
}

/* Solves the Hamiltonian Circuit problem */
bool hamCycle(int graph[V][V]) {
    int path[V];

    // Initialize the path array
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start at vertex 0
    path[0] = 0;

    // Call the recursive utility function
    if (hamCycleUtil(graph, path, 1) == false) {
        printf("No Hamiltonian Circuit exists\n");
        return false;
    }

    printSolution(path);
    return true;
}

int main() {
    /* Adjacency matrix representation of the graph */
    int graph[V][V] = {
        {0, 1, 0, 1, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
    };

    // Solve the Hamiltonian Circuit problem
    hamCycle(graph);

    return 0;
}
