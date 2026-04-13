# Graph in C — Adjacency List using Linked Lists

A complete graph implementation in C built from scratch using **nodes (linked lists)** for the adjacency list representation.

---

## What is a Graph?

A **Graph** is a collection of:
- **Vertices** (nodes) — the entities (e.g., cities, people, servers)
- **Edges** — connections between vertices (e.g., roads, friendships, cables)

```
    A ──── B
    |      |
    C ──── D ──── E
```

This implementation is an **undirected graph** — every edge works both ways (A↔B means A can reach B and B can reach A).

---

## Representation: Adjacency List

Each vertex stores a **linked list** of its neighbors.

```
[A] -> B -> C -> NULL
[B] -> D -> A -> NULL
[C] -> D -> A -> NULL
[D] -> E -> C -> B -> NULL
[E] -> D -> NULL
```

This is more **memory-efficient** than an adjacency matrix for sparse graphs (few edges).

| | Adjacency List | Adjacency Matrix |
|---|---|---|
| Space | O(V + E) | O(V²) |
| Add Edge | O(1) | O(1) |
| Find Neighbor | O(degree) | O(1) |
| Best for | Sparse graphs | Dense graphs |

---

## Data Structures Used

### EdgeNode (one neighbor in the list)
```c
typedef struct EdgeNode {
    int destIndex;        // which vertex this edge points to
    struct EdgeNode* next; // next neighbor
} EdgeNode;
```

### Vertex (one node in the graph)
```c
typedef struct Vertex {
    char name[20];    // label like "A", "Delhi"
    EdgeNode* head;   // head of its adjacency linked list
} Vertex;
```

### Layout in memory
```
vertexList[0] = { name:"A", head → [B] → [C] → NULL }
vertexList[1] = { name:"B", head → [D] → [A] → NULL }
vertexList[2] = { name:"C", head → [D] → [A] → NULL }
...
```

---

## Functions

| Function | Description |
|---|---|
| `addVertex(name)` | Add a new vertex to the graph |
| `addEdge(src, dest)` | Add undirected edge between two vertices |
| `removeEdge(src, dest)` | Remove edge between two vertices |
| `display()` | Print the full adjacency list |
| `BFS(start)` | Breadth First Search traversal |
| `DFS(start)` | Depth First Search traversal |

---

## BFS vs DFS

Given this graph:
```
    A
   / \
  B   C
  |   |
  D   D
      |
      E
```

### BFS (Breadth First Search)
- Uses a **queue**
- Visits level by level — all neighbors first, then their neighbors
- Output: `A → B → C → D → E`
- **Use case:** Shortest path in unweighted graph, social network levels

### DFS (Depth First Search)
- Uses **recursion** (implicit call stack)
- Dives as deep as possible before backtracking
- Output: `A → C → D → E → B`  *(order depends on list order)*
- **Use case:** Maze solving, cycle detection, topological sort

---

## How to Compile & Run

```bash
gcc graph.c -o graph
./graph
```

---

## Sample Output

```
=== Graph using Adjacency List ===

Vertex 'A' added.
Vertex 'B' added.
Vertex 'C' added.
Vertex 'D' added.
Vertex 'E' added.

Edge added: A <-> B
Edge added: A <-> C
Edge added: B <-> D
Edge added: C <-> D
Edge added: D <-> E

--- Adjacency List ---
[A    ] -> C -> B -> NULL
[B    ] -> D -> A -> NULL
[C    ] -> D -> A -> NULL
[D    ] -> E -> C -> B -> NULL
[E    ] -> D -> NULL
----------------------

BFS from 'A': A C B D E
DFS from 'A': A C D E B

Edge removed: C <-> D

BFS from 'A': A C B D E
DFS from 'A': A C B D E
```

---

## Complexity

| Operation | Time | Space |
|---|---|---|
| addVertex | O(1) | O(1) |
| addEdge | O(1) | O(1) |
| removeEdge | O(degree) | O(1) |
| BFS | O(V + E) | O(V) |
| DFS | O(V + E) | O(V) |
| display | O(V + E) | O(1) |

> V = number of vertices, E = number of edges

---

## Concepts Used

- **Structs** — `Vertex` and `EdgeNode`
- **Linked Lists** — Adjacency list per vertex
- **Dynamic Memory** — `malloc` / `free` for edge nodes
- **Array Queue** — Used in BFS
- **Recursion** — Used in DFS
- **String Handling** — `strcmp`, `strncpy` for vertex names

---

## Possible Extensions

- Add **weighted edges** (add a `weight` field to `EdgeNode`)
- Add **directed graph** support (remove the reverse edge in `addEdge`)
- Add **cycle detection** using DFS + color marking
- Add **shortest path** using BFS on weighted graph (Dijkstra)
- Add **removeVertex** function
