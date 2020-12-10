CC := gcc
#CFLAGS := -std=c99 -Wall -Werror -Wextra -Wfloat-equal -pedantic -Wfloat-conversion -Wvla -Wno-cast-function-type
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -pedantic
INCPATH := ../inc/
OUTPATH := ./out/
SRCPATH := ./src/
UNIPATH := ./unit_tests/
LIBPATH := ./lib/
STATICPATH := ./static/
DYN1PATH := ./dyn1/
DYN2PATH := ./dyn2/

SRCS := $(wildcard *.c)
INC := -I $(INCPATH)
LIB := -L $(OUTPATH)

# cтатическая библиотека

#компиляция модулей для библитоеки
$(STATICPATH)$(OUTPATH)processing.o : $(STATICPATH)$(LIBPATH)processing.c
	cd static && cd out && $(CC) $(CFLAGS) $(INC) -c ../$(LIBPATH)processing.c
$(STATICPATH)$(OUTPATH)file_io.o : $(STATICPATH)$(LIBPATH)file_io.c
	cd static && cd out && $(CC) $(CFLAGS) $(INC) -c ../$(LIBPATH)file_io.c
#компиляция основных модулей
$(STATICPATH)$(OUTPATH)app.o : $(STATICPATH)$(SRCPATH)app.c
	cd static && cd out && $(CC) $(CFLAGS) $(INC) -c ../$(SRCPATH)app.c
$(STATICPATH)$(OUTPATH)int_cmp.o : $(STATICPATH)$(SRCPATH)int_cmp.c
	cd static && cd out && $(CC) $(CFLAGS) $(INC) -c ../$(SRCPATH)int_cmp.c
# упаковка статической библиотекой + индексирование (для ускорения работы компоновщика)
$(STATICPATH)$(OUTPATH)libstatic.a : $(STATICPATH)$(OUTPATH)processing.o $(STATICPATH)$(OUTPATH)file_io.o
	cd static && cd out && ar cr libstatic.a processing.o file_io.o
	ranlib $(STATICPATH)$(OUTPATH)libstatic.a
# сборка приложения
app_static.exe : $(STATICPATH)$(OUTPATH)app.o $(STATICPATH)$(OUTPATH)int_cmp.o $(STATICPATH)$(OUTPATH)libstatic.a
	$(CC) $(STATICPATH)$(OUTPATH)app.o $(STATICPATH)$(OUTPATH)int_cmp.o -o app_static.exe -L $(STATICPATH)$(OUTPATH) -lstatic 
	
#динамическая библиотека 1 - динамическая компоновка

#компиляция модулей для библитоеки
$(DYN1PATH)$(OUTPATH)processing.o : $(DYN1PATH)$(LIBPATH)processing.c
	cd dyn1 && cd out && $(CC) $(CFLAGS) -D PR_EXPORTS $(INC) -c ../$(LIBPATH)processing.c
$(DYN1PATH)$(OUTPATH)file_io.o : $(DYN1PATH)$(LIBPATH)file_io.c
	cd dyn1 && cd out && $(CC) $(CFLAGS) -D IO_EXPORTS $(INC) -c ../$(LIBPATH)file_io.c
#компиляция основных модулей
$(DYN1PATH)$(OUTPATH)app.o : $(DYN1PATH)$(SRCPATH)app.c
	cd dyn1 && cd out && $(CC) $(CFLAGS) $(INC) -c ../$(SRCPATH)app.c
$(DYN1PATH)$(OUTPATH)int_cmp.o : $(DYN1PATH)$(SRCPATH)int_cmp.c
	cd dyn1 && cd out && $(CC) $(CFLAGS) $(INC) -c ../$(SRCPATH)int_cmp.c
#компоновка библиотеки
$(DYN1PATH)$(OUTPATH)libdyn1.dll : $(DYN1PATH)$(OUTPATH)processing.o $(DYN1PATH)$(OUTPATH)file_io.o
	$(CC) -shared $(DYN1PATH)$(OUTPATH)processing.o $(DYN1PATH)$(OUTPATH)file_io.o -Wl,--subsystem,windows -o libdyn1.dll
# сборка приложения
app_dyn1.exe : $(DYN1PATH)$(OUTPATH)app.o $(DYN1PATH)$(OUTPATH)int_cmp.o $(DYN1PATH)$(OUTPATH)libdyn1.dll
	$(CC) $(DYN1PATH)$(OUTPATH)app.o $(DYN1PATH)$(OUTPATH)int_cmp.o -o app_dyn1.exe -L$(DYN1PATH)$(OUTPATH) -ldyn1
	
