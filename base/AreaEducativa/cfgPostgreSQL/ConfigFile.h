// ConfigFile.h
// Octulio Biletán * Mayo de 2023
// Modelo Educativo de aplicación para Windows.
// Lee ficheros .conf
// Delara la clase TConfigFile.


#include <vcl.h>

class TConfigFile
{
   private:
   	String fnombre_config;

    public:
    	TConfigFile();
        TConfigFile(String nm);
	String ReadString(const String value);
};
