## What are Manipulators?
Manipulators are special functions in C++ that modify the behavior of an output stream (cout). For example, endl adds a newline, and setw sets the width of the output. You can also create custom manipulators to define your own behavior.

## Steps to Create a Custom Manipulator

1. Define a function that takes a reference to an ostream object as its parameter.
2. Perform the desired operation on the stream inside the function.
3. Return the same ostream reference to allow chaining.

## std::ostream(key points:)
It is the base class for all output streams in C++, such as std::cout (console output), std::ofstream (file output), and others.

## Commonly Used Streams:(just for idea)
std::cout: For standard console output.
std::cerr: For error output, usually unbuffered.
std::clog: For logging, usually buffered.

## Stream Insertion Operator (<<):
The << operator is overloaded in std::ostream to allow you to send data of various types (integers, floating-point numbers, strings, etc.) to the output stream.

## Chaining Operations:
Since std::ostream& is returned by the << operator, you can chain multiple output operations.