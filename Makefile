ifndef DEVICE
$(error DEVICE has not been set, view the readme)
endif

EXAMPLE:
	avr-g++ -std=c++11 -O0 -DF_CPU=16000000UL -mmcu=atmega328p -c -o example/build/checkButton.o example/src/checkButton.cc 
	avr-g++ -std=c++11 -O0 -DF_CPU=16000000UL -mmcu=atmega328p -c -o example/build/example.o example/src/example.cc 
	avr-g++ -std=c++11 -O0 -o example/build/example.bin example/build/example.o example/build/checkButton.o
	avr-objcopy -O ihex -R .eeprom example/build/example.bin example/build/example.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P $(DEVICE) -b 115200 -U flash:w:example/build/example.hex
