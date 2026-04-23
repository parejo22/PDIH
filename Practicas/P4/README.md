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

## Corazón

Para este ejercicio he dibujado un corazón combinando dos círculos en la parte superior y una forma triangular en la parte inferior. Para los círculos he utilizado el operador arcn (arc opera en sentido contrario), ajustando las coordenadas para colocarlos uno al lado del otro y conseguir la forma redondeada característica.

Además, he tenido en cuenta el sentido de dibujo de los arcos (horario y antihorario) para que el trazo sea continuo y encaje correctamente con el resto de la figura. Finalmente, he cerrado la figura con closepath y he aplicado stroke para dibujar el contorno en color rojo.

[Enlace al código](https://github.com/parejo22/PDIH/blob/main/Practicas/P4/corazon.ps)
<img width="920" height="473" alt="image" src="https://github.com/user-attachments/assets/1233d4c0-597a-4629-bd73-0a862bcf5fb2" />
