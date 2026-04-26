
# Práctica 3: Experimentación con Arduino
---

## Introducción

En esta práctica se ha trabajado con la plataforma Arduino para desarrollar programas básicos de entrada/salida.  

El objetivo principal ha sido familiarizarse con el entorno de desarrollo, la configuración de la placa y la implementación de pequeños proyectos electrónicos.

---

## Materiales utilizados

- Arduino 
- LEDs (rojo, amarillo, verde)  
- Resistencias  
- Pulsador  
- Protoboard (breadboard)  
- Cables de conexión  
- [Otros componentes si usas ampliados]

---

## Configuración del entorno

Se ha realizado la instalación del IDE de Arduino y la configuración de la placa siguiendo estos pasos:

- Selección de la placa: Arduino 
- Selección del puerto serie correspondiente  
- Conexión mediante cable USB  

---

## Proyecto 1: Secuencia de LEDs

### Descripción

Se ha implementado un sistema en el que tres LEDs (rojo, amarillo y verde) se encienden y apagan de forma alterna cada 1.5 segundos.

### Esquema del circuito

<img width="1767" height="729" alt="image" src="https://github.com/user-attachments/assets/76960613-6fea-484d-ba0c-589646851295" />


### Código

```c
// Descripción de pines
int ledRojo = 11;
int ledAmarillo = 12;
int ledVerde = 13;

void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  digitalWrite(ledRojo, HIGH);
  delay(1500);
  digitalWrite(ledRojo, LOW);

  digitalWrite(ledAmarillo, HIGH);
  delay(1500);
  digitalWrite(ledAmarillo, LOW);

  digitalWrite(ledVerde, HIGH);
  delay(1500);
  digitalWrite(ledVerde, LOW);
}
```
<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/d56f850d-1024-489f-b375-642975ffa0e9" />

## Proyecto 2: LED con pulsador

### Descripción

Se ha modificado el sistema anterior para que el LED rojo se encienda únicamente al pulsar un botón conectado al pin 7. En ese momento, los otros LEDs permanecen apagados.

### Esquema del circuito

<img width="1768" height="762" alt="image" src="https://github.com/user-attachments/assets/c68c47a3-2ea1-4f70-9393-3cc3a5183c23" />


### Código

```c
int ledRojo = 11;
int ledAmarillo = 12;
int ledVerde = 13;
int boton = 7;

void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(boton, INPUT);
}

void loop() {
  int estado = digitalRead(boton);

  if (estado == HIGH) {
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledVerde, LOW);
  } else {
    digitalWrite(ledRojo, LOW);
  }
}
```
### Código con lógica de input_pullup para no usar tanto cable

```c
int ledRojo = 11;
int ledAmarillo = 12;
int ledVerde = 13;
int boton = 7;

void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
}

void loop() {
  int estado = digitalRead(boton);

  if (estado == LOW) { // ← botón presionado
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledVerde, LOW);
  } else { // botón suelto
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledAmarillo, HIGH);
    digitalWrite(ledVerde, HIGH);
  }
}
```
<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/4725dee8-864a-44bd-b657-7318d4362e5a" />

## Proyecto 3: Secuencia de LEDs tipo "coche fantástico"

### Descripción

Se ha implementado una secuencia de 4 LEDs que se encienden de forma progresiva de izquierda a derecha y viceversa, simulando el efecto de las luces del coche fantástico.

### Materiales utilizados

- Arduino  
- 4 LEDs  
- 4 resistencias de 220Ω  
- Protoboard  
- Cables de conexión  

### Esquema del circuito

<img width="1469" height="806" alt="Captura desde 2026-04-26 12-44-17" src="https://github.com/user-attachments/assets/99af4d2a-c0dc-461d-a685-341325563db3" />

### Código

