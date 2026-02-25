CC = gcc-15
SOURCES = main.c input_data.c test.c
TARGET = main

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $^ -o $@

clean:
	rm -f $(TARGET)

.PHONY: all clean