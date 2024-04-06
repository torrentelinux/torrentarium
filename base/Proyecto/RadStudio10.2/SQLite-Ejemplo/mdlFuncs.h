//---------------------------------------------------------------------------
// Proyecto : SQLite_Ejemplo.cbproj
// Encabezamiento: mdlFuncs.h
// Autor    : Octulio Biletán * Marzo de 2024
// Propósito: Realizar una consulta a la base de datos 'ejemploSQLite.sdb'
//            Declaración de variables externas.
// Obs.     : El lenguaje de consulta utilizado es SQLite v3.
//---------------------------------------------------------------------------

// Códigos de errores para base de datos del tipo sqlite3.

// Código 0 - sin error
extern const int FBIEN;

// Código 2000 - el tamaño del archivo es cero
extern const int FTAMCERO;

// Código 2001 - la cabecera de la base de datos es incorrecta
extern const int FERRORCAB;