#динамическая библиотека 2 - динамическая загрузка

#компиляция модулей для библитоеки	
$(DYN2PATH)$(OUTPATH)processing.o : $(DYN2PATH)$(LIBPATH)processing.c
	cd dyn2 && cd out && $(CC) $(CFLAGS) -D PR_EXPORTS $(INC) -c ../$(LIBPATH)processing.c
$(DYN2PATH)$(OUTPATH)file_io.o : $(DYN2PATH)$(LIBPATH)file_io.c
	cd dyn2 && cd out && $(CC) $(CFLAGS) -D IO_EXPORTS $(INC) -c ../$(LIBPATH)file_io.c
#компиляция основных модулей
$(DYN2PATH)$(OUTPATH)app.o : $(DYN2PATH)$(SRCPATH)app.c
	cd dyn2 && cd out && $(CC) $(CFLAGS) $(INC) -c ../$(SRCPATH)app.c
$(DYN2PATH)$(OUTPATH)int_cmp.o : $(DYN2PATH)$(SRCPATH)int_cmp.c
	cd dyn2 && cd out && $(CC) $(CFLAGS) $(INC) -c ../$(SRCPATH)int_cmp.c
#компоновка библиотеки
$(DYN2PATH)$(OUTPATH)libdyn2.dll : $(DYN2PATH)$(OUTPATH)processing.o $(DYN2PATH)$(OUTPATH)file_io.o
	$(CC) -shared $(DYN2PATH)$(OUTPATH)processing.o $(DYN2PATH)$(OUTPATH)file_io.o -Wl,--subsystem,windows -o libdyn2.dll
# сборка приложения
app_dyn2.exe : $(DYN2PATH)$(OUTPATH)app.o $(DYN2PATH)$(OUTPATH)int_cmp.o $(DYN2PATH)$(OUTPATH)libdyn2.dll
	$(CC) $(DYN2PATH)$(OUTPATH)app.o $(DYN2PATH)$(OUTPATH)int_cmp.o -o app_dyn2.exe
	
	

	
#ТЕСТИРОВАНИЕ
#для модульного тестирования
OBJSUNIT := $(STATICPATH)$(OUTPATH)check_count_amount.o $(STATICPATH)$(OUTPATH)check_int_cmp.o $(STATICPATH)$(OUTPATH)check_key.o $(STATICPATH)$(OUTPATH)check_mysort.o $(STATICPATH)$(OUTPATH)check_swap.o $(STATICPATH)$(OUTPATH)check_main.o
# (функции одинаковые для всех вариантов использования библиотек, поэтому здесь
#используются файлы из статического варианта)
# Объектные файлы, нужные только в модульном тестировании
#компиляция тестирующих модулей
$(STATICPATH)$(OUTPATH)check_count_amount.o : $(STATICPATH)$(UNIPATH)check_count_amount.c
	cd static && cd out && $(CC) $(CFLAGS) $(INC) -c ../$(UNIPATH)check_count_amount.c
$(STATICPATH)$(OUTPATH)check_int_cmp.o : $(STATICPATH)$(UNIPATH)check_int_cmp.c
	cd static && cd out && $(CC) $(CFLAGS) $(INC) -c ../$(UNIPATH)check_int_cmp.c
$(STATICPATH)$(OUTPATH)check_key.o : $(STATICPATH)$(UNIPATH)check_key.c
	cd static && cd out && $(CC) $(CFLAGS) $(INC) -c ../$(UNIPATH)check_key.c
$(STATICPATH)$(OUTPATH)check_mysort.o : $(STATICPATH)$(UNIPATH)check_mysort.c
	cd static && cd out && $(CC) $(CFLAGS) $(INC) -c ../$(UNIPATH)check_mysort.c
$(STATICPATH)$(OUTPATH)check_swap.o : $(STATICPATH)$(UNIPATH)check_swap.c
	cd static && cd out && $(CC) $(CFLAGS) $(INC) -c ../$(UNIPATH)check_swap.c
$(STATICPATH)$(OUTPATH)check_main.o : $(STATICPATH)$(UNIPATH)check_main.c
	cd static && cd out && $(CC) $(CFLAGS) $(INC) -c ../$(UNIPATH)check_main.c
#сборка модульных тестов
unit_tests.exe : $(OBJSUNIT) $(STATICPATH)$(OUTPATH)processing.o $(STATICPATH)$(OUTPATH)file_io.o $(STATICPATH)$(OUTPATH)int_cmp.o
	$(CC) $^ -o $@ -lcheck
