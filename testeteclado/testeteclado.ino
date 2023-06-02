#include <Keypad.h>

const byte ROWS = 4; // Número de linhas
const byte COLS = 3; // Número de colunas
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte pinRows[ROWS] = {6, A5, 2, 4}; // Pinos das linhas
byte pinCols[COLS] = {5, 7, 3}; // Pinos das colunas

Keypad keypad = Keypad(makeKeymap(keys), pinRows, pinCols, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
  }
}
