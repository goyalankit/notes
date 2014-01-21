From Stackoverflow. On default constructor.

if you do not define a constructor, the compiler will define a default constructor for you.

### The implementation of this default constructor is:

default construct the base class (if the base class does not have a default constructor, this is a compilation failure)
default construct each member variable in the order of declaration. (If a member does not have a default constructor, this is a compilation failure).
Note:
The POD data (int,float,pointer, etc.) do not have an explicit constructor but the default action is to do nothing (in the vane of C++ philosophy; we do not want to pay for something unless we explicitly ask for it).

If no destructor/copy Constructor/Assignment operator is defined the compiler builds one of those for you (so a class always has a destructor/Copy Constructor/Assignment Operator (unless you cheat and explicitly declare one but don't define it)).
The default implementation is:

### Destructor:

If user-defined destructor is defined, execute the code provided.
Call the destructor of each member in reverse order of declaration
Call the destructor of the base class.
### Copy Constructor:

Call the Base class Copy Constructor.
Call the copy constructor for each member variable in the order of declaration.
### Assignment Operator:

Call the base class assignment operator
Call the assignment operator of each member variable in the order of declaration.
Return a reference to this.
Note Copy Construction/Assignment operator of POD Data is just copying the data (Hence the shallow copy problem associated with RAW pointers).
