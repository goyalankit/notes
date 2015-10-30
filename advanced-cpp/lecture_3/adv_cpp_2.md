### object that can't be copied

* file descriptors.

You need to remove/hide the copy methods in this case.


```
/* move Semantics */

String(String&& that){

}

String& operator=(const String&& that){
	return *this;
}

~String(void){
	destroy();
}

```

---

```
[ ][ ][ ][ ][ ][ ][ ]**[ ]**

remove an element from vector. 


```

what's the state of memory of last location. Destructor for the last element(object) is executed. This is what is done by language.

* You cannot implement `.` and `?` in c++. All other methods can be overloaded

operator execept new/delete -> there is no difference between operator syntax and function call systax.

function syntax just calls free. you don't need to deallocate.

operator syntax calls a destrctor and then frees.

operator syntax destroys the object and deallocate. function call syntax just deallocate

operator new allocates and then run constructor.
function syntax: runs a malloc and return void * pointer. You need to type cast and know the size of array you want.

```
# Further reading
http://www.scs.stanford.edu/~dm/home/papers/c++-new.html
```
