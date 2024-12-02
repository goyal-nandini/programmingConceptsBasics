## What is o in ocean(const ocean &o)?
-> o is the existing object (already created object, like o1) that you want to copy from.
-> The copy constructor takes this object as input and copies its values to the new object (o2).

## Why const?
-> The const keyword ensures that the original object (o) passed to the copy constructor cannot be modified accidentally inside the copy constructor.
-> It’s like a safety lock. You can read from o, but you cannot change its data.

## Why &? (Reference)
-> Purpose: The & (reference) ensures that the original object (o1) is passed by reference rather than creating a duplicate copy.
-> Without the &, the copy constructor would try to copy the object, which could lead to infinite recursion (copy constructor calling itself repeatedly).

## Example:
Without &:

ocean(ocean o) {
    // Infinite loop: Copy constructor tries to copy"o",
    // which calls copy constructor again and again.
}
To avoid this problem, we pass the object by reference.

## What Does the Copy Constructor Do?
The copy constructor:

1. Receives the existing object o (like o1).

2. Copies the values of its attributes to the new object (o2).

For example:

## this->weather = o.weather;
Here:
# this->weather is the new object's (o2) weather.
Refers to the weather data member of the current object (this refers to the object being constructed, like o2 in this case).
This is where the value is being assigned.
# o.weather is the value of the existing object's (o1) weather.
Refers to the weather data member of the current object (this refers to the object being constructed, like o2 in this case).
This is where the value is being assigned.

## The weather data member of the current object (o2) is being set to the value of the weather data member of the existing object (o1).