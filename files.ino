#include "files.h"

void checkSD(void) {
  while (!SD.begin()) {
    digitalWrite(GREEN_PIN, LOW);

    digitalWrite(RED_PIN, HIGH);
    delay(500);
    digitalWrite(RED_PIN, LOW);
    delay(500);

    Serial.println("SD başlatılamadı!");
  }

  Serial.println("SD başlatıldı.");
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
}

void listDir(String path) {
  File f = SD.open(path, FILE_READ);

  while (f) {
    File entity = f.openNextFile();

    if (entity) {
      if (entity.isDirectory()) {
        Serial.print("/");
      }

      Serial.println(entity.name());
    }

    else {
      f.rewindDirectory();
      f.close();
      break;
    }
  }
}

String requirePath(void) {
  Serial.println("Dosya yolu girin : ");
  return getStrInput();
}

File makeFile(void) {
  File f = SD.open(requirePath(), FILE_WRITE);

  if (f) {
    Serial.println("Dosya oluşturuldu");
  } else {
    Serial.println("Dosya oluşturulamadı.");
  }

  return f;
}
