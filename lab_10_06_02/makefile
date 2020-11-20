CC := gcc
INCPATH := ../inc/
OUTPATH := ./out/
SRCPATH := ./src/
UNIPATH := ./unit_tests/
SRCS := $(wildcard *.c)
INC := -I $(INCPATH)
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wfloat-equal -pedantic -Wfloat-conversion -Wvla

#2 варианта сборки
.PHONY : debug 
debug : CFLAGS += -g3
debug : app.exe

.PHONY : release
release : CFLAGS += -DNDEBUG -g0
release : app.exe

# Общие объектные файлы
OBJS := $(OUTPATH)node.o $(OUTPATH)matrix.o 

# Объектные файлы, нужные только в модульном тестировании
OBJSUNIT := $(OUTPATH)check_node.o $(OUTPATH)check_matrix.o $(OUTPATH)check_main.o 

#сборка основной программы
app.exe : $(OBJS) $(OUTPATH)app.o
	$(CC) $^ -o $@
	
#сборка модульных тестов
unit_tests.exe : $(OBJS) $(OBJSUNIT)
	$(CC) $^ -o $@ -lcheck

#компоновка тестирующих модулей
$(OUTPATH)check_%.o : $(UNIPATH)check_%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<
	
#компоновка основных модулей
$(OUTPATH)%.o : $(SRCPATH)%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<
	
# сборка и прогон модульных тестов	
.PHONY : unit 	
unit : unit_tests.exe
	./unit_tests.exe

# прогон функциональных тестов
.PHONY : func  	
func : app.exe
	cd func_tests && ./run_tests_10_06_02.bat
    
#зависиммости
%.d : %.c
	$(CC) -M $< > $@

include $(SRCS:.c=.d)

#очистка
.PHONY : clean 
clean :
	$(RM) $(OUTPATH)*.o *.exe *.d

# сборка и прогон модульных тестов с проверкой drmemory
.PHONY : check_mem_unit 
check_mem_unit : unit_tests.exe
	drmemory -lib_blacklist "*" -batch -- ./unit_tests.exe
	
# прогон функциональных тестов с проверкой drmemory	
.PHONY : check_mem_func 
check_mem_func : app.exe
	echo "negatives"
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_01_in.txt > func_tests/out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_02_in.txt > func_tests/out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_03_in.txt > func_tests/out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_04_in.txt > func_tests/out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_05_in.txt > func_tests/out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_06_in.txt > func_tests/out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_07_in.txt > func_tests/out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_08_in.txt > func_tests/out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_09_in.txt > func_tests/out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_10_in.txt > func_tests/out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_11_in.txt > func_tests/out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_12_in.txt > func_tests/out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_13_in.txt > func_tests/out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_14_in.txt > func_tests/out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/neg_15_in.txt > func_tests/out.txt; true
	echo "positives"
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/pos_01_in.txt > func_tests/out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/pos_02_in.txt > func_tests/out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/pos_03_in.txt > func_tests/out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/pos_04_in.txt > func_tests/out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/pos_05_in.txt > func_tests/out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/pos_06_in.txt > func_tests/out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/pos_07_in.txt > func_tests/out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/pos_08_in.txt > func_tests/out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/pos_09_in.txt > func_tests/out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe < func_tests/pos_10_in.txt > func_tests/out.txt
	
	