#include <iostream>

using namespace std;

/*
Write a function int binomial(int n, int k) that calculates the binomial coefficient n over k according to the formula formula.
Use the recursive function known from the lecture to calculate the factorial.

Write a variant of the binomial function that uses a recursion on the binomial coefficients, which is easily derived from Pascal's triangle and the binomial theorem. What advantage does this recursive variant have over the calculation using the formula above?

1				
1		1			
1		2		1		
1		3		3		1	
1		4		6		4		1
.				
.				
Pascal's triangle
Each entry is the sum of the two adjacent entries in the line above. The left and right are each filled with 1. The entries in the nth row correspond to the factors that occur in the resolution of the expression 
(a+b)^n. For example, (a+b)^4=a^4+4a^3b+6a^2b^2+4ab^3+b^4.
Since, on the other hand recursion, one easily obtains a recursion for the binomial coefficients.
(Here the properties of Pascal's triangle are simply assumed. In fact, Pascal's triangle has these properties because of the validity of recursion.)

Write another variant of the binomial function using the following formula
(if you always alternate division and multiplication, the entire calculation can be done in integers):
(n k) = ∏(i=1, k){(n - k + i) / i}

Which of the three versions of the binomial function would you use in practice?
*/

int main() {

    return 0;
}

/*
Input:


Output:

*/