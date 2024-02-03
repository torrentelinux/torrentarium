// caso-1.cpp
// octulio biletán * 02/2024
// ejemplo de REST con CURL para Oracle Linux (i sorry Windows).
// muestra en pantalla la dir. IP externa de tu conexión a internet.
// entorno: Oracle Developer Studio v12.6
// compilar: g++ -s -v -lcurl -o <ejecutable> <fuente c++>
// ayuda: man 3 curl_global_init
// licencia: Software Libre.

#include <iostream>
#include <curl/curl.h>

using namespace std;

// Función de callback para recibir los datos de la respuesta
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response)
{
    size_t totalSize = size * nmemb;
    response->append((char*)contents, totalSize);
    return totalSize;
}

int main()
{
    // Inicializar cURL
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Crear un objeto cURL
    CURL* curl = curl_easy_init();
    if (curl)
    {
        // Establecer la URL de la API REST para obtener los datos
        // <poner aquí su consulta a internet/intranet>
        string url = "https://ipinfo.io/json";

        // Establecer la opción URL
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Crear una variable para almacenar la respuesta
        string response;

        // Establecer la función de callback para recibir los datos de la respuesta
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Realizar la solicitud
        CURLcode res = curl_easy_perform(curl);
        if(res == CURLE_OK)
        {
            // La solicitud se realizó correctamente, visualizar la respuesta
            cout << "<<Respuesta>>" << endl << response << endl;
        }
        else
        {
            // Error al realizar la solicitud
            cout << "<<Error al realizar la solicitud>> " << curl_easy_strerror(res) << endl;
        }

        // Liberar el objeto cURL
        curl_easy_cleanup(curl);
    }

    // Finalizar cURL
    curl_global_cleanup();

    return 0;
}
