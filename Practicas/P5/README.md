# Práctica 5: Experimentación con el Sistema de Salida de Sonido
## 1. Objetivos de la Práctica
Los objetivos de esta práctica consisten en:
* Identificar y representar gráficamente la forma de onda de señales de sonido.
* Conocer la estructura de un fichero típico de sonido (especialmente archivos en formato WAV).
* Entender y operar con los parámetros fundamentales de una señal de sonido utilizando el lenguaje R y su entorno RStudio.

[Código]()

#### Ejercicio 1: Creación de ficheros de sonido 

Se han creado dos archivos de sonido:

- nombre.wav
- apellido.wav

Utilizando la herramienta `espeak`:

```bash
espeak -v es "Alberto" -w nombre.wav
espeak -v es "Parejo" -w apellido.wav
```
#### Ejercicio 2: Lectura de archivos y representación de formas de onda
Utilizando la función `readWave()`, se cargaron los archivos en memoria. Posteriormente, se empleó la función genérica `plot()` para visualizar de forma separada los picos y valles de amplitud en el dominio del tiempo para ambos audios.

* **Gráfico de la Onda del Nombre:**
  ![Forma de Onda Nombre]([])

* **Gráfico de la Onda del Apellido:**
  ![Forma de Onda Apellido]([])
  
  #### Ejercicio 3: Información de las cabeceras de sonido
Al ejecutar la función estructural `str()`, se identificó una incompatibilidad técnica inicial crítica entre ambos archivos:

* **Cabecera de `nombre.wav`:** Frecuencia de muestreo (`samp.rate`) de **22050 Hz**, resolución de 16 bits, tipo **Mono** (`stereo: FALSE`).
* **Cabecera de `apellido.wav`:** Frecuencia de muestreo (`samp.rate`) de **32000 Hz**, resolución de 16 bits, tipo **Estéreo** (`stereo: TRUE`).

  #### Ejercicio 4: Adaptación y Unión de las señales
De acuerdo con lo aprendido en los seminarios, dos objetos de tipo `Wave` no se pueden concatenar mediante `pastew()` si difieren en sus canales o en su tasa de muestreo. Para solventarlo:
1. Se forzó el audio del apellido a Mono mediante la función `mono(..., "left")`.
2. Se aplicó un remuestreo (downsampling) sobre el apellido utilizando la función `resamp()` para reducir su tasa desde 32000 Hz hasta los 22050 Hz correspondientes al primer audio.
3. Una vez tenemos homogeneidad, se concatenaron los archivos mediante `pastew(apellido_adaptado, nombre_wave, output="Wave").

   #### Ejercicios 5 y 6: Visualización, reproducción y almacenamiento del audio final
La señal combinada fue reproducida mediante `listen()` y mostrada en forma de gráfico usando la misma herramienta que en el ejercicio 2. Por último, se almacena bajo el nombre  `basico.wav` usando `writeWave()`.

* **Forma de onda resultante integrada (Nombre + Apellido):**
  ![Forma de Onda Combinada]()

  #### Ejercicio 7: Aplicación de filtro de frecuencia
Se procesa el audio unificado a través de un filtro de frecuencia de tipo **banda eliminada** usando la función `bwfilter()`, configurando `bandpass = FALSE`.Se eliminó por completo el rango superior situado entre los **10.000 Hz y 20.000 Hz**.El resultado limpio fue exportado como `filtrado.wav`.

#### Ejercicio 8: Efectos de Eco e Inversión Temporal
1. **Eco:** Tomando como origen `basico.wav`, se utilizó la función `echo()`, inyectando retardos mediante el parámetro `delay = c(0.5, 1.0, 1.5)` y controlando su atenuación progresiva (`amp`). Se exportó como `eco.wav`.
2. **Sonido al revés:** Con la función de inversión temporal `revw()`, se alteró la indexación de las muestras, provocando que el audio se escuche en sentido inverso.El resultado se guardó como `alreves.wav`.
