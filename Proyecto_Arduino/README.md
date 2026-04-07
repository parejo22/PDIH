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

Usaremos INPUT_PULLUP (sin resistencias externas):

Botón 1 → pin 2
Botón 2 → pin 3
Botón 3 → pin 4
Botón 4 → pin 5

Cada botón:

Un lado → pin digital
Otro lado → GND

### Pantalla LCD (opcional en primera versión)

Puedes añadirla después para mostrar información del juego.

Ejemplo de montaje sin pantalla lcd
<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/3095c158-602d-40b3-84f0-ca82ae748aac" />

## Paso 3: Programación


## Paso 4: Prueba del sistema
- Sube el código al Arduino
- Herramientas → Monitor Serie (Aquí veremos la salida del juego)
- Para comenzar el juego, pulsa todos los pulsadores
- Comprobar que todos los tipos de puntuación van bien: x>420 ns = 1p, x<420 =2p, x<275=3p y error -1
- Al finalizar te mostrará tu puntuación
<img width="1313" height="921" alt="image" src="https://github.com/user-attachments/assets/0e62622c-8945-40e9-8898-21ef5b9c388d" />


