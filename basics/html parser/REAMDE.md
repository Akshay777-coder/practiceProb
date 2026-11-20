<h1>HTML Tag Parser in C</h1>

<p>
This project demonstrates a simple <strong>HTML tag parser</strong> implemented in C.  
The parser removes HTML tags (&lt;...&gt;) from a given string and also trims extra spaces from the beginning and end of the text.
</p>

<h2>🚀 Features</h2>
<ul>
    <li>Removes HTML tags such as <code>&lt;h1&gt;</code>, <code>&lt;p&gt;</code>, etc.</li>
    <li>Extracts only the readable content between the tags.</li>
    <li>Trims extra spaces from the start and end of the processed string.</li>
</ul>

<h2>📌 How It Works</h2>
<p>
The program uses a parser function that scans the string character by character.  
When it detects a <code>&lt;</code>, it enters “tag mode” and ignores characters until it reaches a <code>&gt;</code>.  
Characters outside tags are stored back into the string.
</p>

<h2>🧩 Code Used</h2>

<pre>
#include &lt;stdio.h&gt;
#include &lt;string.h&gt;

void parser(char *string) {
    int in = 0; // checks if inside a tag
    int index = 0;

    for (int i = 0; i &lt; strlen(string); i++) {
        if (string[i] == '&lt;') {
            in = 1;
            continue;
        } else if (string[i] == '&gt;') {
            in = 0;
            continue;
        }
        if (in == 0) {
            string[index] = string[i];
            index++;
        }
    }
    string[index] = '\0';

    // Remove leading spaces
    while (string[0] == ' ') {
        for (int i = 0; i &lt; strlen(string); i++) {
            string[i] = string[i + 1];
        }
    }

    // Remove trailing spaces
    while (string[strlen(string) - 1] == ' ') {
        string[strlen(string) - 1] = '\0';
    }
}

int main() {
    char string[] = "&lt;h&gt;    This is a Heading    &lt;/h1&gt;";
    parser(string);
    printf("The parsed string is ~~%s~~", string);
    return 0;
}
</pre>

<h2>📝 Output</h2>
<p>
After running the program, the parser removes the tags and extra spaces, producing:
</p>

<pre>
The parsed string is ~~This is a Heading~~
</pre>

<h2>📖 Usage</h2>
<p>
Compile and run using:
</p>

<pre>
gcc parser.c -o parser
./parser
</pre>

<h2>✔️ Summary</h2>
<p>
This small C utility helps extract readable text from HTML-like formatted strings, making it useful for text processing and learning string manipulation in C.
</p>
