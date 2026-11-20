<h1 align="center">📌 Array Operations in C</h1>

<h2>📖 Overview</h2>
<p>
This program demonstrates basic <b>Array Operations</b> in the C programming language.
It performs the following operations on a static array:
</p>

<ul>
  <li>Insertion at a given position</li>
  <li>Deletion from a given position</li>
  <li>Update at a given position</li>
  <li>Search an element</li>
  <li>Display array elements</li>
</ul>

<hr>

<h2>🧠 Concept Used in This Code</h2>

<h3>1️⃣ Static Array Concept</h3>
<p>
The program uses a <b>static array</b> of fixed size defined using:
</p>

<pre>
#define MAX 10
</pre>

<p>
This means the array can store a maximum of 10 elements.
Since C arrays have fixed size, we manually manage:
</p>

<ul>
  <li>Current number of elements (<b>n</b>)</li>
  <li>Overflow condition</li>
  <li>Underflow condition</li>
</ul>

<hr>

<h3>2️⃣ Pass By Reference (Using Pointers)</h3>
<p>
For insertion and deletion, the size of the array (<b>n</b>) changes.
To modify it inside functions, we pass its address:
</p>

<pre>
void insert(int arr[], int *n, int pos, int value)
</pre>

<p>
Here, <b>*n</b> allows the function to update the original size variable.
</p>

<hr>

<h3>3️⃣ Insertion Logic</h3>
<p>
To insert an element at a specific position:
</p>

<ol>
  <li>Check for <b>Array Overflow</b></li>
  <li>Validate position</li>
  <li>Shift elements to the right</li>
  <li>Insert value</li>
  <li>Increase size (n++)</li>
</ol>

<p><b>Time Complexity:</b> O(n)</p>

<hr>

<h3>4️⃣ Deletion Logic</h3>
<p>
To delete an element:
</p>

<ol>
  <li>Check for <b>Array Underflow</b></li>
  <li>Validate position</li>
  <li>Shift elements to the left</li>
  <li>Decrease size (n--)</li>
</ol>

<p><b>Time Complexity:</b> O(n)</p>

<hr>

<h3>5️⃣ Update Logic</h3>
<p>
Updating is simple:
</p>

<ul>
  <li>Validate position</li>
  <li>Replace value at that index</li>
</ul>

<p><b>Time Complexity:</b> O(1)</p>

<hr>

<h3>6️⃣ Search Logic (Linear Search)</h3>
<p>
The program uses <b>Linear Search</b> to find an element in the array.
</p>

<ol>
  <li>Traverse the array from index 0 to n-1</li>
  <li>Compare each element with the target value</li>
  <li>If found, return its position</li>
  <li>If not found, display "Element not found"</li>
</ol>

<p>
Linear Search is suitable here because:
</p>

<ul>
  <li>The array is not necessarily sorted</li>
  <li>The size is small (MAX = 10)</li>
</ul>

<p><b>Time Complexity:</b> O(n)</p>

<hr>

<h3>7️⃣ Display Function</h3>
<p>
Traverses the array from index 0 to n-1 and prints elements.
</p>

<p><b>Time Complexity:</b> O(n)</p>

<hr>

<h2>⚙️ Error Handling Implemented</h2>

<ul>
  <li>Array Overflow (when array is full)</li>
  <li>Array Underflow (when array is empty)</li>
  <li>Invalid Position checks</li>
  <li>Element Not Found in search</li>
</ul>

<hr>

<h2>📊 Sample Execution Flow</h2>

<pre>
Initial Array: 1 2 3 4 5

After insert at position 2:
1 2 12 11 3 4 5

After delete at position 2:
1 2 11 3 4 5

After update at position 2:
1 2 100 3 4 5

Searching for 100:
Element found at position 2
</pre>

<hr>

<h2>🎯 Learning Outcomes</h2>

<ul>
  <li>Understanding manual memory handling in arrays</li>
  <li>Implementing dynamic behavior using static arrays</li>
  <li>Using pointers to modify variables in functions</li>
  <li>Understanding time complexity of array operations</li>
  <li>Implementing Linear Search algorithm</li>
</ul>

<hr>

<h2>🚀 Conclusion</h2>
<p>
This program builds a strong foundation for understanding:
</p>

<ul>
  <li>Data Structures</li>
  <li>Array Manipulation</li>
  <li>Pointer Concepts in C</li>
  <li>Searching Algorithms</li>
</ul>

<p>
These concepts are essential for mastering <b>DSA (Data Structures & Algorithms)</b>.
</p>
