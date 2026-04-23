# Práctica 4. El lenguaje PostScript

## Objetivos
- Conocer la sintaxis básica del lenguaje PostScript.  
- Crear varios archivos y probar su funcionamiento con un visor PostScript.  
- Transformar los ejemplos creados a otros formatos de archivo, como PDF.  

## Cuestiones a resolver

### Árboles
Para realizar el siguiente ejercicio se han utilizado 3 círculos y un rectángulo para cada árbol. Para dibujar el círculo con su respectivo borde en otro color, se han utilizado 2 círculos idénticos; en el primero se usa `fill` y en el segundo (el borde) no.

[Enlace al código](https://github.com/parejo22/PDIH/blob/main/Practicas/P4/arboles.ps)

![Árboles](https://github.com/user-attachments/assets/78eb3918-8101-48da-a20d-528dced1dc02)

### Tarjeta
Para este ejercicio me he inspirado en los Juegos Olímpicos de Barcelona y en cómo serían las tarjetas que llevarían colgadas las personas que entraban al recinto. El logo consiste en 5 aros simples de diferentes colores, con los que he jugado un poco usando las coordenadas. Para el texto he utilizado `scalefont` para ajustar el tamaño.

[Enlace al código](https://github.com/parejo22/PDIH/blob/main/Practicas/P4/tarjeta.ps)

![Tarjeta](https://github.com/user-attachments/assets/66d5f510-dd88-432e-8227-78ab452e9ef7)

### Corazón

Para este ejercicio he dibujado un corazón combinando dos círculos en la parte superior y una forma triangular en la parte inferior. Para los círculos he utilizado el operador arcn (arc opera en sentido contrario), ajustando las coordenadas para colocarlos uno al lado del otro y conseguir la forma redondeada característica.

Además, he tenido en cuenta el sentido de dibujo de los arcos (horario y antihorario) para que el trazo sea continuo y encaje correctamente con el resto de la figura. Finalmente, he cerrado la figura con closepath y he aplicado stroke para dibujar el contorno en color rojo.

[Enlace al código](https://github.com/parejo22/PDIH/blob/main/Practicas/P4/corazon.ps)
<img width="920" height="473" alt="image" src="https://github.com/user-attachments/assets/1233d4c0-597a-4629-bd73-0a862bcf5fb2" />

## Cuestiones extra

### Sonrisa

En este ejercicio se ha creado una composición en formato apaisado utilizando `setpagedevice` para definir el tamaño de la página en horizontal. 

Se han dibujado varios círculos concéntricos de diferentes colores empleando el operador `arc` junto con `fill`, variando el radio para conseguir el efecto de capas, otra opcion sin usar 'fill' hubiera sido jugar con el tamaño del borde.

[Enlace al código](https://github.com/parejo22/PDIH/blob/main/Practicas/P4/sonrisa.ps)
<img width="572" height="536" alt="image" src="https://github.com/user-attachments/assets/7539e36f-b5a1-47bc-b375-2b53f0fb8776" />

### Tabla y gráfica en dos páginas
En este ejercicio se han generado dos páginas dentro del mismo archivo PostScript.

En la primera página se ha dibujado una tabla con datos inventados. Para ello se han utilizado líneas (`moveto`, `lineto` y `stroke`) para formar la estructura de la tabla, y el operador `show` para insertar los datos en cada celda.

En la segunda página se ha añadido una gráfica sencilla. Los ejes de la gráfica se han creado mediante líneas, y la representación de los datos se ha realizado dibujando circulos enlazados por líneas rectas.

Para separar ambas páginas se ha utilizado el operador `showpage`, que indica el final de una página y el inicio de la siguiente.
[Enlace al código](https://github.com/parejo22/PDIH/blob/main/Practicas/P4/datos.ps)
<img width="1838" height="943" alt="image" src="https://github.com/user-attachments/assets/d509c31d-a193-48d0-85fc-22a6b4cad3d0" />

## Cambio de formato
Para cambiar de formato .ps a jpg o pdf se han usado los siguientes comandos:

`ps2pdf archivo.ps` 

`convert archivo.pdf archivo.jpg`
<img width="988" height="393" alt="image" src="https://github.com/user-attachments/assets/277e550b-074c-407e-9b4f-5ea6f6cf8b4b" />

