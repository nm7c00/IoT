ifndef DEVICE
$(error DEVICE has not been set, view the readme)
endif

TEST:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o test/build/test.o test/src/test.c
	avr-gcc -o test/build/test.bin test/build/test.o
	avr-objcopy -O ihex -R .eeprom test/build/test.bin test/build/test.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P $(DEVICE) -b 115200 -U flash:w:test/build/test.hex
