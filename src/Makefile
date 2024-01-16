TESTFLAGS:=
ifeq ($(shell uname -s),Linux)
	TESTFLAGS += -lm -lrt -lsubunit
endif
TESTFLAGS += -lcheck -lpthread -pthread
GCCFLAGS = -Wall -Werror -Wextra
GCOVFLAGS = -fprofile-arcs -ftest-coverage

all: s21_matrix.a

s21_matrix.a: clean
	clang-format -style=Google -i *.c *.h
	gcc $(GCCFLAGS) -g -c s21_*.c 
	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a
	rm *.o

gcov_report: s21_matrix.a
	gcc $(GCCFLAGS) $(GCOVFLAGS) test.c $(TESTFLAGS) s21_*.c -o gcovreport
	./gcovreport
	lcov -t "gcovreport" -o gcovreport.info -c -d . 
	genhtml -o report gcovreport.info 
	open report/src/index.html
	
test: s21_matrix.a
	gcc $(GCCFLAGS) $(TESTFLAGS) test.c s21_matrix.a -o test
	./test

test_ubuntu: s21_matrix.a
	gcc -o test $(CFLAGS) --coverage test.c s21_matrix.a -lcheck -lm -lpthread -lsubunit
	./test

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info binary_files test report gcovreport
