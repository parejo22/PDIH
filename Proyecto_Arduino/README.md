# Juego de reflejos competitivo con arduino
### Descripción

Este proyecto consiste en un juego de reflejos donde el jugador debe presionar el botón correcto lo más rápido posible cuando se enciende un LED. Está pensado para trabajar como una herramienta para estimular habilidades cognitivas y motoras en jóvenes, adultos y especialmente en personas mayores.

===

## Paso 1: Recolección de materiales

- 1 Arduino UNO
  
- 4 LEDs
  
- 4 resistencias de 220Ω
  
- 4 pulsadores (botones)
  
- 1 pantalla LCD 16x2
  
- Cables (jumper wires)
  
- Protoboard (breadboard)

## Paso 2: Montaje del circuito (Los pines pueden variar no tienen que ser exactamente los mismos)
### LEDs

Conecta cada LED con una resistencia:

LED 1 → pin 9

LED 2 → pin 10

LED 3 → pin 11

LED 4 → pin 12

El lado corto del LED va a GND.

Pulsadores

Se usará INPUT_PULLUP (sin resistencias externas):

Botón 1 → pin 2

Botón 2 → pin 3

Botón 3 → pin 4

Botón 4 → pin 5

Cada botón:

Un lado → pin digital
Otro lado → GND

### Pantalla LCD (opcional en primera versión)

Ejemplo de montaje sin pantalla lcd
<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/3095c158-602d-40b3-84f0-ca82ae748aac" />

## Paso 3: Programación

[Código **sin** pantalla lcd](https://github.com/parejo22/PDIH/blob/main/Proyecto_Arduino/pr_sinlcd.c)

[Código **con** pantalla lcd](https://github.com/parejo22/PDIH/blob/main/Proyecto_Arduino/pr_lcd.c)

## Paso 4: Prueba del sistema
- Sube el código al Arduino
- Herramientas → Monitor Serie (Aquí veremos la salida del juego)
- Para comenzar el juego, pulsa todos los pulsadores, este paso sirve para comprobar que todos los botones funcionan correctamente.
- Comprobar que todos los tipos de puntuación van bien: x>420 ns = 1p, x<420 =2p, x<275=3p y error -1
- Comprobado todo,¡Es hora de jugar! Al finalizar te mostrará tu puntuación
<img width="1313" height="921" alt="image" src="https://github.com/user-attachments/assets/0e62622c-8945-40e9-8898-21ef5b9c388d" />


## Paso 5: Añadir LCD

LCD 1 (GND)  → GND 

LCD 2 (VCC)  → 5V

LCD 3 (VO)   → GND 

LCD 4 (RS)   → pin 12

LCD 5 (RW)   → GND 

LCD 6 (E)    → pin 13

LCD 11 (D4)  → pin 6

LCD 12 (D5)  → pin 7

LCD 13 (D6)  → A1

LCD 14 (D7)  → A2

LCD 15 (LED+) → 5V  con resistencia de 220Ω

LCD 16 (LED-) → GND 

## Montaje:

<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/28d51af4-07b8-4f00-9af0-e10172b2a7f4" />
