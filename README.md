# 151884 - To Do list.

[Presentation](https://mrsimm0.github.io/oop-project-presentation/1)

This is a simple terminal application with simple self-made “GUI”. It allows user to add task, and delete it. Tasks are stored in text file.

This project is the first project for oop-course,it’s written in C++, and I tried to include most of topics we discussed during our classes.

### Constructors

Most of the classes have custom constructor. Only *MainView* class has one default constructor because main logic is stored there.

### Encapsulation

Every field in class is private so it can’t be accessed or changed directly. Only required field are exposed using designated methods. (I didn’t use any getters).

### Interfaces

I used headers files as interfaces. I know that Interfaces and Header files differ in behavior  - header class does not force you to write implementation to each function - but in my opinion this is the best way of implementing interfaces in C++ since this language does not have default structure to handle interfaces (we have to make classes containing only virtual methods). Athough I tried to add one abstract class to show inharetance.

### Immutability

I achieved immutability by creating whole new object when field or fields are to be changed. This is best visible when it comes to creating user interface.

### Exceptions

I used exceptions once - while checking user input for invalid input -  rest of exceptions are handled in C-like style - by returning error code to the handler which changes UI based on error.