#include <WiFi.h>
#include <MQTT.h>
const char ssid[] = "OKBABE";
const char password[] = "12345678A";
String myip;
WiFiClient net;
MQTTClient client(256);
String STT = "1";
String mqtt_topic = "ESP32_SWITCH_AUDIO";



unsigned long lastMillis = 0;

volatile int interruptCounter = 0;
//Biến dùng để lưu chuỗi
char buffer[64]={};
void setup()
{
  
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");

  myip = WiFi.localIP().toString();

  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported by Arduino.
  // You need to set the IP address directly.
  client.begin("118.27.192.219", net);
  client.onMessage(messageReceived);

  connect();
  Serial.println("ESP32_SWITCH_AUDIO_POWERON");
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(18, OUTPUT);

}

void loop()
{
     if (!client.connected()) {
  Serial.println("WIFI IN LOOP BI NGAT");
  connect();
  }
  client.loop();
  //Nếu có tín hiệu vào từ Serial
  if (Serial.available()>0){
    //Đọc tín hiệu đó vào buffer
    Serial.readBytes(buffer, Serial.available());
    //Xuất ngược ra Serial
    Serial.println(buffer);
   String stringOne = String(buffer);// converting a constant char into a String
     int chanel = stringOne.toInt();
    chuyenkenh(chanel);
    //Nghỉ mệt
    delay(500);
  }
  
  
}




void _trypushmqtt(String content) {

  if (!client.connected()) {
    Serial.println("_trypushmqtt => WIFI BI NGAT");
    _reconnect(content);
  } else {
    push_mqtt(content);
  }
}

void _reconnect(String content) {
  Serial.print("_reconnect checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("ESP32_SWITCH_AUDIO")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");
  push_mqtt(content);
  client.subscribe(mqtt_topic);
}

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("ESP32_SWITCH_AUDIO")) { //ESP32_SWITCH_AUDIO
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nconnected!");

  client.subscribe(mqtt_topic);
}
void messageReceived(String & topic, String & payload) {
  Serial.println("incoming: " + topic + " - " + payload);
   Serial.println(payload);
 int chanel = payload.toInt();
   // Serial.println(payload.length());
   if ((chanel>0) && (chanel<17)){
   
    chuyenkenh(chanel);
     }


     

}

void push_mqtt(String content) {
  client.publish("/ESP32_SWITCH_AUDIO_SEND", content);

}

void chuyenkenh(int chanel){
int pin[] = {23, 22, 32, 33,  25,  26, 21, 19, 18};
int cong1[]  = {0, 0, 0, 1,  1,  1, 0, 0, 0};
int cong2[]  = {0, 1, 0, 1,  1,  1, 0, 0, 0};
int cong3[]  = {1, 0, 0, 1,  1,  1, 0, 0, 0};
int cong4[]  = {1, 1, 0, 1,  1,  1, 0, 0, 0};
int cong5[]  = {0, 0, 1, 0,  1,  1, 0, 1, 0};
int cong6[]  = {0, 1, 1, 0,  1,  1, 0, 1, 0};
int cong7[]  = {1, 0, 1, 0,  1,  1, 0, 1, 0};
int cong8[]  = {1, 1, 1, 0,  1,  1, 0, 1, 0};
int cong9[]  = {0, 0, 1, 1,  0,  1, 1, 0, 0};
int cong10[] = {0, 1, 1, 1,  0,  1, 1, 0, 0};
int cong11[] = {1, 0, 1, 1,  0,  1, 1, 0, 0};
int cong12[] = {1, 1, 1, 1,  0,  1, 1, 0, 0};
int cong13[] = {0, 0, 1, 1,  1,  0, 1, 1, 0};
int cong14[] = {0, 1, 1, 1,  1,  0, 1, 1, 0};
int cong15[] = {1, 0, 1, 1,  1,  0, 1, 1, 0};
int cong16[] = {1, 1, 1, 1,  1,  0, 1, 1, 0};
int i;
switch (chanel) {
case 1:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong1[i]); // bật đèn led
  }
  break;
case 2:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong2[i]); // bật đèn led
  }
  break;
case 3:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong3[i]); // bật đèn led
  }
  break;
case 4:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong4[i]); // bật đèn led
  }
  break;
case 5:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong5[i]); // bật đèn led
  }
  break;
case 6:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong6[i]); // bật đèn led
  }
  break;
case 7:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong7[i]); // bật đèn led
  }
  break;
case 8:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong8[i]); // bật đèn led
  }
  break;
case 9:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong9[i]); // bật đèn led
  }
  break;
case 10:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong10[i]); // bật đèn led
  }
  break;
case 11:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong11[i]); // bật đèn led
  }
  break;
case 12:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong12[i]); // bật đèn led
  }
  break;
case 13:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong13[i]); // bật đèn led
  }
  break;
case 14:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong14[i]); // bật đèn led
  }
  break;
case 15:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong15[i]); // bật đèn led
  }
  break;
case 16:
  for (i = 0; i < 9; i++) {
    digitalWrite(pin[i], cong16[i]); // bật đèn led
  }
  break;
default:
  // if nothing else matches, do the default
  // default is optional
  break;
}
}
