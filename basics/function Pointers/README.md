<h1>Euclidean Distance & Circle Area Program</h1>

<p>This project demonstrates how to use <strong>function pointers</strong> in C along with a distance-calculation function to compute the <strong>Euclidean distance</strong> between two points and use it as the radius of a circle.</p>

<hr>

<h2>📌 Key Components</h2>

<h3>1. <code>Edistance()</code> Function</h3>
<p>The <code>Edistance</code> function calculates the Euclidean distance between two points <code>(x1, y1)</code> and <code>(x2, y2)</code>.  
It uses the standard formula:</p>

<pre>
distance = √((x2 - x1)² + (y2 - y1)²)
</pre>

<p>This calculated distance is returned and later used as the radius of a circle.</p>

<hr>

<h3>2. Using a <code>Function Pointer</code></h3>
<p>The program demonstrates how to pass a function as a parameter using a function pointer:</p>

<pre>
float (*ptr)(float, float, float, float);
ptr = &Edistance;
</pre>

<p>This pointer is then passed to another function that needs the distance calculation, making the code modular and reusable.</p>

<hr>

<h2>📐 Circle Area Calculation</h2>
<p>The distance returned by <code>Edistance()</code> is treated as the <strong>radius</strong> of a circle.  
Using this radius, the area is calculated as:</p>

<pre>
Area = π × radius²
</pre>

<p>This showcases how function pointers can be used to delegate mathematical operations inside another function.</p>

<hr>

<h2>🚀 How It Works (Summary)</h2>
<ol>
    <li>User gives two coordinate points.</li>
    <li>The <code>Edistance</code> function computes the distance.</li>
    <li>A function pointer sends this function to the circle-area function.</li>
    <li>The program prints the radius and computed area.</li>
</ol>

<hr>

<h2>📝 Purpose of the Program</h2>
