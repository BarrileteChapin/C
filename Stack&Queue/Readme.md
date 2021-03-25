Implementation of a Stack and Queue for doing some arithmetic operations: addition, substraction, multiplication, and division. 

Functions:

1. Implement Queue to store the expression elements

2. Dequeue N: Delete N elements from the Queue’s front (where N is an integer and 0<N<= the number of elements in current expression).

3. Enqueue E: Add the element E at the back of Queue. (E is an operator or operand).

4. Implement Stack that transforms expressions from infix to postfix and evaluates the expressions.

5. Implement the function to transform the expressions from infix to postfix.

6. Implement the function to evaluate the expressions.

7. Check if the expression is legal.

        Example:

        (1) Binary operation:

Legal: a*b (one operator with two operands)

Illegal: a*b* (the first operator * can perform binary operation with two operands. However, the second operator * cannott operate with only one operand)



        (2) Unmatched parenthesis:

               

8. Print: Retrieve all elements in queue as an expression, and determine if the expression is legal (8.1) or not (8.2)

- After retrieving all the elements, they are putted in a queue again for the upcoming commands.

8.1. If the expression is illegal, output the current expression (1) and the string “Invalid” (2).

8.2. If the expression is legal, output the current expression (1), expression postfix (2), and the result of the expression (3).

---------

°Input

1. N lines of commands where N<=100.

1.1. The first line is an expression.

1.2. The other lines are the commands, including Dequeue (followed by an integer), Enqueue (followed by an operator or operand) or Print.

2. The number of operators ( +, -, *, / ) in the expression (including the first line and any moment we perform an Enqueue or Dequeue operation) is smaller than 20; The number of operators ( ( , ) ) is smaller than 20 ;The number of operands is smaller than 20.

3. The expression does not contain any non-divisible condition.


4. All operands in the expressions are integers within [0,9].

5. The result of the expression.

-----------

°output

For output command “Print”, 
  
  - if the current expression is illegal -> print out the string “Invalid”;
  
  - If the expression is legal, print out the current expression, shift to newline;


--------------

-Date: 11/2020
