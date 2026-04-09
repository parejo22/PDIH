# Seminario: Módulos cargables del Kernel (LKM)

---

## Introducción

Un **Loadable Kernel Module (LKM)** es un archivo que contiene código objeto que puede cargarse en el kernel de Linux en tiempo de ejecución.  

Este mecanismo permite extender las funcionalidades del kernel sin necesidad de recompilarlo completamente.

Los módulos del kernel se utilizan principalmente para:

- Controladores de dispositivos
- Sistemas de archivos
- Extensión de funcionalidades del kernel

Los módulos se ejecutan en el **espacio del kernel**, mientras que las aplicaciones normales se ejecutan en el **espacio de usuario**.

### Objetivos
  
- Conocer cómo funciona el sistema de módulos cargables del kernel de Linux
- Hacer un módulo sencillo.
    
---
## 1. Preparación del sistema para construir LKMs
