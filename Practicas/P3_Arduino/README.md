
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


