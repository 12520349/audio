//Biến dùng để lưu chuỗi
char buffer[64]={};
void setup()
{
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(18, OUTPUT);

  //Mở cổng serial
  Serial.begin(115200);
}

void loop()
{
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
    digitalWrite(pin[i], cong4[i]); // bật đèn led
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
