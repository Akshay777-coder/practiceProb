<h1 align="center">🔗 Linked List in C (Singly Linked List)</h1>

<h2>📖 Overview</h2>
<p>
This program implements a <b>Singly Linked List</b> in C language.
A linked list is a dynamic data structure where elements (nodes) are connected using pointers.
Unlike arrays, linked lists do not require continuous memory.
</p>

<ul>
  <li>Insert at beginning (push_front)</li>
  <li>Insert at end (push_back)</li>
  <li>Delete from beginning (pop_front)</li>
  <li>Delete from end (pop_back)</li>
  <li>Insert at specific position</li>
  <li>Update value</li>
  <li>Search element</li>
  <li>Display list</li>
  <li>Get size in O(1)</li>
</ul>

<hr>

<h2>🧠 What is a Linked List?</h2>

<p>
A <b>Linked List</b> is a collection of nodes where:
</p>

<ul>
  <li>Each node stores <b>data</b></li>
  <li>Each node stores a <b>pointer to next node</b></li>
</ul>

<p>
Structure used in this program:
</p>

<pre>
struct Node {
    int data;
    struct Node* next;
};
</pre>

<p>
So each node contains:
</p>

<ul>
  <li>📦 Data (integer value)</li>
  <li>🔗 Address of next node</li>
</ul>

<hr>

<h2>🌍 Global Variables Used</h2>

<ul>
  <li><b>head</b> → Points to first node</li>
  <li><b>tail</b> → Points to last node</li>
  <li><b>length</b> → Stores number of nodes</li>
</ul>

<p>
Using a <b>tail pointer</b> makes insertion at the end faster (O(1)).
Using a <b>length variable</b> allows size() function to work in O(1).
</p>

<hr>

<h2>⚙️ Functions Explained in Simple Words</h2>

<h3>1️⃣ createNode()</h3>
<p>
Creates a new node using dynamic memory allocation (malloc).
</p>

<ul>
  <li>Allocates memory</li>
  <li>Assigns data</li>
  <li>Sets next = NULL</li>
</ul>

<p><b>Time Complexity:</b> O(1)</p>

<hr>

<h3>2️⃣ push_front()</h3>
<p>
Inserts a new node at the beginning.
</p>

Steps:
<ol>
  <li>Create new node</li>
  <li>Make new node point to old head</li>
  <li>Update head</li>
</ol>

<p><b>Time Complexity:</b> O(1)</p>

<hr>

<h3>3️⃣ push_back()</h3>
<p>
Inserts a node at the end.
</p>

Steps:
<ol>
  <li>Create new node</li>
  <li>Old tail points to new node</li>
  <li>Update tail</li>
</ol>

<p>
Because of tail pointer, it works in <b>O(1)</b>.
</p>

<hr>

<h3>4️⃣ pop_front()</h3>
<p>
Removes first node.
</p>

Steps:
<ol>
  <li>Store current head</li>
  <li>Move head forward</li>
  <li>Free old node memory</li>
</ol>

<p><b>Time Complexity:</b> O(1)</p>

<hr>

<h3>5️⃣ pop_back()</h3>
<p>
Removes last node.
</p>

<ul>
  <li>Traverse to second last node</li>
  <li>Free last node</li>
  <li>Update tail</li>
</ul>

<p><b>Time Complexity:</b> O(n)</p>

<hr>

<h3>6️⃣ insert(value, position)</h3>
<p>
Inserts a node at a specific index.
</p>

<ul>
  <li>Check valid position</li>
  <li>Traverse to (position - 1)</li>
  <li>Adjust pointers</li>
</ul>

<p><b>Time Complexity:</b> O(n)</p>

<hr>

<h3>7️⃣ update(value, position)</h3>
<p>
Updates the value of node at given position.
</p>

<ul>
  <li>Validate position</li>
  <li>Traverse to that index</li>
  <li>Change data</li>
</ul>

<p><b>Time Complexity:</b> O(n)</p>

<hr>

<h3>8️⃣ search(key)</h3>
<p>
Finds an element in the list using <b>Linear Search</b>.
</p>

<ul>
  <li>Traverse node by node</li>
  <li>If found → return index</li>
  <li>If not found → return -1</li>
</ul>

<p><b>Time Complexity:</b> O(n)</p>

<hr>

<h3>9️⃣ size()</h3>
<p>
Returns total number of nodes.
</p>

<p>
Because we maintain a <b>length variable</b>, this works in <b>O(1)</b>.
</p>

<hr>

<h3>🔟 display()</h3>
<p>
Prints the entire linked list.
</p>

Example Output:
<pre>
20 -> 10 -> 30 -> 40 -> NULL
</pre>

<p><b>Time Complexity:</b> O(n)</p>

<hr>

<h2>📊 Sample Execution Flow</h2>

<pre>
push_front(10)
push_front(20)
push_back(30)
push_back(40)

Output:
20 -> 10 -> 30 -> 40 -> NULL

After pop_front():
10 -> 30 -> 40 -> NULL

Insert 22 at position 2:
10 -> 30 -> 22 -> 40 -> NULL

Search(30) → returns index
Search(67) → returns -1
</pre>

<hr>

<h2>⚠️ Important Concepts Used</h2>

<ul>
  <li>Dynamic Memory Allocation (malloc)</li>
  <li>Pointers</li>
  <li>Structures</li>
  <li>Manual memory management (free)</li>
  <li>Time Complexity analysis</li>
</ul>

<hr>

<h2>🚀 Why Linked List is Important?</h2>

<ul>
  <li>No fixed size limitation</li>
  <li>Efficient insertion/deletion</li>
  <li>Foundation for stacks, queues, graphs</li>
</ul>

<hr>

<h2>🎯 Learning Outcomes</h2>

<ul>
  <li>Understanding dynamic data structures</li>
  <li>Mastering pointer manipulation</li>
  <li>Improving problem solving in DSA</li>
</ul>

<hr>

<h2>🏁 Conclusion</h2>
<p>
This program builds a strong foundation in:
</p>

<ul>
  <li>Linked List implementation</li>
  <li>Pointer handling</li>
  <li>Memory management in C</li>
</ul>

<p>
Linked Lists are one of the most important topics in <b>Data Structures & Algorithms (DSA)</b>.
Mastering this will help in advanced topics like stacks, queues, trees and graphs.
</p>
