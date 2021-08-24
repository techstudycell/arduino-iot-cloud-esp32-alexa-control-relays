/**********************************************************************************
 *  TITLE: Arduino IoT Cloud + Alexa + IR + Manual control 4 Relays with DHT11 & Real-Time feedback using ESP32
 *  Click on the following links to learn more. 
 *  YouTube Video: https://youtu.be/pfEGnnY66sw
 *  Related Blog : https://iotcircuithub.com/esp32-projects/
 *  by Tech StudyCell
 *  Preferences--> Aditional boards Manager URLs : 
 *  https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
 *  
 *  Download Board ESP32 : https://github.com/espressif/arduino-esp32
 *  Download the libraries
 *  ArduinoIoTCloud Library with all the dependencies: https://github.com/arduino-libraries/ArduinoIoTCloud
 *  IRremote Library: https://github.com/Arduino-IRremote/Arduino-IRremote
 **********************************************************************************/

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include <DHT.h>
#include <IRremote.h>

const char THING_ID[]           = ""; //Enter THING ID
const char DEVICE_LOGIN_NAME[]  = ""; //Enter DEVICE ID

const char SSID[]               = "";    //Enter WiFi SSID (name)
const char PASS[]               = "";    //Enter WiFi password
const char DEVICE_KEY[]         = "";    //Enter Secret device password (Secret Key)

#define DHTPIN              16 //RX2  pin connected with DHT
#define IR_RECV_PIN         35 //D35 pin connected with IR Receiver IC

// define the GPIO connected with Relays and switches
#define RelayPin1 23  //D23
#define RelayPin2 22  //D22
#define RelayPin3 21  //D21
#define RelayPin4 19  //D19

#define SwitchPin1 13  //D13
#define SwitchPin2 12  //D12
#define SwitchPin3 14  //D14
#define SwitchPin4 27  //D27

#define wifiLed    2   //D2

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301


DHT dht(DHTPIN, DHTTYPE);
IRrecv irrecv(IR_RECV_PIN);
decode_results results;

int toggleState_1 = 0; //Define integer to remember the toggle state for relay 1
int toggleState_2 = 0; //Define integer to remember the toggle state for relay 2
int toggleState_3 = 0; //Define integer to remember the toggle state for relay 3
int toggleState_4 = 0; //Define integer to remember the toggle state for relay 4

float temperature1 = 0;
float humidity1   = 0;
int   reconnectFlag = 0;

void onSwitch1Change();
void onSwitch2Change();
void onSwitch3Change();
void onSwitch4Change();

CloudSwitch switch1;
CloudSwitch switch2;
CloudSwitch switch3;
CloudSwitch switch4;
CloudTemperatureSensor temperature;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(switch1, READWRITE, ON_CHANGE, onSwitch1Change);
  ArduinoCloud.addProperty(switch2, READWRITE, ON_CHANGE, onSwitch2Change);
  ArduinoCloud.addProperty(switch3, READWRITE, ON_CHANGE, onSwitch3Change);
  ArduinoCloud.addProperty(switch4, READWRITE, ON_CHANGE, onSwitch4Change);
  ArduinoCloud.addProperty(temperature, READ, 8 * SECONDS, NULL); //Update temperature value after every 8 seconds
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

void readSensor(){
     
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  else {
    humidity1 = h;
    temperature = t;
   // Serial.println(tempareture);
  }  
}

void sendSensor()
{
  readSensor();
}

void ir_remote_control(){
  if (irrecv.decode(&results)) {
    
      switch(results.value){
          case 0x80BF49B6:  relayOnOff(1); switch1 = toggleState_1; break; //update the HEX-code
          case 0x80BFC936:  relayOnOff(2); switch2 = toggleState_2; break; //update the HEX-code
          case 0x80BF33CC:  relayOnOff(3); switch3 = toggleState_3; break; //update the HEX-code
          case 0x80BF718E:  relayOnOff(4); switch4 = toggleState_4; break; //update the HEX-code
          default : break;         
        }   
        //Serial.println(results.value, HEX);    
        irrecv.resume();   
  } 
}

