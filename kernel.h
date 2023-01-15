#include <SPI.h>
#include <SD.h>
#include "input.h"
#include "files.h"

#define LIST_ALL 1
#define LIST_DIR 2
#define MKDIR 3
#define RMDIR 4
#define MKFILE 5
#define READFILE 6
#define WRITEFILE 7
#define RMFILE 8

#define GREEN_PIN 7
#define RED_PIN 8
