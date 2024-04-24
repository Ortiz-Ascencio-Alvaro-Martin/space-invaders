#include <iostream>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <thread>
using namespace ftxui;
using namespace std;

int main(int argc, char const *argv[])
{

   int pix = 0;
   int piy = 0;
   string prueba = ".|.";
   while(true)
   {
    pix++;
    auto Pantalla = Screen::Create(Dimension::Fixed(20),Dimension::Fixed(10));
   Render(Pantalla,border(text("Hola")));
   Pantalla.PixelAt(5,5).character = "a";
   
   string prueba = "Hola Mundo";
  
   for (auto&&letra : prueba)
   {
    Pantalla.PixelAt(px,py).character = letra;
    px++;
    Pantalla.Print();
    cout<<Pantalla.ResetPosition();

   //  this_thread::sleep_for(0.1s);
   }
   }
   


    return 0;
}

