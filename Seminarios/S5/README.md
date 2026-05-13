
# Seminario: Manejo de Sonido y Cancelación de Ruido en R

## Objetivos
1.  **Identificar y representar** gráficamente la forma de onda de señales de sonido.
2.  **Conocer la estructura** de un fichero de sonido WAV y sus parámetros (frecuencia, resolución, canales).
3.  **Utilizar RStudio** y las librerías `tuneR` y `seewave` para el procesamiento de audio.
4.  **Comprender los fundamentos físicos** de la cancelación de ruido y la cancelación de fase.
5.  **Crear programas** para manipular sonidos (unir, trocear, invertir fase).

## Material utilizado
* **Entorno:** RStudio.
* **Librerías de R:** `tuneR`, `seewave`, `audio`.
* **Archivos de sonido:** Formatos WAV y MP3.

---

## Ejercicio: Análisis y Manipulación de Sonido

En este ejercicio se cargan dos archivos de sonido, se analiza su cabecera y se unen en un solo archivo.

### [Código en R](https://github.com/parejo22/PDIH/edit/main/Seminarios/S5/S_ejer1.R)

Código explicado paso a paso:

1. Instalación y carga de librerías:
  ```R
  # install.packages('tuneR', dep=TRUE)
  # install.packages('seewave', dep=TRUE)
  # install.packages('soundgen', dep=TRUE)
  library(tuneR)
  library(seewave)
  library(audio)
  ```

2. Para establecer el path a nuestra carpeta de trabajo se utiliza `setwd()` 
   <img width="733" height="53" alt="image" src="https://github.com/user-attachments/assets/0eb9530f-192a-4074-a274-ef9874705257" />

3. Se cargan los archivos de sonido MP3 o WAV con `readWave()`
   <img width="735" height="58" alt="image" src="https://github.com/user-attachments/assets/4f4cc77c-d629-477e-8021-d50076765c58" />
   
4. Para mostrar la forma de onda de los perro.wav y gato.wav se usa `plot`
   <img width="1840" height="752" alt="image" src="https://github.com/user-attachments/assets/4aa44178-d773-4e8e-abb5-5fe7408dd2ea" />
   
   <img width="1840" height="752" alt="image" src="https://github.com/user-attachments/assets/04200287-47e4-4bac-8773-44245c6475d2" />
 
5. Inspeccionamos y mostramos los campos del archivo de sonido usando `str()`
   <img width="712" height="287" alt="image" src="https://github.com/user-attachments/assets/12077942-576c-4cf2-b8a0-8a6d0a4dfa0f" />

6. Para juntar los sonidos del perro y el gato usamos `pastew()`.
   <img width="486" height="52" alt="image" src="https://github.com/user-attachments/assets/76a5a909-698b-4fd3-b8c3-da93aaa307a1" />

    Aunque en este caso el proceso es directo, normalmente no lo sería. Para que dos archivos de sonido se puedan pegar, tienen que tener la misma tasa de muestreo, en el caso del perro y el gato usando `str()` coinciden en 44.1 KHz. 
  
    Si un audio estuviera a una frecuencia distinta, utilizaríamos `resamp()` para igualarlos antes de unirlos. Ejemplo de uso:
  ```r
  gato_arreglado <- resamp(gato, f = 44100, output = "Wave")
  ```
7. Guardamos el resultado en el formato que deseemos con la función `writeWave`
   <img width="478" height="38" alt="image" src="https://github.com/user-attachments/assets/83f53eeb-250d-455f-95ad-9a0d845153ef" />



   


