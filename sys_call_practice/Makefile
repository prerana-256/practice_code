
TARGET = decrypt
CSRC = $(TARGET).c
CSRC +=

COBJ = $(CSRC:.c=.o)

CC=gcc
CFLAGS=-ggdb3 -m64
LDFLAGS=

all: $(TARGET).out

$(TARGET).out: $(COBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(COBJ:%.o): %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET).out $(COBJ)

.PHONY: clean all

