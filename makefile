CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c99
SRC = main.cpp square-mat.cpp
TARGET = a.out

all:$(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) *.o