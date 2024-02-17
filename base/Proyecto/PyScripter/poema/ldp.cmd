@echo off
cls
del salida 2> nul
python poema-visualizar.py 2> salida
if %ERRORLEVEL% geq 1 goto errores
goto salir

:errores
echo AVISO: Hubo un error en la aplicacion.
type salida

:salir
echo Presiona cualquier tecla para terminar _
pause
