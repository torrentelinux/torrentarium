@echo off
REM Eugenio Martínez - https://t.me/octulioBiletan - Junio de 2024-
REM Versión 3.0 de miip.cmd para Windows.
REM Muestra la dir. IP local (v4 y v6) y externa de su PC conectada a internet.
REM Es necesario instalar curl.exe
REM -----------------------------------------------------------------
REM AVISO:
REM Instale curl.exe en su sistema.
title Usuario y dir. IP activa local y externa
mode con cols=84 lines=36
echo [Usuario activo]
echo %USERNAME%
whoami /user
echo.
echo [Config. IP - Local]
ipconfig /all|find /i "ipv4"
ipconfig /all|find /i "ipv6"
echo.
echo [Config. IP - Externa]
curl -s https://ipinfo.io/json

REM Opcional: usar pause
timeout /t 7 /nobreak
