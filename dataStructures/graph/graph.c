/*
 * Graph Implementation in C — Adjacency List using Linked Lists
 *
 * What is a Graph?
 *   A graph is a set of VERTICES (nodes) connected by EDGES.
 *   Example: Cities connected by roads, friends connected on social media.
 *
 * This implementation uses:
 *   - An array of vertices (each vertex has a name + pointer to its edge list)
 *   - Each edge list is a linked list of neighbors
 *   - Supports: Undirected graph (edge A→B also adds B→A)
 *
 * Operations:
 *   addVertex(name)        → Add a new vertex to the graph
 *   addEdge(src, dest)     → Connect two vertices with an edge
 *   removeEdge(src, dest)  → Remove edge between two vertices
 *   BFS(start)             → Breadth First Search traversal
 *   DFS(start)             → Depth First Search traversal
 *   display()              → Print the full adjacency list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10   /* Maximum number of vertices in the graph */
#define NAME_LEN     20   /* Max characters in a vertex name */

/* ─── Edge Node (Adjacency List Node) ────────────────────────────────────── */

/*
 * Each EdgeNode represents one neighbor of a vertex.
 * Together they form a linked list = the adjacency list of that vertex.
 *
 *  Vertex A → [B] → [C] → [D] → NULL
 *             edge  edge  edge
 */
typedef struct EdgeNode {
    int destIndex;          /* Index of the destination vertex in vertexList[] */
    struct EdgeNode* next;  /* Next neighbor in the list */
} EdgeNode;

/* ─── Vertex Structure ────────────────────────────────────────────────────── */

/*
 * Each Vertex has:
 *   - A name (label like "A", "Delhi", "Node1")
 *   - A pointer to the head of its edge (neighbor) linked list
 */
typedef struct Vertex {
    char name[NAME_LEN];  /* Label of the vertex */
    EdgeNode* head;       /* Head of the adjacency linked list */
} Vertex;

/* Global vertex list and count */
Vertex vertexList[MAX_VERTICES];
int vertexCount = 0;

/* ─── Helper: Find Vertex Index by Name ──────────────────────────────────── */

/*
 * findVertex(name)
 * Returns the index of a vertex by its name.
 * Returns -1 if not found.
 */
int findVertex(const char* name) {
    for (int i = 0; i < vertexCount; i++) {
        if (strcmp(vertexList[i].name, name) == 0)
            return i;
    }
    return -1;
}

/* ─── Add Vertex ──────────────────────────────────────────────────────────── */

/*
 * addVertex(name)
 * Adds a new vertex with the given name to the graph.
 * Does nothing if the vertex already exists or table is full.
 */
void addVertex(const char* name) {
    if (vertexCount >= MAX_VERTICES) {
        printf("Graph full! Cannot add vertex '%s'\n", name);
        return;
    }
    if (findVertex(name) != -1) {
        printf("Vertex '%s' already exists.\n", name);
        return;
    }

    /* Initialize the new vertex */
    strncpy(vertexList[vertexCount].name, name, NAME_LEN - 1);
    vertexList[vertexCount].head = NULL;
    vertexCount++;

    printf("Vertex '%s' added.\n", name);
}

/* ─── Helper: Add a One-way Edge (internal use) ───────────────────────────── */

/*
 * addDirectedEdge(srcIndex, destIndex)
 * Adds a directed edge from src → dest in the adjacency list.
 * Used internally by addEdge() to build undirected edges.
 */
void addDirectedEdge(int srcIndex, int destIndex) {
    /* Create a new edge node */
    EdgeNode* newEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
    if (!newEdge) {
        printf("Memory allocation failed!\n");
        return;
    }
    newEdge->destIndex = destIndex;
    newEdge->next      = vertexList[srcIndex].head; /* Insert at front */
    vertexList[srcIndex].head = newEdge;
}

/* ─── Add Edge ────────────────────────────────────────────────────────────── */

/*
 * addEdge(srcName, destName)
 * Adds an UNDIRECTED edge between two vertices.
 * This means both A→B and B→A are added to their lists.
 *
 * Example: addEdge("A", "B")
 *   A's list: [B] → ...
 *   B's list: [A] → ...
 */
void addEdge(const char* srcName, const char* destName) {
    int src  = findVertex(srcName);
    int dest = findVertex(destName);

    if (src == -1)  { printf("Vertex '%s' not found.\n", srcName);  return; }
    if (dest == -1) { printf("Vertex '%s' not found.\n", destName); return; }
    if (src == dest){ printf("Self-loops not allowed.\n");           return; }

    /* Add both directions for undirected graph */
    addDirectedEdge(src, dest);
    addDirectedEdge(dest, src);

    printf("Edge added: %s <-> %s\n", srcName, destName);
}

/* ─── Remove Edge ─────────────────────────────────────────────────────────── */

/*
 * removeDirectedEdge(srcIndex, destIndex)
 * Removes one direction of an edge from the adjacency list.
 * Used internally by removeEdge().
 */
