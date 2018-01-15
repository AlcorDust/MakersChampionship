# Voice_Assistant.py
from subprocess import Popen
import serial
import time

def text2speech(text):
    
    #comando = 'espeak -v it+f1 -s150 -g8 "' + text + '" &'
    comando = 'pico2wave -l=it-IT -w a.wav "' + text + '"'
    proc=Popen(comando, shell=True)
    proc.wait()
    proc=Popen('play a.wav', shell=True)
    proc.wait()

ser = serial.Serial('/dev/ttyACM1', 9600)
X = [0, 0]
i = 11

while(1):

    #########################################################
    result = ser.readline()
    parsed = str(result).split(",")
    #print(parsed)
        
    X[0]=parsed[1]      # Codice comando
    X[1]=parsed[2]      # Valore comando
    
    print("INPUT: {}, {}".format(X[0], X[1]))
    print(X[0])
    #########################################################

    if X[0] == '0':    
        #text2speech(str(i))
        if X[1] == '1':
            text2speech("Hai acceso il boiler, notifica di spegnimento tra 2 ore");
        if X[1] == '0':
            text2speech("Hai spento il boiler, con un ritardo di un ora. Te piace spende li sordi eh");  

    if X[0] == '1':    
        #text2speech(str(i))
        if X[1] == '1':
            text2speech("Hai acceso il riscaldamento, temperatura di spegnimento impostata a 23 gradi");
        if X[1] == '0':
            text2speech("Hai spento il riscaldamento");

    if X[0] == '2':    
        #text2speech(str(i))
        if X[1] == '1':
            text2speech("Hai acceso le luci della cucina. Attenzione, il condizionatore nel salotto è acceso");
        if X[1] == '0':
            text2speech("Hai spento le luci della cucina");   

    if X[0] == '3':    
        #text2speech(str(i))
        if X[1] == '1':
            text2speech("Hai acceso il condizionatore, ricorda di chiudere le finestre");
        if X[1] == '0':
            text2speech("Hai spento il condizionatore");

    if X[0] == '4':    
        #text2speech(str(i))
        text2speech("Fuori c'è il sole, spegni le luci. Io alzo la tapparella");  

    if X[0] == '5':    
        #text2speech(str(i))
        text2speech("Fuori è buio, accendi le luci. Io abbasso la tapparella");    
