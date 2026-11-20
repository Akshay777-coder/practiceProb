<h1>Rectangle Class in C using Structures</h1>

<p>This project demonstrates how to simulate a <strong>class-like structure</strong> in C programming using <code>struct</code>, along with functions that act as class methods.</p>

<h2>📌 Features</h2>
<ul>
    <li>Defines a <code>Rectangle</code> structure with <strong>length</strong> and <strong>width</strong>.</li>
    <li>Uses <strong>pointers</strong> to initialize structure members.</li>
    <li>Implements functions that act like class methods:
        <ul>
            <li><code>initialise_value()</code> – sets length & width</li>
            <li><code>Display()</code> – prints length, width & area</li>
        </ul>
    </li>
</ul>

<h2>📘 Code</h2>

<pre>
<code>
#include&lt;stdio.h&gt;

//making a Class Using Structure
struct Rectangle{
    float length;
    float width;
};

//Initialising the value using "initialise_value" method with the help of pointers
void initialise_value(struct Rectangle *r,float l,float w){
    r-&gt;length = l;
    r-&gt;width = w;
}

//Displaying the values using "display" method
float Display(struct Rectangle *r){
    printf("Length is: %.2f\n",r-&gt;length);
    printf("Width is: %.2f\n",r-&gt;width);
    printf("Area is: %.2f\n\n",r-&gt;length * r-&gt;width);
}

int main()
{
    //defining the object for with our class
    struct Rectangle r1;
    
    //storing the values using "initialise_value" method
    initialise_value(&amp;r1,15.22,9.67);
    
    //displaying the values using "Display" method
    Display(&amp;r1);
    
    return 0;
}
</code>
</pre>

<h2>🧾 Output</h2>
<pre>
Length is: 15.22
Width is: 9.67
Area is: 147.23
</pre>

<h2>📍 Summary</h2>
<p>This example shows how to mimic object-oriented programming in C by using <strong>structures + functions + pointers</strong>.  
It demonstrates encapsulation-like behavior and method-style function usage.</p>
