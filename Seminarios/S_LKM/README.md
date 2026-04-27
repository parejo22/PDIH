
# Seminario: Módulos cargables del kernel (LKM)

---

## Introducción

Un **Loadable Kernel Module (LKM)** es un archivo que contiene código objeto que puede cargarse en el kernel de Linux en tiempo de ejecución.  

Este mecanismo permite extender las funcionalidades del kernel sin necesidad de recompilarlo completamente.

Los módulos del kernel se utilizan principalmente para:

- Controladores de dispositivos
- Sistemas de archivos
- Extensión de funcionalidades del kernel

Los módulos se ejecutan en el espacio del kernel, mientras que las aplicaciones normales se ejecutan en el espacio de usuario.

### Objetivos
  
- Conocer cómo funciona el sistema de módulos cargables del kernel de Linux
- Realizar un módulo sencillo.
    
---
## 1. Preparación del sistema para construir LKMs

1. Comprobar la versión del kernel:
   
   `uname -r`
   
   <img width="818" height="112" alt="image" src="https://github.com/user-attachments/assets/bbaf3b45-179a-4e5c-9834-fe179eebe1e3" />
   
3. Actualizar y instalar las cabeceras necesarias

   `sudo apt update` 

   `sudo apt-cache search linux-headers-$(uname -r)`
   
   `sudo apt-get install linux-headers-$(uname -r)`
   
5. Se crea un directorio aislado para realizar el seminario
   
   `mkdir ~/lkm_test`
   
   `cd ~/lkm_test`
   
7. Código hello.c y Makefile
   
El siguiente código lo ha proporcionado el profesor como ejemplo base de un módulo cargable del kernel. A partir de este ejemplo se puede ver la estructura básica de un LKM en Linux, con sus funciones de inicialización y de limpieza del módulo, además del uso de printk para poder enviar mensajes a los logs del sistema.

Gracias a este ejemplo se entiende cómo se registra un módulo en el kernel y también cómo se puede modificar su comportamiento mediante el uso de module_param.
   
   [hello.c](https://github.com/parejo22/PDIH/blob/main/Seminarios/S_LKM/hello.c)

   [Makefile](https://github.com/parejo22/PDIH/blob/main/Seminarios/S_LKM/Makefile)
   
9. Ejecución
    
   - Compilación
     
     Se ejecuta `make` y se observa cómo se crea el archivo hello.ko.
     
     <img width="1518" height="498" alt="image" src="https://github.com/user-attachments/assets/f2b3f11f-2913-4dd4-953b-afc88e4145ff" />

   - Logs generados
     
     Para ver los logs en otra terminal ejecutamos:
     
     `sudo dmesg | tail` justo después de ejecutar los comandos de carga y descarga del módulo.
     
   - Carga del módulo
     
     A continuación, se ejecuta:
     
     `sudo insmod hello.ko`
     
     resultado:
     
     <img width="1617" height="577" alt="image" src="https://github.com/user-attachments/assets/f5608ceb-c9d4-49ca-be51-30581d13417d" />

     
   - Comprobación
     
     Para comprobar, se utiliza: `lsmod | grep hello`
     
     <img width="812" height="574" alt="image" src="https://github.com/user-attachments/assets/71874a65-b563-494e-a76a-1cc66d877eb6" />
     
   - Datos
     
     Se puede ver la información del módulo con:
     
      ` modinfo hello.ko `
     
<img width="812" height="574" alt="image" src="https://github.com/user-attachments/assets/21576ab2-859b-488b-a2f0-eecf1e34738a" />

   - Descarga del módulo
     
     Por último, se ejecuta `sudo rmmod hello`
     
     resultado:
     
     <img width="1619" height="574" alt="image" src="https://github.com/user-attachments/assets/9d5b80a4-fe4d-4207-8aa0-9c4316c08f94" />
