CC=arm-none-eabi-gcc
CFLAGS=	-c -mcpu=cortex-m4 -mthumb -Wall -std=gnu11
# TARGET:main.o
OBJS=led.o

all : main.o led.o startupFile.o

main.o:main.c
	${CC} ${CFLAGS} $^ -o $@

led.o:led.c
	${CC} ${CFLAGS} $^ -o $@

startupFile.o:startupFile.c
	${CC} ${CFLAGS} $^ -o $@

clean:
	rm *.o 