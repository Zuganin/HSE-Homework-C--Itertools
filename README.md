In the README file, I want to talk about the task that needed to be completed, my solution is in the range.h and range.cpp .

Implementation Details
You need to implement a Range (class or function) that returns an object of some class (you need to implement it) with certain begin and end methods.
These methods should return an iterator (it also needs to be implemented), which returns the corresponding integer value when dereferencing, and increases its state by step when incrementing (by default, step == 1).
Examples: for more examples, see the tests)

for (int i : Range(3)) { ... }  // i in [0, 1, 2]

for (int i : Range(3, 6)) { ... }  // i in [3, 4, 5]

for (int i : Range(3, 6, 2)) { ... }  // i in [3, 5]

for (int i : Range(6, 1, -2)) { ... }  // i in [6, 4, 2]
