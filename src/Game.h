
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
  sf::Text score;

  bool in_menu = false;
  bool play_selected = false;
  int speed = 500;
  int score = 0;
  bool reverse = false;
  bool collisionCheck(sf::Vector2i click, sf::Sprite sprite);
  void spawn();



 
};

#endif // PLATFORMER_GAME_H
