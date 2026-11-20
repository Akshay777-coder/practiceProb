/ =========================
/ BASICS
/ =========================

/ print
"hello world"

/ arithmetic
2+3
10-4
3*5
10%2

/ variables
a:10
b:20
a+b

/ =========================
/ LISTS (CORE OF K)
/ =========================

nums:1 2 3 4 5

/ element-wise ops
nums+10
nums*2

/ length
#nums

/ sum
+/nums

/ product
*/nums

/ min / max
|/nums
&/nums

/ indexing
nums[0]
nums[2]

/ =========================
/ FUNCTIONS
/ =========================

/ simple function
add:{x+y}
add[2;3]

/ lambda
{x*x} 5

/ multiple args
f:{x+y*z}
f[2;3;4]

/ =========================
/ CONTROL FLOW
/ =========================

/ conditional
{x>10?"big":"small"} 7

/ if-else
$[1<2;"yes";"no"]

/ =========================
/ ITERATION STYLE
/ =========================

/ each (map)
{x*2} each nums

/ filter
nums where nums>2

/ =========================
/ DICTIONARY
/ =========================

d:`name`age!("akshay";21)

/ access
d[`name]

/ =========================
/ STRINGS
/ =========================

s:"hello"
#s
s[0]

/ =========================
/ MATRIX
/ =========================

m:(1 2 3;4 5 6)
m*2

/ =========================
/ ADVANCED
/ =========================

/ average
avg:{(+/x)%#x}
avg 10 20 30

/ reverse
|nums

/ drop first
1 _ nums

/ take first 3
3#nums

/ unique
? 1 2 2 3 3 4

/ group (like SQL)
= `a`b`a`c`b

/ =========================
/ RECURSION
/ =========================

fact:{$[x=0;1;x*fact[x-1]]}
fact 5

/ =========================
/ REAL DATA STYLE
/ =========================

prices:100 200 150 300

/ returns (% change)
returns:100*(1 _ prices)%prices

/ moving sum (simple)
+/prices

/ =========================
/ ONE-LINERS (POWER)
/ =========================

/ square all
{x*x} each nums

/ sum of squares
+/ {x*x} each nums

/ =========================
/ END
/ =========================
