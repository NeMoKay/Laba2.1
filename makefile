CC = gcc-15
SOURCES = src/main.c src/input_data.c src/dinamic_massive.c tests/test.c
TARGET = main
all: $(TARGET)
$(TARGET): $(SOURCES)
	$(CC) $^ -o $@ -Iinclude
clean:
	rm -f $(TARGET)

.PHONY: all clean