void removeDirectedEdge(int srcIndex, int destIndex) {
    EdgeNode* current = vertexList[srcIndex].head;
    EdgeNode* prev    = NULL;

    while (current != NULL) {
        if (current->destIndex == destIndex) {
            /* Found the edge — bypass it */
            if (prev == NULL)
                vertexList[srcIndex].head = current->next; /* Was the head */
            else
                prev->next = current->next;
            free(current);
            return;
        }
        prev    = current;
        current = current->next;
    }
}

/*
 * removeEdge(srcName, destName)
 * Removes the undirected edge between two vertices (both directions).
 */
void removeEdge(const char* srcName, const char* destName) {
    int src  = findVertex(srcName);
    int dest = findVertex(destName);

    if (src == -1)  { printf("Vertex '%s' not found.\n", srcName);  return; }
    if (dest == -1) { printf("Vertex '%s' not found.\n", destName); return; }

    removeDirectedEdge(src, dest);
    removeDirectedEdge(dest, src);

    printf("Edge removed: %s <-> %s\n", srcName, destName);
}

/* ─── Display Adjacency List ──────────────────────────────────────────────── */

/*
 * display()
 * Prints the full adjacency list of every vertex.
 *
 * Output format:
 *   [A] → B → C → NULL
 *   [B] → A → NULL
 */
void display() {
    printf("\n--- Adjacency List ---\n");
    for (int i = 0; i < vertexCount; i++) {
        printf("[%-5s] -> ", vertexList[i].name);
        EdgeNode* edge = vertexList[i].head;
        while (edge != NULL) {
            printf("%s -> ", vertexList[edge->destIndex].name);
            edge = edge->next;
        }
        printf("NULL\n");
    }
    printf("----------------------\n");
}

/* ─── BFS (Breadth First Search) ─────────────────────────────────────────── */

/*
 * BFS(startName)
 * Traverses the graph level by level using a QUEUE.
 *
 * Algorithm:
 *   1. Start at the given vertex, mark it visited, enqueue it.
 *   2. Dequeue a vertex, print it.
 *   3. Enqueue all unvisited neighbors, mark them visited.
 *   4. Repeat until queue is empty.
 *
 * Think of it as: "Visit all friends, then friends-of-friends, then..."
 */
void BFS(const char* startName) {
    int start = findVertex(startName);
    if (start == -1) { printf("Vertex '%s' not found.\n", startName); return; }

    int visited[MAX_VERTICES] = {0}; /* Track visited vertices */
    int queue[MAX_VERTICES];         /* Simple array-based queue */
    int front = 0, rear = 0;

    /* Enqueue the starting vertex */
    visited[start]  = 1;
    queue[rear++]   = start;

    printf("\nBFS from '%s': ", startName);

    while (front < rear) {
        /* Dequeue */
        int current = queue[front++];
        printf("%s ", vertexList[current].name);

        /* Enqueue all unvisited neighbors */
        EdgeNode* edge = vertexList[current].head;
        while (edge != NULL) {
            int neighbor = edge->destIndex;
            if (!visited[neighbor]) {
                visited[neighbor]  = 1;
                queue[rear++]      = neighbor;
            }
            edge = edge->next;
        }
    }
    printf("\n");
}

/* ─── DFS Helper (Recursive) ─────────────────────────────────────────────── */

/*
 * dfsHelper(index, visited[])
 * Recursive part of DFS — visits current vertex then dives deep.
 */
void dfsHelper(int index, int visited[]) {
    visited[index] = 1;
    printf("%s ", vertexList[index].name);

    /* Recurse into each unvisited neighbor */
    EdgeNode* edge = vertexList[index].head;
    while (edge != NULL) {
        if (!visited[edge->destIndex])
            dfsHelper(edge->destIndex, visited);
        edge = edge->next;
    }
}

/* ─── DFS (Depth First Search) ───────────────────────────────────────────── */

/*
 * DFS(startName)
 * Traverses as DEEP as possible along each branch before backtracking.
 *
 * Think of it as: "Go as far as you can, then backtrack and try next path."
 */
void DFS(const char* startName) {
    int start = findVertex(startName);
    if (start == -1) { printf("Vertex '%s' not found.\n", startName); return; }

    int visited[MAX_VERTICES] = {0};
    printf("\nDFS from '%s': ", startName);
    dfsHelper(start, visited);
    printf("\n");
}

/* ─── Main ────────────────────────────────────────────────────────────────── */

int main() {
    printf("=== Graph using Adjacency List ===\n\n");

    /* Add vertices */
    addVertex("A");
    addVertex("B");
    addVertex("C");
    addVertex("D");
    addVertex("E");

    /* Add edges */
    printf("\n");
    addEdge("A", "B");
    addEdge("A", "C");
    addEdge("B", "D");
    addEdge("C", "D");
    addEdge("D", "E");

    /* Display the graph */
    display();

    /* Traversals */
    BFS("A");
    DFS("A");

    /* Remove an edge and show again */
    printf("\n");
    removeEdge("C", "D");
    display();

    BFS("A");
    DFS("A");

    return 0;
}
