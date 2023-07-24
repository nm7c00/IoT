# IoT 
Each directory is its own project with its
own readme, hardware requirements, build/, src/, etc...   
<br>
## building and flashing
To build a project just run `make <dirname> DEVICE=<device name>`;  
For example my project test/, uses an arduino uno r3 which is 
represented as ttyACM0 in my /dev/ directory  
```bash
make TEST DEVICE=/dev/ttyACM0
```
will compile test/src/ > test/build/test.hex and flash it 
to $(DEVICE).  
<br>
The make flag for each project is its dirname capitalized.
