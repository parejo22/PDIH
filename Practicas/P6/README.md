
# P6 - Reconocimiento de Imágenes (OpenCV)

## Objetivos

- Entender los fundamentos del reconocimiento de imágenes.
- Utilizar OpenCV para procesamiento de imágenes.
- Aplicar un clasificador Haar Cascade para detección facial.
- Dibujar las detecciones sobre imágenes o vídeos.

---

## Tecnologías utilizadas

- Python 3
- OpenCV (`cv2`)
- Haar Cascade Classifier (Viola & Jones)

---
## Preparación 

### 1. Crear entorno virtual

```bash
python3 -m venv venv
```

### 2. Activar entorno

```bash
source venv/bin/activate
```

### 3. Instalar dependencias

```bash
pip install opencv-python
```
## Ejercicios

### 1.Reconocimiento de caras de personas en imágenes


Este ejercicio consiste en implementar una aplicación sencilla capaz de localizar caras humanas dentro de una imagen y resaltarlas visualmente.

Para resolver el problema se utiliza OpenCV junto con un modelo ya entrenado basado en Haar Cascades. Este tipo de modelo no aprende durante la ejecución, sino que ya contiene patrones faciales predefinidos que permiten reconocer estructuras similares a caras.

El archivo utilizado ` wget https://raw.githubusercontent.com/opencv/opencv/master/data/haarcascades/haarcascade_frontalface_alt.xml ` actúa como el detector principal.

[Código](https://github.com/parejo22/PDIH/blob/main/Practicas/P6/Ejercicios/ejer1.py)

Primero se carga la imagen que se quiere analizar. Esta imagen se simplifica convirtiéndola a escala de grises, ya que el color no aporta información relevante para la detección y solo aumenta el coste de procesamiento.

Después, el modelo analiza la imagen en diferentes escalas buscando patrones que coincidan con una cara humana. Este análisis se realiza con la función detectMultiScale, que permite recorrer la imagen de forma adaptativa.

Cuando el algoritmo encuentra coincidencias suficientemente fiables, devuelve sus coordenadas.

Finalmente, el programa recorre esas coordenadas y dibuja un rectángulo sobre la imagen original para marcar cada rostro detectado.

Dentro de la detección hay varios parámetros que influyen directamente en el resultado:

-scaleFactor: controla cómo se reduce la imagen en cada iteración del análisis. Valores más bajos aumentan la precisión.
-minNeighbors: define cuántas coincidencias deben existir para considerar una detección válida.

#### Resultado:

    scaleFactor=1.1,
    minNeighbors=6
![Sin cambiar el scaleFactor](https://github.com/parejo22/PDIH/blob/main/Practicas/P6/Resultados/ej1-2.png)

    scaleFactor=1.05,
    minNeighbors=1 //Está configuración nos da más rostros, pero obtenemos más falsos positivos.
![CAmbiando el scaleFactor](https://github.com/parejo22/PDIH/blob/main/Practicas/P6/Resultados/ej1-3.png)


### 2.Reconocimiento de caras de personas en vídeos

En este segundo ejercicio se amplía el funcionamiento del programa anterior para trabajar en tiempo real sobre un vídeo en lugar de una imagen estática.

Al igual que en el ejercicio anterior, cada frame se convierte a escala de grises para simplificar la información y mejorar el rendimiento del detector.

Después, el clasificador Haar Cascade analiza cada imagen buscando patrones faciales. Cuando detecta una cara, se dibuja un rectángulo alrededor de ella y el resultado se muestra en pantalla en tiempo real.

Este proceso se repite constantemente hasta que el usuario decide cerrar el programa.

La principal diferencia es que en este caso no se trabaja sobre una única imagen, sino sobre una secuencia continua de fotogramas.

Por tanto:

-La detección se ejecuta muchas veces por segundo
-El rendimiento es más importante
-El programa necesita un bucle continuo para capturar y mostrar vídeo

Para conseguir una detección más estable se utiliza un modelo extra para detectar perfiles de personas:
 `wget https://raw.githubusercontent.com/opencv/opencv/master/data/haarcascades/haarcascade_profileface.xml`
 Resultado:
 Sin perfil:
 ![Sin perfil](https://github.com/parejo22/PDIH/blob/main/Practicas/P6/Resultados/ej2-1.png)
 Con perfil:
![Con perfil](https://github.com/parejo22/PDIH/blob/main/Practicas/P6/Resultados/ej2-2.png)
### 3.Reconocimiento de caras de gatos en vídeos
### 4.Reconocimiento de cuerpos y caras de personas en vídeos.
