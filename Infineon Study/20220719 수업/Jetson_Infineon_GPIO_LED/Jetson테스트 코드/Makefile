CC = g++

CFLAGS = -w -Wall -O2
SRCS = signal_led_je.c Jeston_nano_GPIO.o

PROG = signal_led_je

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) 
	
Jeston_nano_GPIO.o:signal_led_je.c Jeston_nano_GPIO.h	
	$(CC) -c signal_led_je.c
	
	$(./PROG)
