# Arduino IoT Cloud ESP32 Alexa Control Smart Home
IoT-based Home Automation with Arduino IoT Cloud &amp; Alexa using ESP32 to control 4 home appliances with voice commands and monitor room temperature. (Circuit + Source Code)

In this IoT project, I have shown how to make an IoT-based Home Automation with Arduino IoT Cloud & Alexa using ESP32 to control 4 home appliances with voice commands.

If the internet is not available, then you can control the home appliances manually with switches and IR remote. During the article, I have shown all the steps to make this smart home system.


This IoT-based Home Automation system has the following features:

1. Control appliances with Alexa and Arduino IoT Cloud Dashboard.
2. Control the relays with the IR remote.
3. Control appliances manually with switches.
4. Control home appliances manually without internet.
5. Monitor real-time feedbacks and room temperature in the Amazon Alexa app.
6. All resources used for this project are FREE.

So, you can easily make this home automation project at home just by using an ESP32 and relay module. Or you can also use a custom-designed PCB for this project.

# Required Components:
1. ESP32 DEVKIT V1
2. 4-channel SPDT 5V Relay Module
3. Push Buttons
4. DHT11 sensor
5. 1838 IR Receiver
6. Alexa Echo Dot (Optional)

If you use the custom-designed PCB for this project, then please refer to the following required components list.

# Required Components for the PCB
1. Relays 5v (SPDT) (4 no)
2. BC547 Transistors (4 no)
3. PC817 Optocuplors (4 no)
4. 510-ohm 0.25-watt Resistor (4 no) (R1 - R4)
5. 1k 0.25-watt Resistors (6 no) (R5 - R10)
6. 10k 0.25-watt Resistor (1 no) (R11)
7. LED 5-mm (6 no)
8. 1N4007 Diodes (4 no) (D1 - D4)
9. Push Buttons (4 no)
10. Terminal Connectors
11. 5V DC supply

# Required Software:
1. Arduino IoT cloud
2. Arduino IDE
3. Amazon Alexa App.

# Circuit Diagram of the ESP32 Home Automation Project 
The circuit is very simple, I have used the GPIO pins D23, D22, D21 & D19 to control the 4 relays.

And the GPIO pins D13, D12, D14 & D27 are connected with switches to control the 4 relays manually.

I have used the INPUT_PULLUP function in Arduino IDE instead of using the pull-up resistors.

IR remote receiver (TSOP1838) connected with D35. And the DHT11 sensor connected with RX2.

I have used a 5V mobile charger to supply the smart relay module.

Please take proper safety precautions while working with high voltage.

# Alexa Control Relay Using ESP32
You can control the home appliances from Amazon Alexa App and also monitor the room temperature if the ESP32 is connected with Wi-Fi.

You can also ask Alexa to turn on and off the appliances from anywhere in the world.

You don't need any Echo DOT or other Alexa devices for this home automation project.

# ESP32 Control Relays With Arduino IoT Cloud Dashboard
You can also monitor the room temperature and control the home appliances from the Arduino IoT Cloud web dashboard and Arduino IoT Cloud Remote mobile app if the ESP32 is connected with WiFi.

In this project, I have used the FREE plan of Arduino IoT Cloud. In the FREE plan, you can control maximum of 5 relays or sensors.

When you control the relays from the Arduino IoT Cloud Remote mobile app the current state of the relay is also updated in the Amazon Alexa App.

# IR Remote Control Relays Using ESP32
You can always control the relays from any IR remote.

I will explain how to get the IR codes (HEX codes) from any remote in the following steps.

And if the ESP32 is connected with Wi-Fi, then you can also monitor the real-time feedback in the Amazon Alexa App & Arduino cloud dashboard.

# Control Relays Manually From Push Buttons
If the WiFi is not available, you can control the relays from the pushbuttons.

When the WiFi is available, the ESP32 will automatically reconnect with the WiFi.

Please refer to the circuit diagram to connect the pushbuttons.

Design the PCB for This Smart Home System
To make the circuit compact and give a professional look, I have designed the PCB after testing all the features of the smart relay module.

You can download the PCB Gerber file of this home automation project from the following link:

# Download the PCB Gerber File
https://github.com/techstudycell/arduino-iot-cloud-esp32-alexa-control-relays/tree/main/PCB%20Gerber

# Order the PCB from JLCPCB
After downloading the Garber file you can easily order the PCB

1. Visit https://jlcpcb.com/RAB and Sign in / Sign up
2. Click on the QUOTE NOW button.
3. Click on the "Add gerber file" button. Then browse and select the Gerber file you have downloaded.
4. Set the required parameter like Quantity, PCB masking color, etc.
5. After selecting all the Parameters for PCB click on SAVE TO CART button.
6. Type the Shipping Address.
7. Select the Shipping Method suitable for you.
8. Submit the order and proceed with the payment.

You can also track your order from the JLCPCB.com

My PCBs took 2 days to get manufactured and arrived within a week using the DHL delivery option.
PCBs were well packed and the quality was really good at this affordable price.

# Solder All the Components on PCB
After that, I have soldered all the components as per the circuit diagram.

Then connect the ESP32, DHT11, 1838 IR receiver with the PCB.

# Create Arduino IoT Cloud FREE Account
For this smart house project, I have used the Arduino Cloud Free plan.

Click on the following link to create an Arduino IoT Cloud account.

https://store.arduino.cc/digital/create

