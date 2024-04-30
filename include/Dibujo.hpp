#pragma once
#include <string>
#include <ftxui/screen/screen.hpp>
using namespace ftxui;
using namespace std;

class Dibujo
{
private:
    int px;
    int py;
    string palabra;
public:
    Dibujo(){
        this-> px=0;
        this-> py=0;
    } 
    Dibujo(int px, int py){
        this-> px=px;
        this-> py=py;
    }
    Dibujo(string palabra, int px, int py){
        this->palabra=palabra;
        this-> px=px;
        this-> py=py;
    }
    
    
    void Dibujar(ftxui::Screen &Pantalla){
     int ppx=0;
     int ppy=0;
  
  
   for (auto &&letra : palabra)
   {
    
    int pfx = this->px + ppx;
    int pfy = this->py + ppy;
    Pantalla.PixelAt(pfx,pfy).character = letra;
    px++;
   }



    }
    ~Dibujo();
};

