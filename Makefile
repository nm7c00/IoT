ifndef DEVICE
$(error DEVICE has not been set, view the readme)
endif

# A high level step-by-step overview of EXAMPLE's build process.
# 	Compile the *.c/cc files into binaries 
# 	Link the binaries
# 	Remove the eeprom and convert into intel hex
# 	Flash the final binary onto the arduino

EXAMPLE:
	avr-g++ -std=c++11 -O0 -DF_CPU=16000000UL -mmcu=atmega328p -c -o example/build/checkButton.o example/src/checkButton.cc  
	avr-g++ -std=c++11 -O0 -DF_CPU=16000000UL -mmcu=atmega328p -c -o example/build/example.o example/src/example.cc 
	avr-g++ -std=c++11 -O0 -o example/build/example.bin example/build/example.o example/build/checkButton.o
	avr-objcopy -O ihex -R .eeprom example/build/example.bin example/build/example.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P $(DEVICE) -b 115200 -U flash:w:example/build/example.hex



UART_PROJ_1:
	avr-gcc -std=gnu99 -O0 -DF_CPU=16000000UL -mmcu=atmega328p -c -o uart_test/build/main.o uart_test/src/main.c
	avr-gcc -std=gnu99 -O0 -o uart_test/build/main.bin uart_test/build/main.o 
	avr-objcopy -O ihex -R .eeprom uart_test/build/main.bin uart_test/build/main.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P $(DEVICE) -b 115200 -U flash:w:uart_test/build/main.hex
