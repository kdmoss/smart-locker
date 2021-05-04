# smart-door-lock

## Tutorial

**Download and Install XAMPP**
This software is _optional_ but allows us to run a PHP server locally.
If you use another software or pay for cloud hosting this does not refer to you.

1. Download and install ![XAMPP 8.0.5](https://www.apachefriends.org/index.html) for Windows from their website.
2. Run the powershell script inside the `/src` folder.
3. Launch the XAMPP Control Panel and start both the Apache and MySQL servers.

**Configuring the ESP8266**
Open the lock.ino source code in the Arduino IDE and perform the following:
1. Add the ![ESP8266 server](https://arduino.esp8266.com/stable/package_esp8266com_index.json) to the `Additional Boards Manager URLs` in `File > Preferences`.
2. Add the three libraries in the `/dependency` folder by going to `Sketch > Include Library > Add .ZIP Library...`. 
3. Alter the `domain` string in the source code to be the IPV4 of the device running the Apache server.
4. Alter the `ssid` string to be the SSID of the router you want the ESP8266 to connect to.
5. Alter the `password` string to be, you guessed it, the password to the router you want the ESP8266 to connect to.
6. Upload the code to the ESP8266 and voila.

## Progress This week

**SETUP ESP8266 AT SCHOOL:**

To setup ESP8266 at school need to follow some instructions:

1. On the Arduino IDE need to go to **File > Preferences**

2. Enter http://arduino.esp8266.com/stable/package_esp8266com_index.json into the “Additional Board Manager URLs” field as shown in the figure below. Then, click the “OK” button.

3. Go to **Tools > Board > Boards Manager….** And install esp8266 by **ESP8266 Community**

4. Then go to **Tools > Board…** and select Node MCU 1

Also install drivers using this website: https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers … **Make sure it is a CP210x Universal Windows Driver.** This will make sure arduino read ports for ESP8266

**Conclusion:**

Sadly I wasn't able to connect to the KSU Wireless using HTTP Authentication. Here is the result.

![HTTP](https://user-images.githubusercontent.com/80173030/110221670-3d612100-7e93-11eb-9f86-d111b6a979a4.PNG)


As for now I will try to finish the project at home so that later we can focus on setting it up at school.

**DATABASE SETUP:**

Pin connections for ESP8266 to BME280. Here below is the picture

![pins](https://user-images.githubusercontent.com/80173030/110221799-d132ed00-7e93-11eb-9d7d-8fa7f44277e9.PNG)

**Door Lock Circuit setup:**

I have successfully completed the code for the door luck to open and close by creating a web server that spits a URL with a IP-address.

Here below is how the circuit looks like.

![IMG_5815](https://user-images.githubusercontent.com/80173030/110705611-4700c680-81bc-11eb-9680-c4b955e040fd.jpg)


Later on I will create a KiCad design of the door lock to show the circuit


