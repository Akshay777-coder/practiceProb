# Hash Table with Separate Chaining (C)

A simple hash table implementation in C using **separate chaining** (linked lists) for collision resolution.

---

## What is a Hash Table?

A hash table is a data structure that maps **keys to values** using a **hash function**. It enables near-constant time O(1) insertions, deletions, and lookups on average.

```
Key → hashFunction(key) → Index → Linked List (chain)
```

---

## Collision Handling: Separate Chaining

When two keys produce the same index, they are stored in a **linked list** at that slot. This is called a "chain".

```
Index 3 → [23] → [13] → NULL
Index 5 → [15] → NULL
Index 6 → [66] → [16] → NULL
```

---

## Project Structure

```
hash_table.c     ← Main source file (all code)
README.md        ← This file
```

---

## Functions

| Function | Description |
|---|---|
| `hashFunction(key)` | Returns `key % MAX` as the bucket index |
| `push(value)` | Inserts value at the front of the chain — O(1) |
| `pop(value)` | Removes first occurrence of value from its chain |
| `display()` | Prints all chains in the table |

---

## How to Compile & Run

```bash
gcc hash_table.c -o hash_table
./hash_table
```

---

## Sample Output

```
After insertions:
--- Hash Table State ---
[ 0] | NULL
[ 1] | 11 -> NULL
[ 2] | NULL
[ 3] | 23 -> 23 -> NULL
[ 4] | 24 -> NULL
[ 5] | 55 -> 15 -> NULL
[ 6] | 16 -> 66 -> NULL
[ 7] | 57 -> NULL
[ 8] | 18 -> NULL
[ 9] | 29 -> NULL
------------------------

After deleting 66 and 15:
--- Hash Table State ---
[ 0] | NULL
[ 1] | 11 -> NULL
...
[ 5] | 55 -> NULL
[ 6] | 16 -> NULL
...
```

---

## Known Bugs Fixed (from original code)

| Bug | Original | Fixed |
|---|---|---|
| Redundant line | `newNode->next = NULL` then overwritten | Removed unnecessary line |
| Wrong free in pop | `free(temp->next)` after bypassing it | Store in `toDelete`, then free correctly |
| No NULL check before traversal | Could segfault on empty chain | Added `if (current == NULL)` guard |
| No malloc failure check | Silent crash on OOM | Added `if (!newNode)` check |
| Infinite loop risk | `while(temp!=NULL)` with no `temp = temp->next` in original pop | Fixed traversal |

---

## Concepts Used

- **Structs** — `Node` with `data` and `next` pointer
- **Linked Lists** — One per hash bucket
- **Dynamic Memory** — `malloc` / `free`
- **Modulo Hashing** — `key % MAX`
- **Pointer Manipulation** — Head insertion, mid-chain deletion

---

## Time Complexity

| Operation | Average | Worst Case |
|---|---|---|
| Push | O(1) | O(1) |
| Pop | O(1) | O(n) |
| Search | O(1) | O(n) |

> Worst case occurs when all keys hash to the same index (full collision).
