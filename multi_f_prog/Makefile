
TARGET = main
CSRC = $(TARGET).c
CSRC += enc_dec_showfile.c

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

