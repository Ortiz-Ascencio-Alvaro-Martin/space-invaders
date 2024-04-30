#include <iostream>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <thread>

using namespace ftxui;
using namespace std;

int main(int argc, char const *argv[])
{

 
 
auto Pantalla = Screen::Create(Dimension::Full(),Dimension::Full());
  
   while(true)
   {
   this_thread::sleep_for(0.1s);
    
    Pantalla.Print();
    Pantalla.Clear();
    cout<<Pantalla.ResetPosition();
        
   
   }
   


    return 0;
}

