CC = gcc
CFLAGS = -g -Wall -I../include
LDLIBS = -lpthread
TARGET = make_test
SRCS = main.c make_test_debug.c make_test_log.c make_test_util.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)

