<h1 align="center">📚 Stack Implementation in C (Array Based)</h1>

<hr>

<h2>📌 Project Overview</h2>

<p>
This project demonstrates the implementation of a <b>Stack Data Structure</b> 
using an <b>Array</b> in the C programming language.
</p>

<p align="center">
<b>Stack follows the principle of LIFO (Last In, First Out)</b>
</p>

<p>
This means the element inserted last will be removed first.
</p>

<hr>

<h2>🧠 Concept Used</h2>

<h3>1️⃣ Stack Data Structure</h3>
<ul>
  <li>A stack is a <b>linear data structure</b>.</li>
  <li>Insertion operation is called <b>Push</b>.</li>
  <li>Deletion operation is called <b>Pop</b>.</li>
  <li>Only the <b>top element</b> can be accessed.</li>
</ul>

<h3>2️⃣ LIFO Principle</h3>
<p>
LIFO stands for <b>Last In, First Out</b>.  
The last inserted element is removed first.
</p>

<hr>

<h2>🏗️ Implementation Details</h2>

<h3>🔹 Maximum Size Definition</h3>

<pre>
#define MAX 5
</pre>

<ul>
  <li>Defines the maximum capacity of the stack.</li>
  <li>Stack size is fixed (Static Memory Allocation).</li>
</ul>

<h3>🔹 Global Variables</h3>

<pre>
int Stack[MAX];
int top = -1;
</pre>

<ul>
  <li><b>Stack[MAX]</b> → Array used to store stack elements.</li>
  <li><b>top</b> → Keeps track of the topmost element index.</li>
  <li>Initially, <b>top = -1</b> indicates stack is empty.</li>
</ul>

<hr>

<h2>⚙️ Functions Explanation</h2>

<h3>🔼 push(int value)</h3>

<p><b>Purpose:</b> Inserts a new element into the stack.</p>

<h4>Overflow Condition:</h4>
<pre>
if(top == MAX - 1)
</pre>

<ul>
  <li>If true → Stack is full → Prints <b>"OverFlow"</b></li>
  <li>Else → Increment top and insert value:</li>
</ul>

<pre>
Stack[++top] = value;
</pre>

<hr>

<h3>🔽 pop()</h3>

<p><b>Purpose:</b> Removes the top element from the stack.</p>

<h4>Underflow Condition:</h4>
<pre>
if(top == -1)
</pre>

<ul>
  <li>If true → Stack is empty → Prints <b>"UnderFlow"</b></li>
  <li>Else → Prints and removes top element:</li>
</ul>

<pre>
printf("Popped %d\n", Stack[top--]);
</pre>

<hr>

<h3>📊 display()</h3>

<p><b>Purpose:</b> Displays stack elements from top to bottom.</p>

<pre>
for(int i = top; i >= 0; i--)
</pre>

<ul>
  <li>Traverses from <b>top</b> to <b>0</b>.</li>
  <li>Prints elements in stack order.</li>
</ul>

<hr>

<h2>▶️ Program Execution Flow</h2>

<pre>
push(10);
push(20);
push(30);
display();
pop();
display();
</pre>

<h3>Execution Steps:</h3>

<ol>
  <li>Push 10 → Stack: 10</li>
  <li>Push 20 → Stack: 10 20</li>
  <li>Push 30 → Stack: 10 20 30</li>
  <li>Display → Output: 30 20 10</li>
  <li>Pop → Removes 30</li>
  <li>Display → Output: 20 10</li>
</ol>

<hr>

<h2>⚠️ Error Handling</h2>

<ul>
  <li><b>Overflow:</b> When trying to push into a full stack.</li>
  <li><b>Underflow:</b> When trying to pop from an empty stack.</li>
</ul>

<hr>

<h2>📌 Key Takeaways</h2>

<ul>
  <li>Demonstrates stack operations using arrays.</li>
  <li>Implements static memory allocation.</li>
  <li>Uses global variables for simplicity.</li>
  <li>Follows strict LIFO principle.</li>
</ul>

<hr>

<h2>🚀 Conclusion</h2>

<p>
This program provides a simple and clear implementation of the 
<b>Stack Data Structure</b> in C using arrays.  
It demonstrates how push, pop, and display operations work along with 
overflow and underflow conditions.
</p>
