CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -pedantic
OUTPATH := ./out/
UNIPATH := ./unit_tests/
LIBPATH := ./dll/

INC := -I .$(LIBPATH)

#библиотека

$(OUTPATH)arr_lib.o : $(LIBPATH)arr_lib.c
	cd out && $(CC) $(CFLAGS) $(INC) -D ARR_EXPORTS -c .$(LIBPATH)arr_lib.c
libarr.dll : $(OUTPATH)arr_lib.o
	$(CC) -shared $(OUTPATH)arr_lib.o -Wl,--subsystem,windows -o libarr.dll
	
#очистка
.PHONY : clean 
clean :
	$(RM) $(OUTPATH)*.o *.exe *.d *.dll
	
	
	
	
#тестирование	

#сборка приложения для тестирования	
unit_tests.exe : $(OUTPATH)check_main.o $(OUTPATH)check_fill_with_fib.o $(OUTPATH)check_take_first_occur.o libarr.dll $(OUTPATH)arr_lib.o
	$(CC) $(OUTPATH)check_main.o $(OUTPATH)check_fill_with_fib.o $(OUTPATH)check_take_first_occur.o -o unit_tests.exe -L . -larr -lcheck
	
#компиляция модулей для тестирования
$(OUTPATH)check_%.o : $(UNIPATH)check_%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<
	
# сборка и прогон модульных тестов	
.PHONY : unit 	
unit : unit_tests.exe
	./unit_tests.exe
# сборка и прогон модульных тестов с проверкой drmemory
.PHONY : check_mem_unit 
check_mem_unit : unit_tests.exe
	drmemory -lib_blacklist "*" -batch -- ./unit_tests.exe
	
