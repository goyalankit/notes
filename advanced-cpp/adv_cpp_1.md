## Lecture 2


**Destructors**: release of resources

**Resource Acquisition Is Initialization (RAII)**

*From wikipedia:*

In this language, if an exception is thrown, and proper exception handling is in place, the only code that will be executed for the current scope are the destructors of objects declared in that scope.

RAII is vital in writing exception-safe C++ code: to release resources before permitting exceptions to propagate (in order to avoid resource leaks) one can write appropriate destructors once rather than dispersing and duplicating cleanup logic between exception handling blocks that may or may not be executed.

---

```c++
Semaphore sem;

mutex fun(){
	LockType mylock{sem};
}

```

***Everything in c++ is deep copy***

```c++
#include<iostream>
#include<cstdint>

using std::cout;
using std::endl;

struct String {

private:
	char* buffer{nullptr}; //*
	uint_32 len{0}; //+
	
public:
	String(void) = default; // String(void) {}
	
	explicit String(const char* input){ //explicit to stop type conversion.
		len = strlen(input);
		buffer = new char[len];
		for(unint32_t k=0; k<len; k+=1){
			buffer[k] = input[k];
		}
	}
	
	~String(void){
		delete buffer; //remove the memory
		//delete[] buffer'
	}
	
	void print(std::ostream& out){
		cout << "length is " << len << endl;
		if(buffer){
			for(unint32_t k=0 ; k<len;k+=1){
				out << buffer[k];
			}
		}
	}
}

std::ostream& operator<<(std::ostream &out, String& mystring){
	myString.print(out);
	return out;
}

int main(void){
	String s("Hello World!");
	cout << s << endl;
	
	String* myArray = new String[100]; // 804 bytes. first 4 bytes contain 100
	delete myArray; //calls the destrcutor once. Tries to delete the first element.
					//ideally should go back once more and then delete
					//This syntax doesn't work
					
	delete[] myArray; //this works!
		
}

```

* not-static members can be initialized now. //null ptr is better. 0 can be ambiguisly interpreted. 
+ {0} new syntax to initialize
* don't write default constructors unless you absolutely need.
* it's okay to leak memory in main. It will be reclaimed when process is removed from memory.

#### `delete vs delete[]`
you need to remember if buffer is a scalar or an array. You can't use delete[] with a scalar. Otherwise your program may crash. 

Compilers stores a metadata in front of array containing the length of array which helps in freeing memory.

**if all the scalars are treated as vectors. overheads:**

	* conditional parameter. but highly predictable
	* increase the size to store metadata.
	

If you allocate with `[]` delete with `[]` otherwise delete without `[]`.

In case of base types, it doesn't matter.

If the type doesn't have a desctructor. It doesn't generate loop to delete.

* Java doesn't have operator overloading.

### every constructor is a type convertor.

```c++

int main(void){
	String s("Hello World!");
	cout << s << endl;
	
	s = "oh my"; //type converted to string		
}


```

without `explicit` on constructor.

* object assignment is built in.
* const char* gets converted into string object. then do the default assignment.

with `explicit`

* code doesn't compile.

---

### double delete problem

**c++: object is pushed on stack.**

```c++
void doit(String t){
	cout << t << endl;
//	while(true); 
}

int main(void){
	String s("Hello World!");
	cout << s << endl;
	doit(s);
	cout << s << endl; //it got deleted in doit.
	while(true);
	
	s = "oh my"; //type converted to string		
}


```

default constructor to push on stack. 

**while pushing to stack**

```c++

//Shallow Copy

s [11]
  [  ] --------
	  		   |
		[HELLO WORLD]
			|
t [11]------
  [  ]
  
```

```c++

//Deep Copy

s [11]
  [  ] -------- [HELLO WORLD]
	  		   
		
			
t [11]------  [HELLO WORLD]
  [  ]
  
```

		
* Java everything is passed by reference. pointer.
* C++ assumes a copy.

#### why copy?

gives you more control. Copy can still work. You could copy the pointer or object itself.

Object that can be copied, you need to delete copy constructor.

```c++
String::String(const String &) //deep copy.
String::String(const String) //will recursively keep calling the same method.
```

```c++
/* Copy Semantics */

String(const String& that){
	copy(that);
}

String& operator=(const String& that){
	if(this != &that){
		destroy(); //x=x ; I destroyed x first.
		copy(that);	
	}
	return *this;
}

~String(void){
	destroy();
}

private:
	void copy(const String& that){
		this->len = that.len;
		if(len == 0){
			buffer = nullptr;
		}else{
			this->buffer = new char[len];
			for (uint32_t k=0; k<len; k+=1){
				out << buffer;
			}
		}		
	}

```

default assignment precedence. right -> left
a = b = c
