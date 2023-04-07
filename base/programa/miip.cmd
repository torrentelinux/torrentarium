@echo off
REM Eugenio Martínez - https://t.me/octulioBiletan - Abril de 2023-
REM Versión 2.0 de miip.cmd para Windows.
REM Muestra la dir. IP local y externa de su PC conectada a internet.
REM Es necesario instalar curl.exe
REM -----------------------------------------------------------------
REM AVISO:
REM Instale curl.exe en su sistema.
title Usuario y dir. IP activa local y externa
mode con cols=78 lines=32
echo [Usuario activo]
echo %USERNAME%
whoami /user
echo.
echo [Config. IP - Local]
ipconfig /all|find /i "ipv4"
echo.
echo [Config. IP - Externa]
curl -s https://ipinfo.io/json

REM Opcional: usar pause
timeout /t 7 /nobreak
