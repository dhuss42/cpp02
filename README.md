# cpp02

CPP02 focused on implementing fixed-point arithmetic through a Fixed class that manages numbers with a fixed number of fractional bits using bit-shifting for conversion and arithmetic operations.
The subject emphasized precise representation and efficient manipulation of numbers without floating-point errors.
From now on, all classes must be designed in the Orthodox Canonical Form, unless explicitly stated otherwise.
This means every class should implement the following four member functions: Default constructor, Copy constructor, Copy assignment operator and Destructor

## ex 00 - My First Class in Orthodox Canonical Form

In this exercise, I implemented a Fixed class that followed the Orthodox Canonical Form.
The class contained a private integer to store a fixed-point number and a static constant representing the number of fractional bits, which I set to 8.

This exercise introduced me to the fixed-point number system, where values are scaled by 256 in my case. 
For example, to store 3.25, I multiplied it by 256, resulting in 832. 
This approach has several advantages: it avoids floating-point precision errors, is computationally faster, and is more memory-efficient since it uses integers rather than floats.

## ex01 - Towards a more useful fixed-point number class

In Exercise 01, I implemented the int constructor by shifting the integer input left by the number of fractional bits (fract_bits) to convert it into fixed-point format. 
This bit shifting works because shifting 1 left by x bits effectively multiplies by 2^x, allowing efficient scaling.
For the float constructor, I used roundf() to round the float input to the nearest integer before applying the same bit-shifting conversion. 
To convert the fixed-point value back to a floating-point number, I implemented the toFloat() method, which safely casts the internal integer to a float and divides by 2^fract_bits to retrieve the original decimal value.
I also overloaded the << operator to output the fixed-point number by inserting its float representation into the output stream. 

## ex02 - Now we’re talking

In Exercise 02, I completed the Fixed class by implementing arithmetic operators (+, -, *, /), adjusting bit shifts for multiplication and division to maintain proper scaling of the fixed-point values. 
Additionally, I overloaded comparison operators to compare fixed-point numbers based on their raw integer values. 
Finally, I implemented pre- and post-increment/decrement operators, as well as static min and max functions.

---
## Bonus

## ex03 - BSP

In Exercise 03, I implemented the Point class representing immutable 2D points using fixed-point coordinates. 
I provided constructors for default initialization, parameterized values, and copy construction, while disabling assignment to preserve immutability.
I then wrote the bsp function to determine whether a given point lies inside a triangle defined by three points.
To do this, I calculated vector cross products for each triangle edge and the test point, checking if all cross products had the same sign. 
