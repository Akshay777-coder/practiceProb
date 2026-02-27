<h1 align="center">Stack Implementation Using Linked List in C</h1>

<p align="center">
  A simple and efficient implementation of <b>Stack Data Structure</b> using 
  <b>Linked List</b> in C programming.
</p>

<hr>

<h2>📌 Overview</h2>

<p>
This project demonstrates the implementation of a <b>Stack</b> using a 
<b>Singly Linked List</b>. 
Unlike array-based stacks, this implementation does not have a fixed size limitation 
(other than available memory).
</p>

<p>
The stack follows the <b>LIFO (Last In First Out)</b> principle.
</p>

<hr>

<h2>⚙️ Features</h2>

<ul>
  <li>Push element onto stack (O(1))</li>
  <li>Pop element from stack (O(1))</li>
  <li>Peek top element</li>
  <li>Check if stack is empty</li>
  <li>Get stack size in O(1)</li>
  <li>Display stack elements</li>
</ul>

<hr>

<h2>🧠 Concepts Used</h2>

<ul>
  <li>Structures in C</li>
  <li>Dynamic Memory Allocation (<code>malloc</code>, <code>free</code>)</li>
  <li>Pointers</li>
  <li>Linked List</li>
  <li>Stack Data Structure (LIFO)</li>
  <li>Time Complexity Optimization (O(1) operations)</li>
</ul>

<hr>

<h2>🏗️ Data Structure Design</h2>

<h3>Node Structure</h3>

<pre>
struct Node {
    int data;
    struct Node* next;
};
</pre>

<ul>
  <li><b>data</b> → Stores stack value</li>
  <li><b>next</b> → Pointer to next node</li>
</ul>

<p>
A global pointer <code>top</code> keeps track of the top element of the stack.
</p>

<hr>

<h2>🚀 Operations Explained</h2>

<h3>1️⃣ Push Operation</h3>
<p>
Creates a new node and inserts it at the beginning of the linked list.
Time Complexity: <b>O(1)</b>
</p>

<h3>2️⃣ Pop Operation</h3>
<p>
Removes the node from the beginning and frees allocated memory.
Time Complexity: <b>O(1)</b>
</p>

<h3>3️⃣ Peek Operation</h3>
<p>
Displays the value stored at the top of the stack.
</p>

<h3>4️⃣ isEmpty()</h3>
<p>
Returns true if stack size is 0.
</p>

<h3>5️⃣ size()</h3>
<p>
Returns the current number of elements in the stack.
Maintained using a static variable for O(1) access.
</p>

<h3>6️⃣ display()</h3>
<p>
Traverses the linked list and prints all stack elements.
</p>

<hr>

<h2>📊 Time Complexity</h2>

<table border="1" cellpadding="8">
  <tr>
    <th>Operation</th>
    <th>Time Complexity</th>
  </tr>
  <tr>
    <td>Push</td>
    <td>O(1)</td>
  </tr>
  <tr>
    <td>Pop</td>
    <td>O(1)</td>
  </tr>
  <tr>
    <td>Peek</td>
    <td>O(1)</td>
  </tr>
  <tr>
    <td>Display</td>
    <td>O(n)</td>
  </tr>
</table>

<hr>

<h2>🖥️ Sample Output</h2>

<pre>
Stack: 50 -> 40 -> 30 -> 20 -> 10 -> NULL
Stack: 40 -> 30 -> 20 -> 10 -> NULL
Top element: 40
Size of stack: 4
Stack is Not Empty
</pre>

<hr>

<h2>🎯 Advantages of Linked List Stack</h2>

<ul>
  <li>No fixed size limitation</li>
  <li>Efficient memory usage</li>
  <li>All major operations are O(1)</li>
</ul>

<hr>

<h2>📌 Conclusion</h2>

<p>
This project clearly demonstrates how a stack can be implemented efficiently 
using a linked list in C. It avoids overflow issues seen in array-based stacks 
and maintains constant time complexity for core operations.
</p>

<hr>

<p align="center">
  💻 Developed for Data Structures and Algorithms Practice
</p>
