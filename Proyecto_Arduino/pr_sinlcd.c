const int leds[] = {8, 9, 10,11};
const int buttons[] = {2, 3, 4,5};

int score = 0;
int rounds = 10;

unsigned long startTime;
unsigned long reactionTime;

//  función para esperar a que todos los botones estén pulsados
void waitForStart() {
  Serial.println("\nPulsa TODOS los botones para empezar...");

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
  delay(500);
}

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
    pinMode(buttons[i], INPUT_PULLUP);
  }

  randomSeed(analogRead(0));

  Serial.println("=== JUEGO DE REFLEJOS ===");
}

void loop() {

  waitForStart();  //  espera inicio manual

  score = 0;

  for (int r = 0; r < rounds; r++) {

    Serial.print("\nRonda ");
    Serial.println(r + 1);
    Serial.println("Prepárate...");

    delay(random(2000, 4000));

    int target = random(0, 4);

    Serial.print("LED encendido: ");
    Serial.println(target + 1);

    digitalWrite(leds[target], HIGH);
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

    if (pressed == target) {
      Serial.println("✅ Correcto");

      if (reactionTime < 275) score += 3;
      else if (reactionTime < 600) score += 2;
      else score += 1;

    } else {
      Serial.println("❌ Incorrecto");
      score -= 1;
    }

    Serial.print("Tiempo: ");
    Serial.print(reactionTime);
    Serial.println(" ms");

    Serial.print("Puntuación actual: ");
    Serial.println(score);

    delay(1500);
  }

  Serial.println("\n=== FIN DEL JUEGO ===");
  Serial.print("🏆 PUNTUACIÓN FINAL: ");
  Serial.println(score);

  Serial.println("\nPulsa todos los botones para jugar otra vez...");
}
