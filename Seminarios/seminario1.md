
# Seminario 1 – Compilación, cambios y ejecución del archivo Hola

## Paso 1: Compilamos Hola con C.bat
En DOSBox, al escribir C en la línea de comandos, el sistema ejecuta automáticamente el archivo C.BAT, ya que en DOS no es necesario indicar la extensión .BAT para lanzar un archivo ejecutable.

<img width="996" height="640" alt="image" src="https://github.com/user-attachments/assets/3f392006-5af7-428c-8305-0519e720d807" />
Al ejecutar nos sale hola
## Paso 2: Editamos Hola 
Simplemente escribimos en terminal "Editar hola" se nos abrira el editor
<img width="1020" height="674" alt="image" src="https://github.com/user-attachments/assets/f8169e29-6b65-4de1-92fe-97d57889a341" />
mss db va a mostrar el nuevo mensaje que quiero que muestre en este caso 'Thatś how we roll'  importante poner el simbolo del $ al final del mensaje, ya que sin el, el ordenador añadira a nuestro mensaje basura hasta que se encuentre con un simbolo de $. 
```asm
mov ah, 08h
int 21h
```
La función 08h: espera a que se pulse una tecla 

La función 09h: muestra el texto

Finalmente el resutado será:
<img width="1020" height="674" alt="image" src="https://github.com/user-attachments/assets/d0a8578d-8c1a-4455-bf9a-415c5902b7f1" />
