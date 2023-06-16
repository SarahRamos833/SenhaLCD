#include <Keypad.h> //biblioteca da matriz
#include <LiquidCrystal.h> //biblioteca do display

// Definição dos pinos do teclado numérico
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

// Definição do display LCD
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // Pinos RS, E, D4, D5, D6, D7

// Definição da senha
const String senhaCorreta = "1606"; // Senha correta

// Variáveis de controle
String senhaDigitada = ""; // Senha digitada pelo usuário

void setup() {
  lcd.begin(16, 2);
  lcd.print("Digite a senha:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '#') {
      if (senhaDigitada == senhaCorreta) {
        lcd.clear();
        lcd.print("Senha correta!");
        delay(2000);
        lcd.clear();
        lcd.print("Frase liberada...");
        delay(2000);
        lcd.clear();
        lcd.print("CURSO DE ARDUINO");
        lcd.setCursor(1, 2);
        lcd.print("DIA 16 E 17/06");
        delay(20000);
        lcd.clear();
        lcd.print("Digite a senha:");
        senhaDigitada = "";
      } else {
        lcd.clear();
        lcd.print("Senha incorreta!");
        delay(2000);
        lcd.clear();
        lcd.print("Digite a senha:");
        senhaDigitada = "";
      }
    } else {
      senhaDigitada += key;
    }
  }
}
