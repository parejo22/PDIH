import cv2

# Cargamos clasificadores para cara y ojos
modeloCara = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
modeloOjo  = cv2.CascadeClassifier('haarcascade_profileface.xml')

# abrimos el flujo de vídeo desde la cámara o desde un vídeo
#camara = cv2.VideoCapture(-1)
camara = cv2.VideoCapture('v2.mp4')

while camara.isOpened():
    _, img = camara.read()
    color = cv2.cvtColor(img, cv2.COLOR_BGR2BGRA)

    faces = modeloCara.detectMultiScale(color, 1.3, 4)
    for (x, y , w ,h) in faces:
        # Dibujamos rectángulo en las caras detectadas
        cv2.rectangle(img, (x,y), (x + w, y + h), (255, 0 , 0), 3)

    eyes = modeloOjo.detectMultiScale(color, 1.3, 4)
    for (x, y , w ,h) in eyes:
        # Dibujamos rectángulo en los ojos
        cv2.rectangle(img, (x,y), (x + w, y + h), (0, 255 , 0), 3)

    cv2.imshow('img', img)
    key = cv2.waitKey(1)
    if key == 27:
        break

camara.release()
cv2.destroyAllWindows()
