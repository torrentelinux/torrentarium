/*
 * File:   main.cpp
 * Author: octulio biletán
 * IDE: Oracle Developer Studio - Linux
 * Created on 19 de septiembre de 2023, 17:51
 */

#include <iostream>
using namespace std;

int dedo(int c = 0)
{
    return c++,c;  // o también "return ++c;"
}

int mano(int m = 0)
{
    return ++m; 
}

int main(void)
{
    cout << "Humano: ¿Cuántos dedos tienes en las dos manos?" << endl;

    int dedos = dedo(dedo(dedo())) * mano(mano());

    cout << "Máquina: Tengo " << dedos << " dedos." << endl;

    return 0;
}
