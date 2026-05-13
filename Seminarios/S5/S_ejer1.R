
# install.packages('tuneR', dep=TRUE)
# install.packages('seewave', dep=TRUE)
# install.packages('soundgen', dep=TRUE)

library(tuneR)
library(seewave)
library(audio)

# establecer el path concreto en cada caso a la carpeta de trabajo
setwd("/home/alberto-parejo/Descargas/Telegram Desktop/S5-P5-ejemplo/ejemplo")

# 1. Leer ficheros de sonido
perro <- readWave('perro.wav')
perro
gato <- readMP3('gato.mp3')
gato

# 2. Dibujar formas de onda
plot(perro)
plot(gato)

# 3. mostrar los campos del archivo de sonido
str(perro)
str(gato)

# 4. Unir sonidos (asegurando misma frecuencia de muestreo)
# Si es necesario, usar resamp() para igualar frecuencias
s_unido <- pastew(perro, gato, output="Wave")

# 5. Guardar el resultado
writeWave(s_unido, file.path("unidos.wav"))