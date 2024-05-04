#-------------------------------------------------------------------------------
# Name:      enviarAvisoTelegram-modelo.py
# Purpose:   Enviar un mensaje de texto a un bot de Telegram.
#	     El bot tiene que estar vinculado a una cuenta de usuario de Telegram.
# Author:    Octulio Biletán.
# Created:   03/05/2024
# Copyright: (c) Octulio Biletán 2024
# Licence:   Software Libre.
#-------------------------------------------------------------------------------
import requests

def main():
    # Ponga aquí su TOKEN suministrado por Telegram.
    token = '0123456789:zxCVABCDE_1_ABCD2ABCDEFF-3ABCDE4xyz'
    
    # Ponga aquí su CHAT_ID suministrado por Telegram.
    chat_id = '9976543201'
    
    # Ingrese Usted el mensaje de textos desde el teclado.
    msj = str(input("Mensaje: "))

    # Modelo a seguir ··>> https://api.telegram.org/bot<TOKEN>/sendMessage?chat_id=<CHAT_ID>&text=msgA%20msgB%20msgC
    
    # Manda mensaje al 'bot telegram' destinatario que Usted definió y asoció con su cuenta de Telegram.
    requests.post('https://api.telegram.org/bot' + token + '/sendMessage', data = {'chat_id': chat_id, 'text': msj})

    print("Ok.")

if __name__ == '__main__':
    main()
