@echo off
REM Eugenio Martínez - https://t.me/octulioBiletan - Abril de 2023-
REM Versión 5.0 de hay-red.cmd para Windows en español y en inglés.
REM Es más eficaz que las otras versiones.
REM ---------------------------------------------------------------
chcp 1252 > nul
set silencioso=0
if "%1" == "" goto paso1
if "%1" == "/a" (echo [Ayuda]&&echo Opción /s --- modo silencioso&&goto fin)
if "%1" == "/s" (set silencioso=1&&goto paso1)
echo ERROR: Opción no reconocida.
echo Solicite una ayuda con opción /a.&&goto fin

:paso1
ver /?|find "Displays" > nul
if %ERRORLEVEL% == 0 goto Wingles

ver /?|find "Muestra" > nul
if %ERRORLEVEL% == 0 goto Wcastellano
ver /?|find "Mostrar" > nul
if %ERRORLEVEL% == 0 goto Wcastellano
echo Idioma no reconocido: español e inglés únicamente.
goto fin

:Wingles
if %silencioso% == 1 goto paso2
echo Windows en inglés.
:paso2
set idioma=1
goto rutina

:Wcastellano
if %silencioso% == 1 goto paso3
echo Windows en español.
:paso3
set idioma=2

:rutina
echo hay-red.cmd [versión 5.0 * abril\2023]
echo Comprobando si hay red...
ping -n 3 1.1.1.1 > nul
if %ERRORLEVEL% == 1 goto nRed

echo Aguarde un momento...
if %idioma% == 2 goto Wcast2
REM Busca la palabra "unreachable." al final de la línea de textos
ping -n 3 1.1.1.1|findstr /r "able.\>" > nul
if %ERRORLEVEL% == 0 goto nRed2
goto siga

:Wcast2
REM Busca la palabra "inaccesible." al final de la línea de textos
ping -n 3 1.1.1.1|findstr /r "ible.\>" > nul
if %ERRORLEVEL% == 0 goto nRed2

:siga
if %silencioso% == 1 goto paso4
netsh wlan show interfaces
netsh lan show interfaces
netsh interface show interface
ipconfig|find "IPv4"
echo ___________________
echo Adaptadores activos
echo ___________________
wmic nicconfig get macaddress,dhcpserver,description,dnsserversearchorder,defaultipgateway,winsprimaryserver|findstr /r /i "mac"
wmic nicconfig get macaddress,dhcpserver,description,dnsserversearchorder,defaultipgateway,winsprimaryserver|find "{"

:paso4
echo --- Sí, si hay red. ---
goto fin

:nRed
if %silencioso% == 1 goto paso5
netsh interface show interface

:paso5
echo No, no hay red.
echo No hay conexión hacia el exterior.
goto fin

:nRed2
if %silencioso% == 1 goto paso6
netsh interface show interface

:paso6
echo No, no hay red.
echo La tarjeta de red está desconectada.

:fin
chcp 850 > nul
pause
