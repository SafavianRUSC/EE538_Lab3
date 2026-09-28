# Lab 3 README

Name: Rosstin Safavian
Student ID: 9177419185
Email: safavian@usc.edu

## Summary

matrix.cpp reads two 10 by 10 matrices, adds them, and prints the result. 

people.cpp stores Student and Teacher objects (with public and private elements) through Person pointers and uses virtual functions to print their information and introductions.

## Compile

```text
g++ -std=c++17 -Wall -Wextra -pedantic matrix.cpp -o matrix
g++ -std=c++17 -Wall -Wextra -pedantic people.cpp -o people
```

## Run

```text
./matrix < samples/matrix.in
./people < samples/people.in
```

## References

Course notes (primarily the lecture and lab slides) , and ChatGPT to review code and debug

## Non-working Parts

None that I am aware of

## Q4 Questions

1. Private matrix data does not let code outside the class change the array directly, with public methods giving specific access. mat_add() can access other.value because it is a member of the matrix class, main cannot because it is not a member of the matrix class

2. if Student inheritance was now private, s.getName() would not be allowed from main() because the public getName from person becomes private in student, so it would not have access. Person* p = &s would not work either, since the base class is now private.

3. because displayInfo() is a purely virtual function, you cannot creat a person object, just a person pointer towards Student/Teacher. if virtual was removed from person and override from derived declerations, then a Person* would call the Person's implementation directly.

Construction order: When constructing a Student, the Person constructor runs first and the Student constructor runs second. Destruction happens in reverse order, and the Person destructor must be virtual so deleting through Person* destroys the full Student object correctly. (as lecture mentioned, "builds" bottom (base class) up but "destroys" top (derived class) down).












