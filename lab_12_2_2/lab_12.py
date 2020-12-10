import ctypes
import tkinter as tk
import tkinter.messagebox as box

#загрузка библиотеки
lib = ctypes.CDLL('C:/msys64/home/alena/lab_12_2_2/libarr.dll')

#загрузка функций

#void fill_with_fib(int n, int *arr)
_fill_with_fib = lib.fill_with_fib
_fill_with_fib.argtypes = (ctypes.c_int, ctypes.POINTER(ctypes.c_int))
_fill_with_fib.restype = None

def fill_with_fib(n):
    arr = (ctypes.c_int * n)()
    _fill_with_fib(n, arr)
    return list(arr)


#void take_first_occur(int *src, int src_len, int *dst, int *dst_len)
_take_first_occur = lib.take_first_occur
_take_first_occur.argtypes = (ctypes.POINTER(ctypes.c_int),
                              ctypes.c_int,
                              ctypes.POINTER(ctypes.c_int),
                              ctypes.POINTER(ctypes.c_int))
_take_first_occur.restype = None

def take_first_occur(nums, how):
    n = len(nums)
    arr = (ctypes.c_int * n)(*nums)
    
    if (how == 1):
        n_res = ctypes.c_int(n)

    elif (how == 2):
        n_res = ctypes.c_int(0)
        _take_first_occur(arr, n, None, n_res)
    res = (ctypes.c_int * n_res.value)()
    _take_first_occur(arr, n, res, n_res)
                       
    return n_res, list(res)


def clean():
    entry_num.delete(0, tk.END)
    entry_res1.delete(0, tk.END)
    entry_res2.delete(0, tk.END)
    entry_arr.delete(0, tk.END)
    

def input_num():
    #ввод
    n = entry_num.get()
    try:
        n = int(n)
    except:
        box.showerror('Ошибка',"Количество элементов должно быть целым числом!")
        n = 0
        return 
    if n <= 0:
        box.showerror('Ошибка',"Количесвто элементов должно быть целым положительным числом")
        n = 0
        return
    
    #обработка
    arr = fill_with_fib(n)
    
    #вывод
    output_arr(arr, len(arr), entry_res1)


def input_arr():
    #ввод
    arr_str = entry_arr.get()
    try:
        arr = [int(x) for x in arr_str.split()]
    except:
        box.showerror('Ошибка',"Не удалось считать массив!")
        return
    n = len(arr)
    if n == 0:
        box.showerror('Ошибка',"Массив не может быть пустым!")
        return
    
    #обработка
    global how
    n_res, res = take_first_occur(arr, how.get())
    
    #вывод
    output_arr(res, n_res.value, entry_res2)
    
        
    
def output_arr(arr, n, where):
    where.delete(0, tk.END)
    for i in range(n):
        where.insert('insert', str(arr[i]) + ' ')


#создание окна
root = tk.Tk()            
root.title('Лабораторная работа 12, Вариант 2')       
root.geometry('750x600+10+10')
root['bg'] = ('mint cream')

# заполнение основной панели виджетами
#первое задание
lbl_task1= tk.Label(root,text = '1) Заполненить массив из n элементов числами Фибоначчи.',
    font='arial 13', justify = tk.LEFT, bd = 1, bg = 'LightBlue1')
lbl_task1.place(x = 10, y = 10, width = 730, height = 30, anchor= tk.NW)

lbl_num = tk.Label(root,text = 'Введите n:', 
    font='arial 13', justify = tk.LEFT, bg = 'mint cream')
lbl_num.place(x = 10, y = 50, width = 100, height = 30, anchor= tk.NW)

entry_num = tk.Entry(root, justify = tk.LEFT,
                     font='arial 13', bg = "CadetBlue1")
entry_num.place(x = 110, y = 50, width = 50, height = 30, anchor= tk.NW)

but_num = tk.Button(root, text = 'Ввести',font= 'arial 13', justify = tk.LEFT,
                  command = input_num, bg = 'SteelBlue1')
but_num.place(x = 200, y = 50, width = 100, height = 30)

lbl_res1= tk.Label(root,text = 'Результат:',
    font='arial 13', justify = tk.LEFT, bg = 'mint cream')
lbl_res1.place(x = 10, y = 100, width = 100, height = 30, anchor= tk.NW)

entry_res1 = tk.Entry(root, justify = tk.LEFT,
                     font='arial 13', bg = "CadetBlue1")
entry_res1.place(x = 110, y = 100, width = 600, height = 30, anchor= tk.NW)

# второе задание
lbl_task2= tk.Label(root,text = '2) Из исходного массива переместить во второй первое '
                    'вхождение каждого элемента.',
    font='arial 13', justify = tk.LEFT, bd = 1, bg = 'LightBlue1')
lbl_task2.place(x = 10, y = 170, width = 730, height = 30, anchor= tk.NW)

lbl_how = tk.Label(root,text = 'Как вызывающей стороне выделять память?',
    font='arial 13', justify = tk.LEFT, bd = 1, bg = 'mint cream')
lbl_how.place(x = 10, y = 210, width = 370, height = 30, anchor= tk.NW)

how = tk.IntVar() #how.get()
 
how1_checkbutton = tk.Radiobutton(text="оценить максимально возможный размера массива и выделить память с запасом",
                    value=1, variable=how, font='arial 13', justify = tk.LEFT, bd = 1, bg = 'mint cream')
how1_checkbutton.select()
how1_checkbutton.place(x = 10, y = 240, width = 670, height = 30, anchor= tk.NW)

how2_checkbutton = tk.Radiobutton(text="cначала вызвать функцию библиотеки, чтобы узнать требуемый размер массива,\n"
                               "затем выделить память и повторно вызвать функцию",
                    value=2, variable=how, font='arial 13', justify = tk.LEFT, bd = 1, bg = 'mint cream')
how2_checkbutton.place(x = 10, y = 270, width = 670, height = 60, anchor= tk.NW)


lbl_arr = tk.Label(root,text = 'Введите исходный массив (без запятых, через пробелы):',
    font='arial 13', justify = tk.LEFT, bg = 'mint cream')
lbl_arr.place(x = 10, y = 350, width = 450, height = 30, anchor= tk.NW)

entry_arr = tk.Entry(root, justify = tk.LEFT,
                     font='arial 13', bg = "CadetBlue1")
entry_arr.place(x = 10, y = 380, width = 480, height = 30, anchor= tk.NW)

but_arr = tk.Button(root, text = 'Ввести',font= 'arial 13', justify = tk.LEFT,
                  command = input_arr, bg = 'SteelBlue1')
but_arr.place(x = 500, y = 380, width = 100, height = 30)

lbl_res2 = tk.Label(root,text = 'Результат:',
    font='arial 13', justify = tk.LEFT, bg = 'mint cream')
lbl_res2.place(x = 10, y = 420, width = 100, height = 30, anchor= tk.NW)

entry_res2 = tk.Entry(root, justify = tk.LEFT,
                     font='arial 13', bg = "CadetBlue1")
entry_res2.place(x = 10, y = 450, width = 480, height = 30, anchor= tk.NW)

but_clean = tk.Button(root, text = 'Очистить все поля',font= 'arial 13', justify = tk.LEFT,
                  command = clean, bg = 'SteelBlue1')
but_clean.place(x = 10, y = 550, width = 160, height = 30)

#запуск цикла обработки событий
root.mainloop()