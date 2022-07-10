CC=gcc
CFLAGS=-c -Wall -Werror -Wextra -std=c11
OS := $(shell uname -s)
ifeq ($(OS), Darwin)
  LDFLAGS= -lcheck
else
  LDFLAGS=-lcheck -lsubunit -lrt -lpthread -lm
endif
LIBSRC=$(filter-out test.c, $(wildcard *.c))
LIBOBJ=$(LIBSRC:.c=.o)
EXECUTABLE=result_file
LCOVEXEC=$(EXECUTABLE).info
REPORTDIR=report
STATICLIB=afini.a parce.a
APP = ./qt/3DViewer.app

.PHONY: all build test gcov_report clean rebuild

all: build

build: clean test.o $(STATICLIB)
	$(CC) test.o $(STATICLIB) -o $(EXECUTABLE) $(LDFLAGS)

install:
	cd ./qt; qmake
	cd ./qt; make
	@mkdir $(HOME)/Desktop/C8_3DViewer_v1.0/
	@cp -rf $(APP) $(HOME)/Desktop/C8_3DViewer_v1.0/
	cd ../ make clean
	
uninstall:
	@rm -rf $(HOME)/Desktop/C8_3DViewer_v1.0/

test: build
	./$(EXECUTABLE) 

dist:
	tar -czf C8_3DViewer.tgz ./*

gcov_report: CFLAGS+=--coverage
gcov_report: LDFLAGS+=--coverage
gcov_report: test
	lcov -t $(EXECUTABLE) -o $(LCOVEXEC) -c -d .
	genhtml -o $(REPORTDIR) $(LCOVEXEC)
	open report/index.html

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

style:
	cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py afini.c afini.h test.c parse.c parse.h
	CK_FORK=no leaks --atExit -- ./result_file
	rm -f CPPLINT.cfg

clean:
	cd qt/; make clean || echo "Please, install application first!"; rm -rf Makefile 3DViewer.app
	rm -rf *.o $(EXECUTABLE) $(STATICLIB) *.gcno *.gcda *.gcov $(LCOVEXEC) $(REPORTDIR)
	rm -rf C8_3DViewer.tgz

dvi:
	open dvi.html

rebuild: clean all

$(STATICLIB): $(LIBOBJ)
	ar rcs $@ $^
	ranlib $@