
# Handle refcount automagically using a cleanup attribute #

Dead simple example of using the `cleanup` attribute (supported by recent GCC
and Clang) to automagically decrement a reference count when a variable go out
of scope.

To run, first build with `python setup.py build` and then run something like
this:

```python
import sys
sys.path.append('build/lib.linux-x86_64-3.5/')
import watch

watch.demo()
```

The automatic refcount decrement using a simple macro (`watched`) to add a
cleanup attribute that causes the `decref` function to be called when the
`pObj` pointer goes out of scope.

```c
#define watched __attribute__((cleanup (decref)))
```

That's it...there's not really much here!
