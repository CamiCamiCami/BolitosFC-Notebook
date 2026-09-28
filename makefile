SHELL := /bin/bash
FILE_NAME := $(basename $(notdir $(FILE)))
DIR_NAME := $(dir $(FILE))
OUT_NAME := $(DIR_NAME)$(FILE_NAME).out
IN_NAME := $(DIR_NAME)$(FILE_NAME).in
clear: run
	rm $(OUT_NAME)

run: compile
	./$(OUT_NAME)

debug: compile
	gdb -x ./comandosGDB ./$(OUT_NAME)

compile: $(FILE)
	g++ $(FILE) -DLOCAL -DFILE_DIR='"./$(IN_NAME)"' -g -fsanitize=address,undefined -o $(OUT_NAME)

fill:
	mkdir $(DIR)
	cat template.cpp | tee $(DIR)/{a..n}.cpp > /dev/null
	touch $(DIR)/{a..n}.in

traer:
	cp $(DIR)/.clang-format .clang-format
	cp $(DIR)/makefile makefile
	cp $(DIR)/comandosGDB comandosGDB
	cp $(DIR)/template.cpp template.cpp

llevar:
	cp .clang-format $(DIR)/.clang-format 
	cp makefile $(DIR)/makefile 
	cp comandosGDB $(DIR)/comandosGDB 
	cp template.cpp $(DIR)/template.cpp 