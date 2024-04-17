#include <iostream>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <string>

 using namespace std;
 using namespace ftxui;


int main(int argc, char const *argv[])
{
 Element lienzo = hbox ({
   
    spinner(21,3) | bold

 });

Screen pantalla = Screen::Create(
  
    Dimension::Full(),
    Dimension::Fit(lienzo)
    
);

Render(pantalla,lienzo);
pantalla.Print();
pantalla.ResetPosition();

return 0;



}