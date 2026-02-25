<h1 align="center">🌳 Binary Tree Implementation in C</h1>

<hr>

<h2>📌 Introduction</h2>
<p>
This project demonstrates the implementation of a <b>Binary Tree</b> in C language.
It covers:
</p>
<ul>
  <li>Structure of a Binary Tree Node</li>
  <li>Dynamic Memory Allocation</li>
  <li>Building a Tree using Preorder Traversal</li>
  <li>Tree Traversal Techniques (DFS & BFS)</li>
</ul>

<hr>

<h2>🌳 What is a Binary Tree?</h2>
<p>
A <b>Binary Tree</b> is a hierarchical data structure where:
</p>
<ul>
  <li>Each node contains data</li>
  <li>Each node has at most two children</li>
  <li>Children are called <b>Left Child</b> and <b>Right Child</b></li>
</ul>

<p>
It is widely used in searching, sorting, expression trees, and hierarchical data representation.
</p>

<hr>

<h2>🏗 Structure of a Node</h2>

<pre>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
</pre>

<h3>Explanation:</h3>
<ul>
  <li><b>data</b> → Stores integer value.</li>
  <li><b>left</b> → Pointer to left child node.</li>
  <li><b>right</b> → Pointer to right child node.</li>
</ul>

<p>
This structure forms the basic building block of the Binary Tree.
</p>

<hr>

<h2>🧠 Dynamic Memory Allocation</h2>

<pre>
struct Node* createNode(int value)
</pre>

<h3>Concept Used:</h3>
<ul>
  <li><b>malloc()</b> from stdlib.h is used.</li>
  <li>Memory is allocated at runtime.</li>
  <li>Returns pointer to newly created node.</li>
</ul>

<p>
Dynamic memory allocation allows the tree to grow during program execution.
</p>

<hr>

<h2>🌲 Building Tree using Preorder</h2>

<pre>
struct Node* buildTree(int preorder[])
</pre>

<h3>Concepts Used:</h3>
<ul>
  <li>Recursion</li>
  <li>Preorder Traversal Logic</li>
  <li>Static Global Index</li>
  <li>Base Condition</li>
</ul>

<h3>How It Works:</h3>
<ol>
  <li>Index increases sequentially.</li>
  <li>If value is -1 → return NULL (no node).</li>
  <li>Create node with current value.</li>
  <li>Recursively build left subtree.</li>
  <li>Recursively build right subtree.</li>
</ol>

<p>
<b>-1</b> represents NULL node in the tree.
</p>

<hr>

<h2>🔁 Tree Traversals (Depth First Search - DFS)</h2>

<h3>1️⃣ Preorder Traversal (Root → Left → Right)</h3>
<pre>
void preOrder(struct Node* root)
</pre>
<p>
Print root first, then recursively visit left and right subtree.
</p>

<h3>2️⃣ Inorder Traversal (Left → Root → Right)</h3>
<pre>
void inOrder(struct Node* root)
</pre>
<p>
Visit left subtree, print root, then visit right subtree.
</p>

<h3>3️⃣ Postorder Traversal (Left → Right → Root)</h3>
<pre>
void postOrder(struct Node* root)
</pre>
<p>
Visit both subtrees first, then print root node.
</p>

<hr>

<h2>📶 Level Order Traversal (Breadth First Search - BFS)</h2>

<pre>
void levelOrder(struct Node* root)
</pre>

<h3>Concepts Used:</h3>
<ul>
  <li>Queue Data Structure</li>
  <li>FIFO Principle (First In First Out)</li>
  <li>Iterative Traversal</li>
</ul>

<h3>How It Works:</h3>
<ol>
  <li>Insert root into queue.</li>
  <li>Remove front node.</li>
  <li>Print node data.</li>
  <li>Insert left child (if exists).</li>
  <li>Insert right child (if exists).</li>
  <li>Repeat until queue becomes empty.</li>
</ol>

<p>
This traversal prints nodes level by level.
</p>

<hr>

<h2>🧪 Main Function Explanation</h2>

<pre>
int preorder[] = {1,2,-1,3,-1,-1,4,-1,5,-1,-1};
</pre>

<p>
This array represents tree in preorder format where:
</p>
<ul>
  <li>Numbers = Node values</li>
  <li>-1 = NULL (no child)</li>
</ul>

<p>
Steps in main():
</p>
<ol>
  <li>Build tree using buildTree().</li>
  <li>Call all traversal functions.</li>
  <li>Print results on screen.</li>
</ol>

<hr>

<h2>⏱ Time Complexity</h2>

<table border="1" cellpadding="8">
<tr>
<th>Operation</th>
<th>Time Complexity</th>
</tr>
<tr>
<td>Building Tree</td>
<td>O(n)</td>
</tr>
<tr>
<td>Preorder</td>
<td>O(n)</td>
</tr>
<tr>
<td>Inorder</td>
<td>O(n)</td>
</tr>
<tr>
<td>Postorder</td>
<td>O(n)</td>
</tr>
<tr>
<td>Level Order</td>
<td>O(n)</td>
</tr>
</table>

<p>
Each node is visited exactly once.
</p>

<hr>

<h2>🎯 Concepts Covered in This Project</h2>

<ul>
  <li>Binary Tree Data Structure</li>
  <li>Pointers</li>
  <li>Dynamic Memory Allocation</li>
  <li>Recursion</li>
  <li>Depth First Search (DFS)</li>
  <li>Breadth First Search (BFS)</li>
  <li>Queue Implementation using Array</li>
</ul>

<hr>

<h2>🚀 Conclusion</h2>

<p>
This project provides a complete understanding of Binary Trees in C.
It demonstrates how trees are built, traversed, and processed using both
recursive and iterative approaches.
</p>

<p align="center">
⭐ Great practice project for mastering Data Structures in C!
</p>
