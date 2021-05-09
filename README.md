# smart-locker

## Tutorial

### Download and Install XAMPP:

This software is _optional_ but allows us to run a PHP server locally.
If you use another software or pay for cloud hosting this does not pertain to you.

1. Download and install [XAMPP 8.0.5](https://www.apachefriends.org/index.html) for Windows from their website.
2. Run the setup script inside the `/src` folder using Powershell.
3. Launch the XAMPP Control Panel and start both the Apache and MySQL servers.

### Configuring the ESP8266:

Open the `lock.ino` source code in the Arduino IDE and perform the following:
1. Add the [ESP8266 server](https://arduino.esp8266.com/stable/package_esp8266com_index.json) to the `Additional Boards Manager URLs` in `File > Preferences`.
2. Add the three libraries in the `/dependencies` folder by going to `Sketch > Include Library > Add .ZIP Library...` 
3. Alter the `domain` string in the source code to be the IPV4 of the device running the Apache server.
4. Alter the `ssid` string to be the SSID of the router you want the ESP8266 to connect to.
5. Alter the `password` string to be, you guessed it, the password to the router you want the ESP8266 to connect to.
6. Upload the code to the ESP8266 and voila.
