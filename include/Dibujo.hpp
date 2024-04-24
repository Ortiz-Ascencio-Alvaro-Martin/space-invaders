
#include <fstream>
#include <ftxui/dom/elements.hpp>
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
            getline(archivo, linea);
            lineas.emplace_back(text(linea));
        }
        this->contenido = vbox(lineas);
        archivo.close();
    }
    Element GetElement(){
        return this->contenido;
    }
    ~Dibujo() {}
};