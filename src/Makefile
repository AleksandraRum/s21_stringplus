FLAGS=-Werror -Wextra -Wall
SOURCE=$(wildcard *.c test/*.c)
GCOV=-fprofile-arcs -ftest-coverage
# Ниже настройки сборки файлов для разных систем
UNAME_S := $(shell uname -s)
OS := $(shell cat /etc/os-release)
ifeq ($(UNAME_S),Darwin)# Команды для MacOS
    LCHECK=-lcheck
else ifeq ($(findstring Ubuntu, $(OS)), Ubuntu)
    LCHECK=-lcheck -lsubunit -lm
else ifeq ($(findstring Manjaro, $(OS)), Manjaro)
	LCHECK=-lcheck -lm
else
	LCHECK=-lcheck -lm
endif

all: rm s21_string.a test clean

s21_string.a: rm
	gcc $(FLAGS) -c $(SOURCE)
	ar rc s21_string.a *.o 
	
test: s21_string.a
	gcc $(FLAGS) test_main.c tests/*.c s21_string.a -o test $(LCHECK)
	./test

gcov_report: rm clean
	gcc $(FLAGS) test.c $(SOURCE) -o test $(LCHECK) $(GCOV)
	./test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info -o coverage_html

rebuild: clean all

rm: clean
	rm -f test s21_string.a

clean:
	rm -rf *.o *.gcda *.gcno *.info coverage_html 