#include <fstream>
#include <ftxui/dom/elements.hpp>
using namespace std;
using namespace ftxui;

class Archivo
{
private:
    fstream archivo;
    Element contenido;
public:
    Archivo(string path)
    {
        archivo.open(path);
        Elements lineas;
        while (!archivo.eof())
        {
            string linea;
            getline(archivo, linea);
            lineas.emplace_back(text(linea));
        }
        this->contenido = vbox(lineas);
        archivo.close();
    }
    Element GetElement(){
        return this->contenido;
    }
    ~Archivo() {}
};