1. Click on "Create one".
2. Enter your birthday, then click on "Next".
3. Enter the email ID, user name, set password. Then click on "Sign Up".
4. Now click on "IoT Cloud".
5. Add ESP32 Device in the Arduino IoT Cloud
6. Click on the Select Device on the right.
7. Select "Set up a third Party device", then select device type as ESP32 and device model as DOIT ESP32 DEVKIT V1.
8. You will get a Device ID and Secret Key which will be required in the code.
9. Click on "Continue", You will find the device added.
10. Add Variable in Arduino IoT Cloud
11. Now to control 4 relays, and get reading from the DHT11 sensor, you have to add 5 variables.
12. Click on the "ADD VARIABLE" button.
13. Enter name, then select Alexa compatible switch type. Variable Permission will be "Read & Write" and Variable Update Policy will be "On Change". In a similar way, you have to add the next 3 variables.
14. For the room temperature, reading select Alexa compatible Temperature Sensor. Variable Update Policy will be "Periodically", and mention the interval time.

# Set Up Arduino IoT Cloud Dashboard
1. Now click on Dashboard on the top to set up the Arduino cloud dashboard.
2. Then click on Build Dashboard. After that click on the EDIT icon.
3. Then click on ADD and select Switch.
4. Give a name to this Switch, then link a variable with this switch widget.
5. Then click on Done.

In a similar way, you have to add total 4 Switch widgets to control 4 relays.

For the temperature, select Gauge widgets and link the Temperature variable. You can also set the MIN and MAX limits.

# Get the IR Codes (HEX Code) From Remote
Now, to get the HEX codes from the remote, first, we have to connect the IR receiver output pin with GPIO D35.

And give the 5V across the VCC and GND. The IR receiver must have a metallic casing, otherwise, you may face issues. Then follow the following steps to get the HEX codes.

Download the Sketch to get HEX code from any IR remote

1. Install the IRremote library in Arduino IDE.
2. Download the attached code, and upload it to ESP32.
3. Open Serial Monitor with Baud rate 9600.
4. Now, press the IR remote button.
5. The respective HEX code will populate in the serial monitor.
6. Save all the HEX codes in a text file.

# Program the ESP32 With Arduino IDE
To program the ESP32, I have used Arduino IDE.

1. Download the code for this project.
2. Then you have to install the ArduinoIoTCloud library https://github.com/arduino-libraries/ArduinoIoTCloud. During installation, it may ask to install other dependencies. Then click on Install All.

3. In the code, enter the following details.

const char THING_ID[] = ""; //Enter THING ID

const char DEVICE_LOGIN_NAME[] = ""; //Enter DEVICE ID

const char SSID[] = ""; //Enter WiFi SSID (name)

const char PASS[] = ""; //Enter WiFi password

const char DEVICE_KEY[] = ""; //Enter Secret device password (Secret Key)

You will get the THING_ID[] from Arduino IoT cloud Things. And copy-paste the DEVICE_LOGIN_NAME[] and DEVICE_KEY[] from the PDF which you have downloaded during adding the device to the Arduino IoT cloud.

4. Then update the HEX codes to control the relays from IR remote.

case 0x80BF49B6: relayOnOff(1); switch1 = toggleState_1; break; //update the HEX-code

case 0x80BFC936: relayOnOff(2); switch2 = toggleState_2; break; //update the HEX-code

case 0x80BF33CC: relayOnOff(3); switch3 = toggleState_3; break; //update the HEX-code

case 0x80BF718E: relayOnOff(4); switch4 = toggleState_4; break; //update the HEX-code

I have shown all the steps in the tutorial video. After doing all these changes, you can upload the code to ESP32.

# Configure the Alexa App for Arduino IoT Cloud

Download and install the Amazon Alexa App from the Google play store or App Store.

1. Tap on "More".
2. Then select "Skills & Games".
3. Search for Arduino and tap on "Arduino".
4. Tap on "ENABLE TO USE".
5. Connecting Arduino Cloud Devices With Alexa
6. Log in with the Arduino Cloud credentials.
7. Tap on CLOSE.
8. Tap on "DISCOVER DEVICES". It will take a minute to add devices. During this time the NodeMCU should be connected with the WiFi.
9. Tap on "Devices", and tap on "Switches" to see all the devices.

Thus, all the devices from Arduino IoT Cloud will be added to Amazon Alexa App.

# Arduino IoT Cloud Remote App Set-Up
You can also control the appliances from the Arduino IoT Cloud Remote App.

1. Download and install the Arduino IoT Cloud Remote App from the Google play store or App Store.
2. Tap on SIGN IN
3. Then log in to the Arduino IoT Cloud account
4. Tap on the THING you have created to open the dashboard.
5. Now, you can also control the relays from this Arduino IoT Cloud Remote App.

# Connect the Home Appliances
Connect the 4 home appliances with the relay module as per the circuit diagram.

Please take proper safety precautions while working with high voltage.

Connect 5-volt DC supply with the PCB. (I have used my old mobile charger 5V 2Amp) Turn on the 110V/230V supply and 5V DC supply.

# Finally!! the Arduino Cloud Smart Home System Is Ready
Now you can control your home appliances in a smart way.

I hope you have liked this Arduino IoT and Alexa control home automation project. I have shared all the required information for this project.

I will really appreciate it if you share your valuable feedback. Also if you have any query please write in the comment section.

Thank you & Happy Learning.
