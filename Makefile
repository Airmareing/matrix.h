CC:=gcc
CFLAGS := -Wall -Werror -Wextra

all : clean build

build :
	${CC} ${CFLAGS} s21_arithmetic.c s21_matrix.c -o s21_matrix
	./s21_matrix

clean :
	rm -f s21_matrix