void relayOnOff(int relay) {

  switch (relay) {
    case 1:
      if (toggleState_1 == 0) {
        digitalWrite(RelayPin1, LOW); // turn on relay 1
        toggleState_1 = 1;
        Serial.println("Device1 ON");
      }
      else {
        digitalWrite(RelayPin1, HIGH); // turn off relay 1
        toggleState_1 = 0;
        Serial.println("Device1 OFF");
      }
      delay(100);
      break;
    case 2:
      if (toggleState_2 == 0) {
        digitalWrite(RelayPin2, LOW); // turn on relay 2
        toggleState_2 = 1;
        Serial.println("Device2 ON");
      }
      else {
        digitalWrite(RelayPin2, HIGH); // turn off relay 2
        toggleState_2 = 0;
        Serial.println("Device2 OFF");
      }
      delay(100);
      break;
    case 3:
      if (toggleState_3 == 0) {
        digitalWrite(RelayPin3, LOW); // turn on relay 3
        toggleState_3 = 1;
        Serial.println("Device3 ON");
      } else {
        digitalWrite(RelayPin3, HIGH); // turn off relay 3
        toggleState_3 = 0;
        Serial.println("Device3 OFF");
      }
      delay(100);
      break;
    case 4:
      if (toggleState_4 == 0) {
        digitalWrite(RelayPin4, LOW); // turn on relay 4
        toggleState_4 = 1;
        Serial.println("Device4 ON");
      }
      else {
        digitalWrite(RelayPin4, HIGH); // turn off relay 4
        toggleState_4 = 0;
        Serial.println("Device4 OFF");
      }
      delay(100);
      break;
    default : break;
  }
}

void manual_control() {
  //Manual Switch Control
  if (digitalRead(SwitchPin1) == LOW) {
    delay(200);
    relayOnOff(1);
    switch1 = toggleState_1;
  }
  else if (digitalRead(SwitchPin2) == LOW) {
    delay(200);
    relayOnOff(2);
    switch2 = toggleState_2;
  }
  else if (digitalRead(SwitchPin3) == LOW) {
    delay(200);
    relayOnOff(3);
    switch3 = toggleState_3;
  }
  else if (digitalRead(SwitchPin4) == LOW) {
    delay(200);
    relayOnOff(4);
    switch4 = toggleState_4;
  }
}

void doThisOnConnect(){
  /* add your custom code here */
  Serial.println("Board successfully connected to Arduino IoT Cloud");
  digitalWrite(wifiLed, HIGH); //Turn off WiFi LED
}
void doThisOnSync(){
  /* add your custom code here */
  Serial.println("Thing Properties synchronised");
}

void doThisOnDisconnect(){
  /* add your custom code here */
  Serial.println("Board disconnected from Arduino IoT Cloud");
  digitalWrite(wifiLed, LOW); //Turn off WiFi LED
}

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();
  dht.begin();
  irrecv.enableIRIn(); // Start the receiver
  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  ArduinoCloud.addCallback(ArduinoIoTCloudEvent::CONNECT, doThisOnConnect);
  ArduinoCloud.addCallback(ArduinoIoTCloudEvent::SYNC, doThisOnSync);
  ArduinoCloud.addCallback(ArduinoIoTCloudEvent::DISCONNECT, doThisOnDisconnect);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);

  pinMode(wifiLed, OUTPUT);

  pinMode(SwitchPin1, INPUT_PULLUP);
  pinMode(SwitchPin2, INPUT_PULLUP);
  pinMode(SwitchPin3, INPUT_PULLUP);
  pinMode(SwitchPin4, INPUT_PULLUP);

  //During Starting all Relays should TURN OFF
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
  digitalWrite(RelayPin3, HIGH);
  digitalWrite(RelayPin4, HIGH);
}

void loop() {

  ArduinoCloud.update();
  
  manual_control();     //Manual Control
  ir_remote_control();  //IR Remote Control
  sendSensor();         //Get Sensor Data
}

void onSwitch1Change() {
  //Control the device
  if (switch1 == 1)
  {
    digitalWrite(RelayPin1, LOW);
    Serial.println("Device1 ON");
    toggleState_1 = 1;
  }
  else
  {
    digitalWrite(RelayPin1, HIGH);
    Serial.println("Device1 OFF");
    toggleState_1 = 0;
  }
}

void onSwitch2Change() {
  if (switch2 == 1)
  {
    digitalWrite(RelayPin2, LOW);
    Serial.println("Device2 ON");
    toggleState_2 = 1;
  }
  else
  {
    digitalWrite(RelayPin2, HIGH);
    Serial.println("Device2 OFF");
    toggleState_2 = 0;
  }
}

void onSwitch3Change() {
  if (switch3 == 1)
  {
    digitalWrite(RelayPin3, LOW);
    Serial.println("Device3 ON");
    toggleState_3 = 1;
  }
  else
  {
    digitalWrite(RelayPin3, HIGH);
    Serial.println("Device3 OFF");
    toggleState_3 = 0;
  }
}

void onSwitch4Change() {
  if (switch4 == 1)
  {
    digitalWrite(RelayPin4, LOW);
    Serial.println("Device4 ON");
    toggleState_4 = 1;
  }
  else
  {
    digitalWrite(RelayPin4, HIGH);
    Serial.println("Device4 OFF");
    toggleState_4 = 0;
  }
}
