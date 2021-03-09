DIR_SRC = ./
DIR_INC = ../include
 
SRC = ./*.cpp
 
TARGET = server
LIB = -lpthread -L/usr/lib64/ 
 
CC = g++ 
CFLAGS = -g -Wall -I${DIR_INC}  -std=c++17 -lstdc++fs
 
${TARGET}:${DIR_SRC}/${SRC}
	$(CC) $^  ${CFLAGS} -o $@ ${LIB} 
    
.PHONY:clean
clean:
	rm  $(TARGET)
