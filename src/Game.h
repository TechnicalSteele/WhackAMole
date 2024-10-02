
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void text();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);

 private:
  sf::RenderWindow& window;
  sf::Sprite bird;
  sf::Sprite background;
  sf::Texture background_texture;
  sf::Texture bird_texture;
  sf::Font font;
  sf::Text title_text;
  sf::Text play_option;
  sf::Text exit_option;

  bool in_menu = false;


 
};

#endif // PLATFORMER_GAME_H
