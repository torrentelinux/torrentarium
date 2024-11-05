// Programa   : calculaNroPi.cpp
// Descripción: Cálculo del nº pi mediante la fórmula de Leibniz.
// Plataforma : Oracle Linux Server v7.9, g++ v4.8.5 20150623 (Red Hat 4.8.5-44.0.3).
// Compilación: g++ -std=c++11 -pthread -o calculaNroPi calculaNroPi.cpp
// Refs.: Contenido en Linkedin.com
//        https://www.linkedin.com/posts/naser-rezayi-89774723b_include-include-include-activity-7259580640692477954-KlbA?utm_source=combined_share_message&utm_medium=member_desktop_web
// Fecha: 5/Nov/2024

#include <iostream>
#include <iomanip>
#include <cmath>
#include <thread>
#include <future>

using namespace std;

double CalculatePi(int terms)
{
	double result = 0.0;
	
   if(terms < 1)
   {
       throw runtime_error("Terms cannot be less than 1.");
   }
   
   for(int i = 0; i < terms; i++)
   {
       int sign = pow(-1, i);
       double term = 1.0 / (i * 2 + 1);
       
       result += sign * term;
   }
   
   return result * 4;
}

int main()
{
   cout << "Cálculo del número PI" << endl;
   cout << "aguarde un momento..." << endl << endl;
   
   packaged_task<double(int)> task1(CalculatePi);
   future<double> future1 = task1.get_future();
   
   // Alternativa según compilador C++: std::thread t1(move(task1), 1'000'000'000);
   // invoca indirectamente a CalculatePi(1000000000)
   thread t1(move(task1), 1000000000);
   
   try
   {
       double result = future1.get();
       
       cout << "PI = ";
       cout << setprecision(15) << result << endl;
   }
   catch(exception &e)
   {
       cerr << "ERROR! " << e.what() << endl;
   }
   
   t1.join();
   
   cout << "Operación finalizada." << endl;
   return 0;
}
