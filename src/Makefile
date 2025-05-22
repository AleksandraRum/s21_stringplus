CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g -I/opt/homebrew/opt/check/include
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = -L/opt/homebrew/opt/check/lib

# CHECKFLAGS = $(shell pkg-config --cflags --libs check)
OS = $(shell uname -s)

ifeq ($(OS),Linux)
	TEST_LIBS =-lcheck -lm -lsubunit
else
	TEST_LIBS =-lcheck
endif

all: clean s21_string.a

s21_string.a: s21_string.o
	ar rc s21_string.a obj/*.o
	ranlib s21_string.a

s21_string.o:
	$(CC) $(CFLAGS) -c $(wildcard s21_*.c)
	mkdir obj
	mv *.o obj

test:
	$(CC) $(CFLAGS) $(LDFLAGS) test_main.c tests/*.c s21_string.a $(TEST_LIBS) -o s21_string_test
	./s21_string_test

brew:
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

gcov_report:
	$(CC) $(CFLAGS) $(GCOVFLAGS) tests/*.c *.c -o s21_string_gcov $(TEST_LIBS)
	./s21_string_gcov
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report
	rm -rf *.gcda *.gcno
	open report/index.html

ubuntu:
	sudo apt-get install check
	sudo apt-get install lcov

format:
	clang-format -n *.h *.c *.h tests/*.c tests/*.h

fix:
	clang-format -i *.h *.c *.h tests/*.c tests/*.h

# leaks:
#	leaks -atExit -- ./s21_string_test

cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem ./*.c
	cppcheck --enable=all --suppress=missingIncludeSystem ./tests/*.c

clean:
	rm -rf report/ obj/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt s21_string_test s21_string_gcov

.PHONY: all clean

