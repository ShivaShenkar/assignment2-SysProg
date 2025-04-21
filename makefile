CC = clang++
CFLAGS = -Wall -Wextra -pedantic 
SRC = main.cpp square-mat.cpp
TARGET = a.out
TEST_TARGET = test.out
TEST_SRC = test.cpp square-mat.cpp

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_SRC)
	$(CC) $(CFLAGS) -o $@ $^

all:$(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(TEST_TARGET) *.o