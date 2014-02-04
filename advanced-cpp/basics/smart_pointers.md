### Smart Pointers

```C++
foo(){

	int *p = new int;
	
	delete(p); //need to free memory else memory leak	
}

```

**c++ doesn't have garbage collector.**


```C++
int *q;

foo(){

	int *p = new int;
	q = p;
	/*q is still using the memory*/
	delete(p); //need to free memory else memory lea	
}

```

w.r.t to each pointer we store the number of references. Whenever num of references reaches 0, free the memory.

```
T
[         ]
  ^		^
  |     |
T *p  T *q
```

Different smartpointer variables will reference te same control block:

```
Smartpointer:
	ControlBlock * ctrl;

ControlBlock:
	T * ptr;
	count = 3	
```