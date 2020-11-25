CC := gcc
INCPATH := ../inc/
OUTPATH := ./out/
SRCPATH := ./src/
UNIPATH := ./unit_tests/
SRCS := $(wildcard *.c)
INC := -I $(INCPATH)
CFLAGS := -std=c99 -Wno-format -Werror -Wall -Wextra -pedantic -Wvla

#-Wno-format for ignoring 
#null byte formating string
#extra args
#not enough args
#wrong type of args

# Объектные файлы, нужные в модульном тестировании
OBJSUNIT := $(OUTPATH)my_snprintf.o $(OUTPATH)check_my_snprintf.o $(OUTPATH)check_main.o 
#$(OUTPATH)check_film_array.o
	
#сборка модульных тестов
unit_tests.exe : $(OBJSUNIT)
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
	
# сборка и прогон модульных тестов с проверкой drmemory
.PHONY : check_mem_unit 
check_mem_unit : unit_tests.exe
	drmemory -lib_blacklist "*" -batch -- ./unit_tests.exe
 
#зависиммости
%.d : %.c
	$(CC) -M $< > $@

include $(SRCS:.c=.d)

#очистка
.PHONY : clean 
clean :
	$(RM) $(OUTPATH)*.o *.exe *.d


	
