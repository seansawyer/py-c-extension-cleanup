#include <Python.h>

#define watched __attribute__((cleanup (decref)))

void decref(PyObject **pObj)
{
    if (pObj == NULL || *pObj == NULL) {
        return;
    }
    printf("decrementing refcount for object: ");
    PyObject_Print(*pObj, stdout, 0);
    printf("\n");
    Py_DECREF(*pObj);
}

static PyObject * watch_demo(PyObject *self, PyObject *args)
{
    PyObject *pObj watched = NULL;
    pObj = PyBytes_FromString("I am a string.\n");
    printf("created an object: ");
    PyObject_Print(pObj, stdout, 0);
    printf("\n");
    Py_RETURN_NONE;
}

static PyMethodDef WatchMethods[] = {
    {"demo", watch_demo, METH_VARARGS, "Run the demo."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef WatchModule = {
    PyModuleDef_HEAD_INIT,
    "watch",
    NULL,
    -1,
    WatchMethods
};

PyMODINIT_FUNC PyInit_watch(void)
{
    return PyModule_Create(&WatchModule);
}
