#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <chrono>                  // for operator""s, chrono_literals
#include <ftxui/dom/elements.hpp>  // for Element, operator|, separator, filler, hbox, size, spinner, text, vbox, bold, border, Fit, EQUAL, WIDTH
#include <ftxui/screen/screen.hpp>  // for Full, Screen
#include <iostream>                 // for cout, endl, ostream
#include <string>                   // for to_string, operator<<, string
#include <thread>                   // for sleep_for
#include <utility>                  // for move
#include <vector>                   // for vector

using namespace ftxui;
#include "ftxui/dom/node.hpp"      // for Render
#include "ftxui/screen/color.hpp"  // for ftxui

int main() {
  using namespace ftxui;
  using namespace std::chrono_literals;

    // Crea los elementos de la interfaz de usuario.
    Element label = text("Hola, mundo!");
    Element container = hbox({label});

    // Crea la pantalla y establece el contenido.
    auto screen = Screen::Create(
        Dimension::Full(), 
        Dimension::Fit(container)
    );

    Render(screen,container);
  std::string reset_position;
  for (int index = 0; index < 200; ++index) {
    std::vector<Element> entries;
    for (int i = 0; i < 23; ++i) {
      if (i != 0)
        entries.push_back(separator());
      entries.push_back(  //
          hbox({
              text(std::to_string(i)) | size(WIDTH, EQUAL, 2),
              separator(),
              spinner(i, index) | bold,
          }));
    }
    auto document = hbox({
        vbox(std::move(entries)) | border,
        filler(),
    });
    auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
    Render(screen, document);
    std::cout << reset_position;
    screen.Print();
    reset_position = screen.ResetPosition();

    return 0;
    std::this_thread::sleep_for(0.1s);
  }
  std::cout << std::endl;
}