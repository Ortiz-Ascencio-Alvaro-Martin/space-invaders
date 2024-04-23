#include <iostream>
#include <string>
#include <thread>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include <ftxui/screen/terminal.hpp>
#include <fstream>

using namespace std;
using namespace ftxui;
class Dibujo
{
    private:
         fstream archivo;
         Element contenido;
    public:

         Dibujo(string path) 
   {
              archivo.open(path);
                 Elements lineas;
               while (!archivo.eof())
              {
              string linea;
             getline(archivo,linea);
             lineas.emplace_back(text(linea));
              }

    
              Element getelement()
              {
                return this -> contenido;
             }
    archivo.close();
     }   
    ~Dibujo() {}
};