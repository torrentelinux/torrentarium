@echo off
cls
del salida 2> nul
set poema=c:\base\Proyecto\PyScripter\PySide2
pushd %poema%
python poema-visualizar.py 2> salida
if %ERRORLEVEL% geq 1 goto errores
goto salir

:errores
echo AVISO: Hubo un error en la aplicacion.
type salida

:salir
popd
set poema=
echo Presiona cualquier tecla para terminar _
pause
