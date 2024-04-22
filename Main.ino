#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;

// Initialize the LCD with the I2C address 0x27 (for a 16x2 display)
LiquidCrystal_I2C lcd(0x27, 16, 2);

int peopleCount = 0; // Initialize people count

void setup() {
  Serial.begin(9600);
  Wire.begin(); // Initialize I2C communication
  lcd.init();   // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
  SPI.begin();  // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

  lcd.print("RFID Tag Reader");
  lcd.setCursor(0, 1);
  lcd.print("Scan a tag...");
  delay(2000);
  lcd.clear();
}

void loop() {
  displayCount();

  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if (!rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been read                                                    
  if (!rfid.PICC_ReadCardSerial())
    return;

  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

  // Check if the PICC is of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
      piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
      piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    displayMessage("Not MIFARE Classic");
    delay(2000);
    return;
  }

  // Compare the detected NUID with predefined NUIDs and print corresponding names
  if (compareUID(rfid.uid.uidByte, 0x7E, 0x0C, 0x5D, 0x73)) {
    displayMessage("Pranjal Shah");
  }
  else if (compareUID(rfid.uid.uidByte, 0x4E, 0x88, 0x5E, 0x73)) {
    displayMessage("Aagaaz Kapoor");
  }
  else if (compareUID(rfid.uid.uidByte, 0xB3, 0xC2, 0x72, 0xCD)) {
    displayMessage("Anubhav Shivare");
  }
  else if (compareUID(rfid.uid.uidByte, 0x63, 0xD6, 0xD0, 0xFC)) {
    displayMessage("Yash Rajput");
  }
  else {
    displayMessage("Unknown card");
  }

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();

  delay(2000);
}

void displayCount() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Name:");
  lcd.setCursor(0, 1);
  lcd.print("Count: ");
  lcd.print(peopleCount);
}

void displayMessage(const char* message) {
  lcd.clear();
  lcd.print(message);
  if (peopleCount > 0) {
    peopleCount--; // Decrease count if the same card is tapped again
  }
}

bool compareUID(byte* uid, byte byte0, byte byte1, byte byte2, byte byte3) {
  byte comparisonArray[4] = {byte0, byte1, byte2, byte3};
  for (int i = 0; i < 4; i++) {
    if (uid[i] != comparisonArray[i]) {
      return false;
    }
  }
  return true;
}
