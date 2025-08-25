TARGET = 11_JSON

CC = gcc
CFLAGS = -Iinclude -Wall

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(TARGET)

#Quy tắc để tọa ra tệp thực thi
$(TARGET) : $(OBJ)
	$(CC) -o $@ $^

#Quy tắc để biên dịch các tệp .c thành .o
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

#Quy tắc để làm sạch thư mục build
clean:
	rm -f *.o $(TARGET)

#Quy tắc giả (phony target)
.PHONY: all clean