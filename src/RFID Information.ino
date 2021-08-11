//RFID 정보 확인 및 표시
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin(); //SPI 시작
  mfrc522.PCD_Init(); //mfrc522 시작
}

void loop() {
  if( ! mfrc522.PICC_IsNewCardPresent())

    return;

  if( ! mfrc522.PICC_ReadCardSerial())

    return;

  mfrc522.PCD_DumpVersionToSerial();  //MFRC522 정보 표시
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid)); //카드의 정보를 시리얼로 전송
}
