CC = gcc-15
SOURCES = main_matrix/main.c main_matrix/io.c main_matrix/dinamic_massive.c main_matrix/Matrix.c
TARGET = main
all: $(TARGET)
$(TARGET): $(SOURCES)
	$(CC) $^ -o $@ -Iinclude
clean:
	rm -f $(TARGET)

.PHONY: all clean

