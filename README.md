
# RFID Tag Reader

![IMG_3233](https://github.com/vanshksingh/Arduino_attendance/assets/114809624/f6def07d-1eea-4d70-8bc8-fc1f8b45b13d)


This project uses an Arduino with an MFRC522 RFID module and a LiquidCrystal I2C display to read and identify RFID tags and track the count of people who have used the RFID scanner. It can recognize predefined RFID tags and display corresponding names on the LCD. 

## Table of Contents
- [Hardware](#hardware)
- [Software](#software)
- [Installation](#installation)
- [Usage](#usage)
- [Customization](#customization)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Hardware

- **Arduino Board**: The project is built with an Arduino board. Ensure compatibility with your specific Arduino model.
- **MFRC522 RFID Module**: Used for reading RFID tags.
- **LiquidCrystal I2C Display**: A 16x2 LCD display to show information about scanned tags and the count of people.
- **Wires**: Used for connecting the different modules together.

## Software

- **Arduino IDE**: Used for programming the Arduino board.
- **Libraries**: You will need the following libraries:
  - `MFRC522` for RFID communication
  - `Wire` for I2C communication
  - `LiquidCrystal_I2C` for controlling the LCD

## Installation

1. **Install Libraries**: Install the necessary libraries in the Arduino IDE.
   - `MFRC522` library
   - `LiquidCrystal_I2C` library
2. **Clone the Project**: Clone this repository or copy the code into a new Arduino sketch.
3. **Upload the Code**: Connect your Arduino to your computer and upload the code to your Arduino board using the Arduino IDE.

## Usage

1. **Setup**: Connect the hardware components as specified in the code:
   - **MFRC522**: Connect the SS pin to digital pin 10 and the RST pin to digital pin 9.
   - **LCD**: Connect the I2C pins (SDA and SCL) to the Arduino's corresponding pins.
2. **Power on**: Turn on the Arduino board to start the program.
3. **Scan RFID Tags**: Bring an RFID tag close to the MFRC522 module to scan it.
4. **View Information**: The LCD display will show the name corresponding to the scanned RFID tag (if predefined) and the people count.

## Customization

- **Predefined Tags**: You can customize the predefined RFID tags and corresponding names in the code by modifying the `compareUID` function.
- **Display Messages**: Customize the messages displayed on the LCD in the `displayMessage` function.
- **People Count Logic**: Modify the logic for tracking the people count in the `displayCount` and `displayMessage` functions.

## License

This project is open-source and available under the [MIT License](LICENSE).

## Acknowledgements

This project uses the `MFRC522` and `LiquidCrystal_I2C` libraries, and we would like to acknowledge the authors and contributors of these libraries.
