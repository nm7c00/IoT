# uart project one

This is a simple project where I have a circuit on an arduino with a [sensor name].  [sensor description].  The arduino receives the data from the [sensor name] on 
a serial rx port respectively.  The data is processed and sent to the raspberry pi 4 b from the arduino's tx to the pi's rx.  The sensor data is printed to stdout 
bc I'm ssh-ing into the pi and only have one good monitor.  

I know this is uart but because bits are being sent over a wire, I decided to use networking naming conventions.  It just felt right.  The arduino is referred to as 
the host.  It is where the data is coming from.  Rapsberry pi's job is to listen so I named it client.  I tried to give a graphical overview with KiCad though my 
education has come from google searches so it may look unclear to beginners and experts alike.
