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
OBJS := $(OUTPATH)count_amount.o $(OUTPATH)int_cmp.o $(OUTPATH)key.o $(OUTPATH)mysort.o $(OUTPATH)swap.o

# Объектные файлы, нужные только в модульном тестировании
OBJSUNIT := $(OUTPATH)check_count_amount.o $(OUTPATH)check_int_cmp.o $(OUTPATH)check_key.o $(OUTPATH)check_mysort.o $(OUTPATH)check_swap.o 

#сборка основной программы
app.exe : $(OBJS) $(OUTPATH)file_io.o $(OUTPATH)app.o
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
	cd func_tests && ./run_tests_07_01_01.bat
 

%.d : %.c
	$(CC) -M $< > $@

include $(SRCS:.c=.d)

.PHONY : clean 
clean :
	$(RM) $(OUTPATH)*.o *.exe *.d

# сборка и прогон модульных тестов	с проверкой на память
.PHONY : check_mem_unit_tests 
check_mem_unit_tests : unit_tests.exe
	drmemory -lib_blacklist "*" -batch -- ./unit_tests.exe
	
