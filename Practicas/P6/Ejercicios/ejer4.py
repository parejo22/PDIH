import cv2

# MODELOS HAAR
modeloFrontal = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
modeloPerfil  = cv2.CascadeClassifier('haarcascade_profileface.xml')
modeloCuerpo  = cv2.CascadeClassifier('haarcascade_fullbody.xml')

# HOG 
hog = cv2.HOGDescriptor()
hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())

# VIDEO
camara = cv2.VideoCapture('v4.mp4')

while camara.isOpened():
    ret, img = camara.read()
    if not ret:
        break

    gris = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # DETECCIÓN HAAR
    caras = modeloFrontal.detectMultiScale(gris, 1.2, 5)
    perfiles = modeloPerfil.detectMultiScale(gris, 1.2, 5)
    cuerpos = modeloCuerpo.detectMultiScale(gris, 1.1, 3)

    # caras frontales (azul)
    for (x, y, w, h) in caras:
        cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0), 2)

    # caras perfil (verde)
    for (x, y, w, h) in perfiles:
        cv2.rectangle(img, (x, y), (x+w, y+h), (0, 255, 0), 2)

    # cuerpo Haar (amarillo)
    for (x, y, w, h) in cuerpos:
        cv2.rectangle(img, (x, y), (x+w, y+h), (0, 255, 255), 2)

#HOG
    personas, _ = hog.detectMultiScale(img)

    for (x, y, w, h) in personas:
        cv2.rectangle(img, (x, y), (x+w, y+h), (0, 0, 255), 2)

#mostrar
    cv2.imshow("Output", img)

    if cv2.waitKey(1) == 27:
        break

camara.release()
cv2.destroyAllWindows()
