CC = gcc-15
SOURCES = src/main.c src/io.c src/dinamic_massive.c src/Matrix.c
TARGET = main
all: $(TARGET)
$(TARGET): $(SOURCES)
	$(CC) $^ -o $@ -Iinclude
clean:
	rm -f $(TARGET)

.PHONY: all clean

