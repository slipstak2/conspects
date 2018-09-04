#include <SFML/Graphics.hpp>
 
using namespace sf;
int main()
{
	RenderWindow window(sf::VideoMode(640, 480), "Lesson 4. kychka-pc.ru"); 
 
	
 
	Texture herotexture;
	herotexture.loadFromFile("images/hero.png");
 
	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0,192,96,96));//получили нужный нам прямоугольник с котом
	herosprite.setPosition(50, 25);
 
	while (window.isOpen())	
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
 
		window.clear();
		window.draw(herosprite);
		window.display();
	}
 
	return 0;
}