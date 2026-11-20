<h1>Array Split Program in C</h1>

<p>
This program demonstrates how to split a parent array into two child arrays in the C programming language.
The parent array contains 10 integers, and the goal is to divide it into two equal parts (first 5 elements and last 5 elements).
</p>

<h2>🧾 Program Overview</h2>

<p>
The program performs the following actions:
</p>

<ul>
  <li>Creates a parent array with 10 elements.</li>
  <li>Defines two child arrays, each with a size of 5.</li>
  <li>Copies the first half of the parent array into the first child array.</li>
  <li>Copies the second half of the parent array into the second child array.</li>
  <li>Prints all the arrays on the screen.</li>
</ul>

<h2>📌 C Program Code</h2>

<pre>
<code>
#include&lt;stdio.h&gt;

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int arr1[5];
    int arr2[5];
    
    size_t length = sizeof(array) / sizeof(array[0]);
    
    printf("Size of Parent array:- %zu\n\n",length);
    
    printf("Parent Array:- ");
    for(int i = 0;i &lt; length;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    
    for(int i = 0;i &lt; length/2;i++){
        arr1[i] = array[i];
    }
    printf("First Child Array:- ");
    for(int i = 0;i &lt; length/2;i++){
        printf("%d ",arr1[i]);
    }
    printf("\n");

    for(int i = length/2;i &lt; length;i++){
        arr2[i - length/2] = array[i];   // corrected index
    }
    printf("Second Child Array:- ");
    for(int i = 0;i &lt; length/2;i++){
        printf("%d ",arr2[i]);
    }
    printf("\n");

    return 0;
}
</code>
</pre>

<h2>⚠️ Important Correction</h2>

<p>
In the original code, the second child array was assigned incorrectly using <code>arr2[i]</code>.
The corrected version uses <code>arr2[i - length/2]</code> to store values properly.
</p>

<h2>📤 Output Example</h2>

<pre>
Size of Parent array:- 10

Parent Array:- 1 2 3 4 5 6 7 8 9 10
First Child Array:- 1 2 3 4 5
Second Child Array:- 6 7 8 9 10
</pre>

<h2>✔️ Summary</h2>

<p>
This program is a simple demonstration of array manipulation and splitting in C.  
It helps beginners understand array indexing, copying elements, and printing results.
</p>
