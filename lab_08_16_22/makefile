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
OBJS := $(OUTPATH)alloc_free.o $(OUTPATH)matrix_io.o $(OUTPATH)matrix_operations.o

# Объектные файлы, нужные только в модульном тестировании
OBJSUNIT := $(OUTPATH)check_alloc_free.o $(OUTPATH)check_matrix_io.o $(OUTPATH)check_matrix_operations.o

#сборка основной программы
app.exe : $(OBJS) $(OUTPATH)app.o
	$(CC) $^ -o $@
	
#сборка модульных тестов
unit_tests.exe : $(OBJS) $(OBJSUNIT) $(OUTPATH)check_main.o 
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
	cd func_tests && ./run_tests_08_16_22.bat
 
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
	drmemory -lib_blacklist "*" -batch -- ./app.exe 2; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe 2 3 4 5 6; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe r 3 4 5; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe a 3 4; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe m 3 4; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o 3 4 5; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\nonexisted.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_08_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_09_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_10_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_11_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_12_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_13_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_14_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_15_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_16_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_17_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_18_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_19_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_20_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_21_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_22_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_23_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_24_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_25_in.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests\\neg_26_in_1.txt tests\\neg_26_in_2.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests\\neg_27_in_1.txt tests\\neg_27_in_2.txt func_tests\\out.txt; true
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\neg_28_in.txt func_tests\\out.txt; true; true; true
	echo "positives"
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests\\pos_01_in_1.txt func_tests\\pos_01_in_2.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests\\pos_02_in_1.txt func_tests\\pos_02_in_2.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe a func_tests\\pos_03_in_1.txt func_tests\\pos_03_in_2.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests\\pos_04_in_1.txt func_tests\\pos_04_in_2.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests\\pos_05_in_1.txt func_tests\\pos_05_in_2.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe m func_tests\\pos_06_in_1.txt func_tests\\pos_06_in_2.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\pos_07_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\pos_08_in.txt func_tests\\out.txt
	drmemory -lib_blacklist "*" -batch -- ./app.exe o func_tests\\pos_09_in.txt func_tests\\out.txt
	
