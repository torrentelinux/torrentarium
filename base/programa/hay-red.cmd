@echo off
REM Eugenio Mart�nez - https://t.me/octulioBiletan - Junio de 2023-
REM Versi�n 7.0 de hay-red.cmd para Windows en espa�ol y en ingl�s.
REM Comprueba el funcionamiento b�sico del servicio DNS.
REM Es m�s eficaz que las otras versiones anteriores.
REM Uso: hay-red [/a]|[/c]|[/s]
REM /a Muestra una simple ayuda del comando.
REM	/c Muestra una ayuda m�s completa del comando.
REM /s Corre el comando en modo silencioso, no muestra demasiado texto en pantalla.
REM -------------------------------------------------------------------------------
chcp 1252 > nul
set silencioso=0
set txtAyuda=%~dp0\hay-red-ayuda.txt

if "%1" == "" goto paso1
if "%1" == "/a" (echo [Ayuda]&&echo Opci�n /c --- muestra una ayuda m�s completa&&echo Opci�n /s --- modo silencioso&&goto fin)
if "%1" == "/c" (type %txtAyuda%&&goto fin)
if "%1" == "/s" (set silencioso=1&&goto paso1)
echo ERROR: Opci�n no reconocida.
echo Solicite una ayuda con opci�n /a.&&goto fin

:paso1
ver /?|find "Display" > nul
if %ERRORLEVEL% == 0 goto Wingles

ver /?|find "Muestra" > nul
if %ERRORLEVEL% == 0 goto Wcastellano
ver /?|find "Mostrar" > nul
if %ERRORLEVEL% == 0 goto Wcastellano
echo Idioma no reconocido: espa�ol e ingl�s �nicamente.
goto fin

:Wingles
if %silencioso% == 1 goto paso2
echo Windows en ingl�s.
:paso2
set idioma=1
goto rutina

:Wcastellano
if %silencioso% == 1 goto paso3
echo Windows en espa�ol.
:paso3
set idioma=2

:rutina
echo hay-red.cmd [versi�n 7.0 * junio\2023]
echo Comprobando si hay red...
ping -n 3 1.1.1.1 > nul
if %ERRORLEVEL% == 0 goto rutina2
if %idioma% == 2 goto Wcast2A

REM Averigua si el servicio DNS est� activo
nslookup 1.1.1.1 | findstr /r "Name" > nul
if %ERRORLEVEL% == 0 goto siga
goto nRed

:Wcast2A
REM Averigua si el servicio DNS est� activo
nslookup 1.1.1.1 | findstr /r "Nombre" > nul
if %ERRORLEVEL% == 0 goto Wcast2
goto nRed

:rutina2
echo Aguarde un momento...
if %idioma% == 2 goto Wcast2
REM Busca la palabra "unreachable." al final de la l�nea de textos
ping -n 3 1.1.1.1|findstr /r "able.\>" > nul
if %ERRORLEVEL% == 0 goto nRed2
goto siga

:Wcast2
REM Busca la palabra "inaccesible." al final de la l�nea de textos
ping -n 3 1.1.1.1|findstr /r "ible.\>" > nul
if %ERRORLEVEL% == 0 goto nRed2

:siga
if %silencioso% == 1 goto paso4
netsh wlan show interfaces
netsh lan show interfaces
netsh interface ipv4 show addresses
echo ** Resumen de direcciones IP **
ipconfig|find "IPv4"
ipconfig|find "IPv6"
echo ___________________
echo Adaptadores activos
echo ___________________
wmic nicconfig get macaddress,dhcpserver,description,dnsserversearchorder,defaultipgateway,winsprimaryserver|findstr /r /i "mac"
wmic nicconfig get macaddress,dhcpserver,description,dnsserversearchorder,defaultipgateway,winsprimaryserver|find "{"
echo ** Dir. IP externa **
curl https://ipinfo.io/json
echo.
echo ** Su zona horaria local **
w32tm /tz

:paso4
echo --- S�. Si hay red %USERNAME%. ---
goto fin

:nRed
if %silencioso% == 1 goto paso5
netsh interface show interface

:paso5
echo No, no hay red.
echo No hay conexi�n hacia el exterior.
goto fin

:nRed2
if %silencioso% == 1 goto paso6
netsh interface show interface

:paso6
echo No, no hay red.
echo La tarjeta de red est� desconectada.

:fin
set silencioso=
set idioma=
set txtAyuda=
chcp 850 > nul
pause
