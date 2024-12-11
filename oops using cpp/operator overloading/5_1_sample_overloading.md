## the issue in 5_.....cpp
The issue in your code is that you’re trying to overload the << and >> operators as member functions, but this doesn't work directly for the cin and cout streams, because they are not members of your myClass class. 
## The >> and << operators typically need to be friend functions in such cases, because they need access to cin and cout stream objects, which aren't part of the class itself.

Correct Approach: Overloading the << and >> operators as friend functions.

## Return Type (istream& or ostream&): 
This allows chaining of operations by returning the same stream object (e.g., cin or cout) after an operation.

## Parameter Type (istream& or ostream&): 
This lets the operator function access the stream from which data is being read (for >>) or to which data is being written (for <<).

--> "istream and ostream" are "classes" defined in "iostream.h" file which has been included in the program.

--> "cin and cout" are objects of "istream and ostream" respectively.