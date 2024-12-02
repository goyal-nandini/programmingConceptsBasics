 ## Class Body is for Declarations, Not Executions
 
 class defines the blueprint for objects. It contains:
 1. Data members (variables to store data).
 2. Member functions (methods that operate on the data).
 The body of a class is meant to declare what an object can do, not perform actions.
 Actions or executable statements (like cout) belong inside "member functions".

## important:
A class is like a blueprint, not the actual building. When defining the blueprint, you can’t place actions like "paint the wall" directly in the blueprint; you specify it in the constructor or a method

## important:
Why Can't cout Be Used Directly in Class?
Because the class body is not a part of the program’s execution flow. Only the functions inside the class (or objects of the class) interact with the runtime execution flow.

in-class initialization is allowed in modern cpp