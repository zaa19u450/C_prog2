#define PY_SSIZE_T_CLEAN
#include "C:\Users\alena\AppData\Local\Programs\Python\Python38-32\include\Python.h"
#include "arr_lib.h"
#include <stdlib.h>

static PyObject* copy_to_py_list(const int *arr, int n)
{
    if (!arr)
        return NULL;
    PyObject *plist, *pitem;

    plist = PyList_New(n);
    if (!plist)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        pitem = PyLong_FromLongLong(arr[i]);
        if (!pitem)
        {
            Py_DECREF(plist);
            return NULL;
        }

        PyList_SET_ITEM(plist, i, pitem);
    }

    return plist;
}

//void fill_with_fib(int n, int *arr)
static PyObject* py_fill_with_fib(PyObject *self, PyObject *args)
{
    PyObject *plist;
    int n;
    int *pbuf;

    if (!PyArg_ParseTuple(args, "i", &n))
        return NULL;

    pbuf = malloc(n * sizeof(double));
    if (!pbuf)
        return NULL;

    fill_with_fib(n, pbuf);

    plist = copy_to_py_list(pbuf, n);

    free(pbuf);

    return plist;
}

//void take_first_occur(int *src, int src_len, int *dst, int *dst_len)
static PyObject* py_take_first_occur(PyObject *self, PyObject *args)
{
    PyObject *seq, *item, *item_int;
	
    int *src = NULL;
    int *dst = NULL;
    int n_src;
	int n_dst;

    // На вход - исходный масссив и длина нового массива
    if (!PyArg_ParseTuple(args, "Oi", &seq, &n_dst))
    {
        return NULL;
    }
    seq = PySequence_Fast(seq, "Argument must be iterable");
    if (!seq)
        return NULL;

    //получаем длину исходного массива
    n_src = PySequence_Fast_GET_SIZE(seq);

    // Преобразуем последовательность в массив int (если получится)
    src = malloc(n_src * sizeof(int));
    if (!src)
    {
        Py_DECREF(seq);
        return NULL;
    }

    for (int i = 0; i < n_src; i++)
    {
        item = PySequence_Fast_GET_ITEM(seq, i);
        if (!item)
        {
            Py_DECREF(seq);
            free(src);
            return NULL;
        }

        item_int = PyNumber_Long(item);
        if (!item_int)
        {
            Py_DECREF(seq);
            free(src);
            return NULL;
        }
        src[i] = PyLong_AS_LONG(item_int);

        Py_DECREF(item_int);
    }    
    // Освобождаем последовательность
    Py_DECREF(seq);

    //если нужно, выделяем память под dst
    if (n_dst > 0)
    {
        dst = malloc(n_dst * sizeof(int));
        if (!dst)
        {
            free(src);
            return NULL;
        }
    }
    //иначе возвращаем только необходимый размер
    else
    {
        take_first_occur(src, n_src, dst, &n_dst);
        return Py_BuildValue("i", n_dst);
    }

    take_first_occur(src, n_src, dst, &n_dst);

    PyObject *dst_tmp = copy_to_py_list(dst, n_dst);

    free(dst);
    free(src);

    //возвращаем новую длину и новый массив
    return Py_BuildValue("(iO)", n_dst, dst_tmp);

}

//Таблица методов модуля
static PyMethodDef arr_methods[] =
{
    {"fill_with_fib", py_fill_with_fib, METH_VARARGS, "filling an array with Fibonachi numbers"},
    {"take_first_occur", py_take_first_occur, METH_VARARGS, "leave first occurances of elements"},
    {NULL, NULL, 0, NULL}
};

// Структура, описывающая модуль
static struct PyModuleDef arr_dll_module =
{
    PyModuleDef_HEAD_INIT,
    "arr_dll", //Имя модуля
    "Array dlll module", //документация
    -1,
    arr_methods //таблица методов
};

//функция инициализации модуля
PyMODINIT_FUNC PyInit_arr_dll(void)
{
    return PyModule_Create(&arr_dll_module);
}
