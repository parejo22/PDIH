# Seminario. Introducción al uso de Arduino
## Objetivos 
1. Conocer la plataforma arduino
2. Describir un kit de programación para Arduino
3. Instalar y realizar sencillos programas mediante el IDE de programación basado en el lenguaje Processing de Arduino.
4. Conocer herramientas adicionales para el diseño de prototipos en Arduino (Fritzing).

## Ejercicio 1:
Código:
```c
const int ledRojo = 12;
const int ledVerde = 13;

void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  // Rojo encendido, verde apagado
  digitalWrite(ledRojo, HIGH);
  digitalWrite(ledVerde, LOW);
  delay(1500);

  // Verde encendido, rojo apagado
  digitalWrite(ledRojo, LOW);
  digitalWrite(ledVerde, HIGH);
  delay(1500);
}
```
<img width="1772" height="713" alt="image" src="https://github.com/user-attachments/assets/a3bc4616-32e5-465c-b54b-4dd1f5ed681a" />

```c
const int led = 12;
const int boton = 7;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
}

void loop() {
  // Si el botón está pulsado
  if (digitalRead(boton)  == LOW) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
```

## Ejercicio 2:
<img width="1759" height="623" alt="image" src="https://github.com/user-attachments/assets/3b8a8764-729b-49f1-8b0c-0001e3c8c6d5" />
