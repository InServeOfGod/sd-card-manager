#include "input.h"

void delayUntilInput(void) {
  while (!Serial.available()) {
    delay(1);
  }
}

String getStrInput(void) {
  delayUntilInput();
  String buff = Serial.readString();
  buff.replace("\n", "");
  return buff;
}

long getNumberInput(void) {
  return getStrInput().toInt();
}

void getChoices(void) {
  Serial.println("1 = TÜM DOSYA VE KLASÖRLERİ LİSTELE");
  Serial.println("2 = KLASÖR İÇİNDEKİLERİ LİSTELE");
  Serial.println("3 = KLASÖR OLUŞTUR");
  Serial.println("4 = KLASÖR SİL");
  Serial.println("5 = DOSYA OLUŞTUR");
  Serial.println("6 = DOSYA OKU");
  Serial.println("7 = DOSYA YAZ");
  Serial.println("8 = DOSYA SİL");
}
