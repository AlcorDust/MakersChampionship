# App_Broker.py
import BlynkLib
import time

BLYNK_AUTH = '8dfa75f8295242a9a496383dd674e98d'

blynk = BlynkLib.Blynk(BLYNK_AUTH)

@blynk.VIRTUAL_WRITE(1)
def my_write_handler(value):
    print('Current V1 value: {}'.format(value))

@blynk.VIRTUAL_READ(2)
def my_read_handler():
    
    blynk.virtual_write(2, time.ticks_ms() // 1000)

blynk.run()
