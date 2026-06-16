import serial
import keyboard
import time

porta_p1 = "COM10"
porta_p2 = "COM3"  # ajuste

ser_p1 = serial.Serial(porta_p1, 115200, timeout=0.01)
ser_p2 = serial.Serial(porta_p2, 115200, timeout=0.01)

teclas = {
    "P1_UP": "w",
    "P1_DOWN": "s",
    "P1_LEFT": "a",
    "P1_RIGHT": "d",
    "P1_B1": "1",
    "P1_B2": "2",
    "P1_B3": "3",
    "P1_B4": "q",
    "P1_START": "q",
    "P1_SELECT": "e",

    "P2_UP": "i",
    "P2_DOWN": "k",
    "P2_LEFT": "j",
    "P2_RIGHT": "l",
    "P2_B1": "u",
    "P2_B2": "o",
    "P2_B3": "n",
    "P2_B4": "m",
    "P2_START": "p",
    "P2_SELECT": "b"
}

def processar(comando):
    if comando:
        print(comando)

    if comando.endswith("_ON"):
        nome = comando.replace("_ON", "")
        if nome in teclas:
            keyboard.press(teclas[nome])

    elif comando.endswith("_OFF"):
        nome = comando.replace("_OFF", "")
        if nome in teclas:
            keyboard.release(teclas[nome])

print("Rodando com dois Arduinos...")

while True:
    comando_p1 = ser_p1.readline().decode(errors="ignore").strip()
    comando_p2 = ser_p2.readline().decode(errors="ignore").strip()

    processar(comando_p1)
    processar(comando_p2)