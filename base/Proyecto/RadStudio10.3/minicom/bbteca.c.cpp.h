// bbteca.c.cpp.h
// Biblioteca estándar de clases y funciones en C/C++ agrupadas en 'struct'
// Se utilizan tanto puntero a función como puntero a clase.
// Compatible con Embarcadero RAD Studio 10.2 y versiones posteriores.

#include <_stddef.h>
#include <cstdio>

struct _cstdio
{
    int (*printf)(const char *fmt, ...);
    int (*puts)(const char *txt);
    int (*putchar)(const int cc);

    int   (*scanf)(const char *fmt, ...);
    char* (*gets)(char * __s);

    void  (*perror)(const char *txt);
    char* (*strerror)(int nerr);

    int   (*fclose)(FILE * __stream);
    FILE* (*fopen)(const char * __path, const char * __mode);
    int   (*getc)(FILE * __fp);
    int   (*fgetc)(FILE * __stream);
    char* (*fgets)(char * __s, int __n, FILE * __stream);
    int   (*ungetc)(int __c, FILE * __stream);
    int   (*putc)(const int __c, FILE * __fp);
    int   (*fputc)(int __c, FILE * __stream);
    int   (*fputs)(const char * __s, FILE * __stream);
    int   (*fscanf)(FILE * __stream, const char * __format, ...);
    int   (*fprintf)(FILE * __stream, const char * __format, ...);
    _SIZE_T (*fread)(void * __ptr, _SIZE_T __size, _SIZE_T __n, FILE * __stream);
    _SIZE_T (*fwrite)(const void * __ptr, _SIZE_T __size, _SIZE_T __n, FILE * __stream);
    int  (*fseek)(FILE * __stream, long __offset, int __whence);
    int  (*_fseeki64)(FILE * __stream, __int64 __offset, int __whence);
    int  (*fsetpos)(FILE * __stream, const fpos_t*__pos);
    long (*ftell)(FILE * __stream);
    __int64 (*_ftelli64)(FILE * __stream);
    int  (*flushall)(void);
    int  (*fflush)(FILE * __stream);
    int  (*fileno)(FILE * __fp);
    int  (*fcloseall)(void);
    int  (*feof)(FILE * __fp);
    int  (*ferror)(FILE * __fp);
    void (*rewind)(FILE * __stream);
    void (*clearerr)(FILE * __stream);

    int (*sprintf)(char * __buffer, const char * __format, ...) __ATTRIB_FORMAT(printf, 2, 3);
    int (*sscanf)(const char * __buffer,  const char * __format, ...);

};

struct _conio
{
    int (*getch)(void);
};

struct _mem
{
   void* (*memset)(void *s, int c, size_t n);
};

struct _cstring
{
   int (*strcmp)(const char *txt1, const char *txt2);
};

struct _cstdlib
{
    void (*exit)(int e);
};

struct _process
{
    int (*spawnv)(int modo, const char *trayectoria, char * const *argv);
    int (*cwait)(int *_term_stat, int _pid, int _accion);
};

#include <iostream>

struct _iostream
{
    ostream *cerr;
    ostream *cout;
    istream *cin;
};

