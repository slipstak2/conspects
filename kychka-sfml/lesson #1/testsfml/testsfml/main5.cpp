#include <SFML/Graphics.hpp>
 
using namespace sf;
int main()
{
	RenderWindow window(sf::VideoMode(640, 480), "Lesson 5. kychka-pc.ru");
 
 
	
	Texture herotexture;
	herotexture.loadFromFile("images/hero.png");
 
	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0, 192, 96, 96));//получили нужный нам прямоугольник с котом
	herosprite.setPosition(250,250); //выводим спрайт в позицию x y 
 
	
 
	while (window.isOpen())
	{
		
 
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)			
			window.close();
		}
 
		if (Keyboard::isKeyPressed(Keyboard::Left)) { herosprite.move(-0.1, 0); } //первая координата Х отрицательна =>идём влево
		if (Keyboard::isKeyPressed(Keyboard::Right)) { herosprite.move(0.1, 0); } //первая координата Х положительна =>идём вправо
		if (Keyboard::isKeyPressed(Keyboard::Up)) { herosprite.move(0, -0.1); } //вторая координата (У) отрицательна =>идём вверх (вспоминаем из предыдущих уроков почему именно вверх, а не вниз)
		if (Keyboard::isKeyPressed(Keyboard::Down)) { herosprite.move(0, 0.1); } //вторая координата (У) положительна =>идём вниз (если не понятно почему именно вниз - смотрим предыдущие уроки)
 
		window.clear();
		window.draw(herosprite);
		window.display();
	}
 
	return 0;
}