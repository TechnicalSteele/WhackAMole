
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
	: window(game_window)
{
	srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
	text();
	in_menu = true;

	if (!background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png"))
	{
		std::cout << "background texture did not load\n";
	}
	background.setTexture(background_texture);

	if (!bird_texture.loadFromFile("../Data/WhackaMole Worksheet/bird.png"))
	{
		std::cout << "bird not loading for you whomp whomp\n";

	}
	bird.setTexture(bird_texture);
	bird.setPosition(100, 100);
	bird.setScale(0.5, 0.5);
	if (!font.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "font didnt load! \n";
	}
	
	return true;
}

void Game::text()
{
	title_text.setString("Whack-A-Mole");
	title_text.setFont(font);
	title_text.setCharacterSize(100);
	title_text.setFillColor(sf::Color(0, 0, 0, 255));
	title_text.setPosition(
		window.getSize().x / 4 - title_text.getGlobalBounds().width / 2,
		window.getSize().y / 4 - title_text.getGlobalBounds().height / 2);


	play_option.setString("Play");
	play_option.setFont(font);
	play_option.setCharacterSize(50);
	play_option.setFillColor(sf::Color(255, 255, 255, 255));
	play_option.setPosition(
		window.getSize().x / 4 - play_option.getGlobalBounds().width / 4,
		window.getSize().y / 4 - play_option.getGlobalBounds().height / 4);

	exit_option.setString("Quit");
	exit_option.setFont(font);
	exit_option.setCharacterSize(50);
	exit_option.setFillColor(sf::Color(255, 255, 255, 255));
	exit_option.setPosition(
		window.getSize().x / 2 - exit_option.getGlobalBounds().width / 2,
		window.getSize().y / 4 - exit_option.getGlobalBounds().height / 4);

	score_text.setString(":" + int(score));
	score_text.setFont(font);
	score_text.setCharacterSize(50);
	score_text.setFillColor(sf::Color(0, 0, 0, 255));
	score_text.setPosition(
		window.getSize().x / 6 - score_text.getGlobalBounds().width / 6,
		window.getSize().y / 6 - score_text.getGlobalBounds().height / 6);
}



void Game::update(float dt)
{
	
	if ((bird.getPosition().x > (window.getSize().x - bird.getGlobalBounds().width)) ||
		(bird.getPosition().x < 0))
	{
		reverse = !reverse;
	}
	if (reverse)
	{
		bird.move(-1.0f * speed * dt, 0);
		
		bird.setTextureRect(sf::IntRect(
			bird.getLocalBounds().width,
			0,
			-bird.getLocalBounds().width,
			bird.getLocalBounds().height));
	}
	else
	{
		bird.move(1.0f * speed * dt, 0);
		
		bird.setTextureRect(sf::IntRect(
			0, 0, bird.getLocalBounds().width, bird.getLocalBounds().height));

	}
}

void Game::render()
{
	if (in_menu)
	{
		window.draw(play_option);
		window.draw(exit_option);
	}
	else
	{
		window.draw(background);
		window.draw(bird);
		window.draw(title_text);
		window.draw(score_text);
	}
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
  if (collisionCheck(click, bird))
  {
	  spawn();
	  
  }

}

bool Game::collisionCheck(sf::Vector2i click, sf::Sprite sprite)
{
	bird.getPosition();

//sprite_left = 
//sprite_right = 
//sprite_top = 
//sprite_bottom =

	if (click.x < bird.getPosition().x + bird.getGlobalBounds().width &&
		click.x < bird.getPosition().y + bird.getGlobalBounds().height &&
		click.y < bird.getPosition().y + bird.getGlobalBounds().height)
		
	{
		return true;
	}
		
	return false;
}

void Game::keyPressed(sf::Event event)
{
	if ((event.key.code == sf::Keyboard::Left ||
		event.key.code == sf::Keyboard::Right))
	{
		play_selected = !play_selected;
		if (play_selected)
		{
			play_option.setString("> Play <");
			exit_option.setString("Quit");
		}
		else
		{
			play_option.setString("Play");
			exit_option.setString("> Quit <");
	}

	}
	else if (event.key.code == sf::Keyboard::Enter)
	{
		if (play_selected)
		{
			in_menu = false;
		}
		else
		{
			window.close();
		}
	}

}


void Game::keyReleased(sf::Event event)
{

}

void Game::spawn()
{
	float xpos = std::rand() % int(window.getSize().x - bird.getGlobalBounds().width);
	float ypos = std::rand() % int(window.getSize().y - bird.getGlobalBounds().height);
	bird.setPosition(xpos, ypos);
}
