import cv2

print("Versión OpenCV:", cv2.__version__)

#Cargamos nuestro modelo classificador de Haar
modelo = cv2.CascadeClassifier('/home/alberto-parejo/PDIH teoria/P6_ejemplos/caras/haarcascade_frontalface_alt.xml')

if modelo.empty():
    print("Error: no se pudo cargar el modelo Haar Cascade")
    exit()

#Cargamos la imagen:
img = cv2.imread('/home/alberto-parejo/PDIH teoria/P6_ejemplos/caras/imagen_input.jpg')

if img is None:
    print("Error: no se pudo cargar la imagen")
    exit()

#Procesado:
imagen = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

#Buscamos los rostros:
rostros = modelo.detectMultiScale(
    imagen,
    scaleFactor=1.05,
    minNeighbors=6
)

print("Rostros detectados:", len(rostros))

#Ahora recorremos el array 'rostros' y dibujamos los rectángulos sobre la imagen original:
for (x,y,ancho, alto) in rostros:
    cv2.rectangle(img, (x,y), (x+ancho, y+alto), (0,0,255) , 3)

#resultado:
cv2.imshow('Output', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
