CC=arm-none-eabi-gcc
CFLAGS=	-c -mcpu=cortex-m4 -mthumb -Wall -std=gnu11
LDFLAGS = -nostdlib -T
LDFILE = STM32_linker.ld
LDCMDS= -Wl,-Map=final.map
# TARGET:main.o
OBJS=main.o led.o startupFile.o

all : main.o led.o startupFile.o final.elf

main.o:main.c
	${CC} ${CFLAGS} $^ -o $@

led.o:led.c
	${CC} ${CFLAGS} $^ -o $@

startupFile.o:startupFile.c
	${CC} ${CFLAGS} $^ -o $@

final.elf: ${OBJS}
	${CC} ${LDFLAGS} ${LDFILE} ${LDCMDS} $^ -o $@

clean:
	rm *.o *.elf *.log -o *.elf *.map

load:
	openocd -f board/stm32f4discovery.cfg