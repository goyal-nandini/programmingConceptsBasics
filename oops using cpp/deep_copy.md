for oops7_3:
Issue

## id and sex are local variables:

1. id and sex are created within the constructor but are not assigned to the class member variables name and gender.
2. Once the constructor finishes, id and sex are destroyed, and their allocated memory becomes inaccessible.

#### Key Points to Remember
1. When implementing a deep copy, ensure the dynamically allocated memory is assigned directly to the object's member variables.
2. Avoid using temporary local variables(here, id and sex) that do not affect the class members.
3. Properly free allocated memory in the destructor to prevent memory leaks.


for oops7_3_1:
## Key Points:
1.String literals are sequences of characters enclosed in double quotes ("..."), and they are constant by default.
2. They are of type const char[] (read-only).
3. You should use const char* for parameters or variables that will point to string literals to avoid warnings and potential issues.