# сборка и прогон модульных тестов	
.PHONY : unit 	
unit : unit_tests.exe
	./unit_tests.exe
# сборка и прогон модульных тестов с проверкой drmemory
.PHONY : check_mem_unit 
check_mem_unit : unit_tests.exe
	drmemory -lib_blacklist "*" -batch -- ./unit_tests.exe

#для функционального тестирования

# cтатическая библиотека
# прогон функциональных тестов
.PHONY : func_static 	
func_static : app_static.exe
	cd func_tests && ./run_tests_static.bat	
# прогон функциональных тестов с проверкой drmemory	
.PHONY : func_static_mem
func_static_mem : app_static.exe
	echo "negatives"
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\file_in.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\file_in.txt func_tests\\file_out.txt f toomuch; true
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\file_in.txt func_tests\\file_out.txt F; true
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\does_not_exist.txt func_tests\\file_out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\neg_06_in.txt func_tests\\neg_06_out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\neg_07_in.txt func_tests\\neg_07_out.txt f; true
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\neg_08_in.txt func_tests\\neg_08_out.txt f; true

	echo "positives"
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\pos_01_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\pos_02_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\pos_03_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\pos_04_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\pos_05_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\pos_06_in.txt func_tests\\out.txt f
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\pos_07_in.txt func_tests\\out.txt f
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\pos_08_in.txt func_tests\\out.txt f
	drmemory -lib_blacklist "*" -batch -- ./app_static.exe func_tests\\pos_09_in.txt func_tests\\out.txt f
	
	
#динамическая библиотека 1 - динамическая компоновка
# прогон функциональных тестов
.PHONY : func_dyn1 	
func_dyn1 : app_dyn1.exe
	cd func_tests && ./run_tests_dyn1.bat	
# прогон функциональных тестов с проверкой drmemory	
.PHONY : func_dyn1_mem
func_dyn1_mem : app_dyn1.exe
	echo "negatives"
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\file_in.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\file_in.txt func_tests\\file_out.txt f toomuch; true
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\file_in.txt func_tests\\file_out.txt F; true
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\does_not_exist.txt func_tests\\file_out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\neg_06_in.txt func_tests\\neg_06_out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\neg_07_in.txt func_tests\\neg_07_out.txt f; true
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\neg_08_in.txt func_tests\\neg_08_out.txt f; true

	echo "positives"
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\pos_01_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\pos_02_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\pos_03_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\pos_04_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\pos_05_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\pos_06_in.txt func_tests\\out.txt f
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\pos_07_in.txt func_tests\\out.txt f
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\pos_08_in.txt func_tests\\out.txt f
	drmemory -lib_blacklist "*" -batch -- ./app_dyn1.exe func_tests\\pos_09_in.txt func_tests\\out.txt f
	
#динамическая библиотека 2 - динамическая загрузка
# прогон функциональных тестов
.PHONY : func_dyn2	
func_dyn2 : app_dyn2.exe
	cd func_tests && ./run_tests_dyn2.bat	
# прогон функциональных тестов с проверкой drmemory	
.PHONY : func_dyn2_mem
func_dyn2_mem : app_dyn2.exe
	echo "negatives"
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\file_in.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\file_in.txt func_tests\\file_out.txt f toomuch; true
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\file_in.txt func_tests\\file_out.txt F; true
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\does_not_exist.txt func_tests\\file_out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\neg_06_in.txt func_tests\\neg_06_out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\neg_07_in.txt func_tests\\neg_07_out.txt f; true
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\neg_08_in.txt func_tests\\neg_08_out.txt f; true

	echo "positives"
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\pos_01_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\pos_02_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\pos_03_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\pos_04_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\pos_05_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\pos_06_in.txt func_tests\\out.txt f
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\pos_07_in.txt func_tests\\out.txt f
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\pos_08_in.txt func_tests\\out.txt f
	drmemory -lib_blacklist "*" -batch -- ./app_dyn2.exe func_tests\\pos_09_in.txt func_tests\\out.txt f
	
	
#зависимости
%.d : %.c
	$(CC) -M $< > $@

include $(SRCS:.c=.d)

.PHONY : clean 
clean :
	$(RM) $(STATICPATH)$(OUTPATH)*.o $(STATICPATH)$(OUTPATH)*.a $(DYN1PATH)$(OUTPATH)*.o $(DYN1PATH)$(OUTPATH)*.dll $(DYN2PATH)$(OUTPATH)*.o  $(DYN2PATH)$(OUTPATH)*.dll *.exe *.d *.dll

	
	

	
