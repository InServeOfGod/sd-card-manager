#include "kernel.h"

void setup() {
  Serial.begin(9600);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);

  while (!Serial) {
    delay(1);
  }

  getChoices();
}

void loop() {
  checkSD();
  Serial.println("Seçim : ");
  int choose = getNumberInput();

  switch (choose) {
    case LIST_ALL:
      listDir("/");
      break;

    case LIST_DIR:
      listDir(requirePath());
      break;

    case MKDIR:
      if (SD.mkdir(requirePath())) {
        Serial.println("Klasör oluşturuldu.");
      } else {
        Serial.println("Klasör oluşturulamadı.");
      }

      break;

    case RMDIR:
      if (SD.rmdir(requirePath())) {
        Serial.println("Klasör silindi.");
      } else {
        Serial.println("Klasör silinemedi.");
      }

      break;

    case MKFILE:
      makeFile();
      break;

    case READFILE: {
        File f = SD.open(requirePath(), FILE_READ);
        long file_size = f.size();

        if (f) {
          Serial.println("Dosya içerikleri alınıyor...");

          for (long i = 0; i < file_size; i++) {
            Serial.print((char)f.read());
          }

          Serial.println();
          f.close();

        } else {
          Serial.println("Dosya bulunamadı.");
        }
      }

      break;

    case WRITEFILE: {
        File file = makeFile();

        if (file) {
          Serial.println("Dosyaya yaz : ");
          String content = getStrInput();

          file.print(content);
          file.close();
          Serial.println("Dosyaya yazıldı.");
        } else {
          Serial.println("Dosyaya yazılırken hata oluştu.");
        }
      }

      break;

    case RMFILE:
      if (SD.remove(requirePath())) {
        Serial.println("Dosya silindi");
      } else {
        Serial.println("Dosya silinemedi");
      }

      break;

    default:
      Serial.println("Geçersiz seçenek!");
  }
}
