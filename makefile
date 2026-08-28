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
	gdb -x ./comandosDebug ./$(OUT_NAME)

compile: $(FILE)
	g++ $(FILE) -DLOCAL -DFILE_DIR='"./$(IN_NAME)"' -g -fsanitize=address,undefined -o $(OUT_NAME)


FILES := a b c d e f g h i j k l m n
fill:
	mkdir $(DIR)
	cat template.cpp | tee $(DIR)/{a..n}.cpp > /dev/null
	touch $(DIR)/{a..n}.in