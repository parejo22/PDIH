# PRÁCTICA 5: Experimentación con el sistema de salida de sonido

#Carga de librerías necesarias 
library(tuneR)
library(seewave)
library(audio)

# Ejercicio 1: Creación de ficheros de sonido(Ruta hacia los ficheros)
setwd("/home/alberto-parejo/PDIH teoria")

# Ejercicio 2: Leer los ficheros creados y dibujar su forma de onda por separado
nombre_wave <- readWave("nombre.wav")
apellido_wave <- readWave("apellido.wav")

# Dibujar las formas de onda originales
plot(nombre_wave, main="Forma de onda original - Nombre (Mono, 22050Hz)")
plot(apellido_wave, main="Forma de onda original - Apellido (Estéreo, 32000Hz)")

# Ejercicio 3: Obtener la información de las cabeceras de ambos sonidos
str(nombre_wave)
str(apellido_wave)

# Ejercicio 4: Adaptación y Unión de ambos sonidos
# Al tener muestreos y canales distintos (22050Hz Mono frente a 32000Hz Estéreo),
# procedemos a homogeneizarlos.

# 4a. Convertimos el objeto 'apellido' a Mono (tomando el canal izquierdo)
apellido_mono <- mono(apellido_wave, "left")

# 4b. Remuestreamos (downsampling) el apellido de 32000Hz a 22050Hz usando resamp()
apellido_adaptado <- resamp(apellido_mono, f=32000, g=22050, output="Wave")

# 4c. Concatenamos ambos audios compatibles usando pastew()
basico_wave <- pastew(apellido_adaptado, nombre_wave, output="Wave")

# Ejercicio 5: Dibujar la forma de onda de la señal resultante y reproducirla
plot(basico_wave, main="Forma de onda - Nombre y Apellido Unidos")
listen(basico_wave)

# Ejercicio 6: Almacenar el sonido resultante en un archivo llamado "basico.wav"
writeWave(basico_wave, filename = file.path("basico.wav"))

#---------------------------------
# REQUISITOS AMPLIADOS 

# Ejercicio 7: Aplicar filtro de frecuencia (eliminar entre 10.000 Hz y 20.000 Hz)
# Usamos bwfilter() configurando un filtro con bandpass = FALSE (banda eliminada)
filtrado_wave <- bwfilter(basico_wave, 
                          f = basico_wave@samp.rate, 
                          channel = 1, 
                          from = 10000, 
                          to = 20000, 
                          bandpass = FALSE, 
                          output = "Wave")

# Almacenar la señal
writeWave(filtrado_wave, filename = file.path("filtrado.wav"))

# Ejercicio 8: Aplicar efecto de eco, dar la vuelta al sonido y almacenarlos
# Volvemos a leer "basico.wav"
basico_para_eco <- readWave("basico.wav")

# Aplicar eco mediante la función echo() 
eco_wave <- echo(basico_para_eco, 
                 f = basico_para_eco@samp.rate, 
                 amp = c(0.6, 0.3, 0.1), 
                 delay = c(0.5, 1.0, 1.5), 
                 output = "Wave")

# Forzar coherencia en los límites del canal izquierdo 
eco_wave@left <- eco_wave@left

# Guardar sonido con eco en "eco.wav"
writeWave(eco_wave, filename = file.path("eco.wav"))

# Darle la vuelta al sonido utilizando revw() 
alreves_wave <- revw(basico_para_eco, output="Wave")

# Guardar sonido 
writeWave(alreves_wave, filename = file.path("alreves.wav"))

