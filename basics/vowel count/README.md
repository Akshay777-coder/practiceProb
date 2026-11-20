<h1>Count Vowels in a String (C Program)</h1>

<p>
This project demonstrates a simple C program that counts the number of vowels in a user-entered string.
It uses <code>fgets()</code> for safe input handling and <code>tolower()</code> to ensure case-insensitive vowel checking.
</p>

<h2>✨ Features</h2>
<ul>
    <li>Reads a string of up to 150 characters</li>
    <li>Converts characters to lowercase for accurate comparison</li>
    <li>Counts vowels: <strong>a, e, i, o, u</strong></li>
    <li>Handles invalid input safely</li>
</ul>

<h2>📌 How It Works</h2>
<p>The program:</p>
<ol>
    <li>Prompts the user to enter a string</li>
    <li>Processes each character one by one</li>
    <li>Checks if the character is a vowel</li>
    <li>Keeps a running total and prints the final count</li>
</ol>

<h2>▶️ How to Run</h2>
<pre>
gcc vowel_count.c -o vowel_count
./vowel_count
</pre>

<h2>📝 Example Output</h2>
<pre>
Enter a string: Hello World
Number of vowels: 3
</pre>

<p>
Feel free to improve or extend the logic—such as counting consonants, digits, or special characters!
</p>
