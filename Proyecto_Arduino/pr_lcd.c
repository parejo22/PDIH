#include <LiquidCrystal.h>

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 13, 6, 7, A1, A2);

const int leds[] = {8, 9, 10, 11};
const int buttons[] = {2, 3, 4, 5};

int score = 0;
int rounds = 10;

unsigned long startTime;
unsigned long reactionTime;

// ----------------------------
// Esperar a pulsar TODOS
// ----------------------------
void waitForStart() {

  Serial.println("\nPulsa TODOS los botones para empezar...");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pulsa TODOS");

  lcd.setCursor(0, 1);
  lcd.print("para empezar");

  bool allPressed = false;

  while (!allPressed) {

    allPressed = true;

    for (int i = 0; i < 4; i++) {

      if (digitalRead(buttons[i]) == HIGH) {
        allPressed = false;
      }
    }
  }

  Serial.println("¡Juego iniciado!\n");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Juego iniciado");

  delay(1000);
}

// ----------------------------
// SETUP
// ----------------------------
void setup() {

  Serial.begin(9600);

  lcd.begin(16, 2);

  for (int i = 0; i < 4; i++) {

    pinMode(leds[i], OUTPUT);
    pinMode(buttons[i], INPUT_PULLUP);
  }

  randomSeed(analogRead(0));

  Serial.println("=== JUEGO DE REFLEJOS ===");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Juego Reflejos");

  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");

  delay(2000);
}

// ----------------------------
// LOOP
// ----------------------------
void loop() {

  waitForStart();

  score = 0;

  for (int r = 0; r < rounds; r++) {

    Serial.print("\nRonda ");
    Serial.println(r + 1);

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Ronda ");
    lcd.print(r + 1);

    lcd.setCursor(0, 1);
    lcd.print("Preparado...");

    delay(random(2000, 4000));

    int target = random(0, 4);

    digitalWrite(leds[target], HIGH);

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("LED ");
    lcd.print(target + 1);

    lcd.setCursor(0, 1);
    lcd.print("PULSA YA!");

    startTime = millis();

    int pressed = -1;

    while (pressed == -1) {

      for (int i = 0; i < 4; i++) {

        if (digitalRead(buttons[i]) == LOW) {
          pressed = i;
        }
      }
    }

    reactionTime = millis() - startTime;

    digitalWrite(leds[target], LOW);

    lcd.clear();

    // ------------------------
    // RESULTADO
    // ------------------------

    if (pressed == target) {

      Serial.println("Correcto");

      lcd.setCursor(0, 0);
      lcd.print("Correcto!");

      if (reactionTime < 275) {
        score += 3;
      }
      else if (reactionTime < 600) {
        score += 2;
      }
      else {
        score += 1;
      }

    } else {

      Serial.println("Incorrecto");

      lcd.setCursor(0, 0);
      lcd.print("Incorrecto");

      score -= 1;
    }

    // ------------------------
    // Mostrar tiempo
    // ------------------------

    lcd.setCursor(0, 1);
    lcd.print(reactionTime);
    lcd.print(" ms");

    Serial.print("Tiempo: ");
    Serial.print(reactionTime);
    Serial.println(" ms");

    Serial.print("Puntuacion: ");
    Serial.println(score);

    delay(2000);

    // ------------------------
    // Mostrar score
    // ------------------------

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Puntos:");

    lcd.setCursor(0, 1);
    lcd.print(score);

    delay(1500);
  }

  // ----------------------------
  // FIN DEL JUEGO
  // ----------------------------

  Serial.println("\n=== FIN DEL JUEGO ===");

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("FIN DEL JUEGO");

  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.print(score);

  delay(5000);
}