```c
int leds[] = {2, 3, 4, 5};
int numLeds = 4;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // Ida
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], HIGH);
    delay(100);
    digitalWrite(leds[i], LOW);
  }

  // Vuelta
  for (int i = numLeds - 2; i > 0; i--) {// numleds -2 para que no ilumine de nuevo el ultimo encendido
    digitalWrite(leds[i], HIGH);
    delay(100);
    digitalWrite(leds[i], LOW);
  }
}
```
<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/df14f183-b920-4ee9-90a9-859d84d9d87e" />
[Ver demo](https://github.com/parejo22/PDIH/blob/main/Practicas/P3_Arduino/fantastico.mp4)

## Proyecto 4: Sensor de distancia con buzzer

### Descripción

Se ha desarrollado un sistema que mide la distancia a un objeto mediante un sensor ultrasónico.
En función de la distancia detectada, el buzzer emite un sonido cuya frecuencia varía.

### Materiales utilizados

- Arduino
- Sensor ultrasónico HC-SR04
- Buzzer (pasivo)
- Protoboard
- Cables de conexión

### Esquema del circuito

<img width="1499" height="858" alt="Captura desde 2026-04-26 19-10-57" src="https://github.com/user-attachments/assets/a9ed00af-ebff-4504-9057-29b7c0fdc294" />

### Código

```c
const int trigPin = 10;
const int echoPin = 9;
const int buzzer = 8;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duracion;
  int distancia;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracion = pulseIn(echoPin, HIGH);
  distancia = duracion * 0.034 / 2;

  if (distancia < 50) {
    int frecuencia = map(distancia, 0, 50, 2000, 200);
    tone(buzzer, frecuencia);
  } else {
    noTone(buzzer);
  }

  delay(100);
}
```
<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/75bdac06-cc7d-4b48-be08-0ec174486ce0" />
[Ver demo](https://github.com/parejo22/PDIH/blob/main/Practicas/P3_Arduino/distancia.mp4)

## Proyecto 5: Sensor de luz con fotosensor

### Descripción

Se ha implementado un sistema que detecta la cantidad de luz mediante un fotosensor (LDR).
Un LED varía su intensidad en función de la luz ambiente.

### Materiales utilizados

- Arduino
- LDR (fotosensor)
- Resistencia de 10kΩ
- LED
- Resistencia de 220Ω
- Protoboard
- Cables de conexión

### Esquema del circuito

<img width="1499" height="858" alt="Captura desde 2026-04-26 13-29-27" src="https://github.com/user-attachments/assets/87679668-ecb0-4c18-b94d-5cf67e33f93e" />
<img width="1499" height="858" alt="Captura desde 2026-04-26 13-29-35" src="https://github.com/user-attachments/assets/28e6a0fb-a32c-4db1-a833-192e5bf9b649" />

El valor minimo es un poco superior a 0, ya que al hacer el circuito físico era casi imposible apagar el led por completo. Por lo que subiendo un poco el valor es más facil ver el correcto funcionamiento del circuito.

### Código

```c
int ldrPin = A0;
int ledPin = 5;
Serial.begin(9600);

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int valor = analogRead(ldrPin);
   Serial.println(distance);
  // Mapear a brillo LED
  int brillo = map(valor, 300, 1023, 0, 255);

  analogWrite(ledPin, brillo);

  delay(100);
}
}
```
<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/c93ce1cd-13b7-46ee-99e3-0b32d9a7e3e1" />
<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/83b29d62-066a-4b34-90c8-7c1ceecda1be" />

## Proyecto 6: Control de servo con pulsador

### Descripción

Se ha desarrollado un sistema en el que un servo motor se activa al pulsar un botón.
Cuando el botón está presionado, el servo gira a una posición determinada; en caso contrario, vuelve a su posición inicial.

### Materiales utilizados

- Arduino
- Servo motor
- Pulsador
- Protoboard
- Cables de conexión

### Esquema del circuito

<img width="1499" height="858" alt="Captura desde 2026-04-26 20-26-32" src="https://github.com/user-attachments/assets/d9c2d1d2-9a98-4e8a-a3a7-eb28360503b9" />
<img width="1499" height="858" alt="image" src="https://github.com/user-attachments/assets/83e6e383-1622-49b4-b646-d70d2b1b8b8b" />


### Código

```c
#include <Servo.h>

Servo miServo;
int boton = 2;

void setup() {
  miServo.attach(9);
  pinMode(boton, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(boton) == LOW) {
    miServo.write(90); // gira
  } else {
    miServo.write(0);  // posición inicial
  }
}
```
<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/25fd5b15-8be1-44c3-8a9a-31f2bf82875d" />
[Ver demo](https://github.com/parejo22/PDIH/blob/main/Practicas/P3_Arduino/motor.mp4)
