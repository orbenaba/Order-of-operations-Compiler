# Order-of-operations-Compiler
How does the compiler know what is the order of the operations in an arithmetic expression?
For example, for the following expression
    A + B * C – D ^ 2
the compiler will use a temporary stack in for the calculation:
       
                Operation Operand1 Operand2 Result
                    *         B       C       Z
                    +         A       Z       Y
                    ^         D       2       X
                    –         Y       X       W
Explanation:
  first calculate (B*C) keep the result in Z
  second calculate (A+(B*C)) = (A+Z) keep the result in Y
  third calculate (D^2) keep the result in X
  fourth calculate (Y)-(X) keep the result
  
Note that the order of operations in a power sequence namely '^' is important, for example:
2^3^4 must be interpretered as 2^(3^4) and NOT as (2^3)^4 according to Math. rules.
** (2^3)^4 = 4096     &&&     2^(3^4) = 2^81   WOW!
To sum up, power operation is an extreme case that must take into account.
Enjoy!
