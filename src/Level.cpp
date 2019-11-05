#include "Level.h"


Level::Level() :
	view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(static_cast<float>(WINDOW_WIDHT), static_cast<float>(WINDOW_HEIGHT)))

{
    BackMove = true;
    Notpause = true;
}


Level::~Level()
{
}

void Level::ResizeView()
{
	float aspectRatio = float(window->getSize().x) / float(window->getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

void Level::InitializePlatforms()
{
	Platforms.includePlatform(sf::Vector2f(1500.0f, VIEW_HEIGHT), sf::Vector2f(3000.0f, 100.0f), "Textures/Backgrounds.png");
	Platforms.includePlatform(sf::Vector2f(1000.0f, VIEW_HEIGHT / 2.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Backgrounds.png");
}

void Level::Initialize()
{
	InitializePlatforms();
	Notpause = true;
}

void Level::includePlayer(Player * player)
{
	Players.include(player);

	if (FirstPlayer)
	{
		player1 = player;
	}
	else
	{
		player2 = player;
		P2 = true;
	}

	FirstPlayer = false;
}

void Level::includePlatform(sf::Vector2f position, sf::Vector2f size, const char* file)
{
	Platforms.includePlatform(position, size, file);
}

void Level::checkCollisions()
{
	sf::Vector2f direction;

    ListT<Obstacle*>::Element<Obstacle*>* pAux4 = Obstacles.getFirst();
	while(pAux4 != NULL)
    {
        ObstaclesFixos.CheckCollisionObstacle(pAux4->getInf(), 1.0f);
        Obstacles.CheckCollisionObstacle(pAux4->getInf(), 0.0f);
        Platforms.CheckCollisionObstacle(pAux4->getInf(), 1.0f);
        pAux4 = pAux4->getNext();
    }

     ListT<Obstacle*>::Element<Obstacle*>* pAux5 = ObstaclesFixos.getFirst();
    while(pAux5 != NULL)
    {
        Platforms.CheckCollisionObstacle(pAux5->getInf(), 1.0f);
        pAux5 = pAux5->getNext();
    }

	//Collisions between the players and the players
	ListT<Player*>::Element<Player*>* pAux3 = Players.getFirst();
	while (pAux3 != NULL)
	{
		Obstacles.CheckCollision(pAux3->getInf(), 0.0f);
		Players.checkCollision(pAux3->getInf(),	-5.f);
		ObstaclesFixos.CheckCollision(pAux3->getInf(), 1.0f);
		pAux3 = pAux3->getNext();
	}

	//Collisions between the enemies and the players
	ListT<Player*>::Element<Player*>* pAux2 = Players.getFirst();
	while (pAux2 != NULL)
	{
		Enemies.checkCollision(pAux2->getInf(), 1.0f);
		Obstacles.CheckCollision(pAux2->getInf(), 1.0f);
		pAux2 = pAux2->getNext();
	}

	//Collisions between the enemies and the enemies
	ListT<Enemy*>::Element<Enemy*>* pAux6 = Enemies.getFirst();
	while (pAux6 != NULL)
	{
		Enemies.checkCollisionEnemy(pAux6->getInf(), 1.0f);
		pAux6 = pAux6->getNext();
	}

	//Collisions between the players and the platforms
	ListT<Player*>::Element<Player*>* pAux0 = Players.getFirst();
	while (pAux0 != NULL)
	{
		Platforms.CheckCollision(pAux0->getInf(), 1.f);
		pAux0 = pAux0->getNext();
	}

	//Collisions between the enemies and the platforms
	ListT<Enemy*>::Element<Enemy*>* pAux1 = Enemies.getFirst();
	while (pAux1 != NULL)
	{
		Platforms.CheckCollision(pAux1->getInf(), 1.f);
		pAux1 = pAux1->getNext();
	}

}


int Level::Execute()
{
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDHT, WINDOW_HEIGHT), "GAME", sf::Style::Default);

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window->isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 60.0f)
			deltaTime = 1.0f / 60.0f;

		sf::Event evnt;

		while (window->pollEvent(evnt))
		{

			switch (evnt.type)
			{
			case sf::Event::Closed:
				//Closes window
				window->close();
				return 0;
				break;

			case sf::Event::Resized:
				//Resize window and view
				ResizeView();
				break;

			default:
				break;
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			Notpause = false;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			Notpause = true;
		}

        if(Notpause == true)
        {
            //Update
            Players.update(deltaTime);
            Obstacles.Update(deltaTime);
            ObstaclesFixos.Update(deltaTime);
            back.Update(deltaTime);
            if (!P2)
                Enemies.update(deltaTime, player1->getPosition());
            else
                Enemies.update(deltaTime, player1->getPosition(), player2->getPosition());
        }



		if (!player1->Dead())
		{
			if (player1->getPosition().x >= ((WINDOW_WIDHT / 2.0f) - (WINDOW_WIDHT * PLAYERXPOSSCALE)))
			{
				if (P2)
				{
					if (player2->getPosition().x >= WINDOW_WIDHT / 2.f + (WINDOW_WIDHT * PLAYERXPOSSCALE) + player1->getPosition().x)
						player2->setPositionx(player1->getPosition().x + WINDOW_WIDHT / 2.f + (WINDOW_WIDHT * PLAYERXPOSSCALE));
					if (player2->getPosition().x <= -(WINDOW_WIDHT / 2.f) + (WINDOW_WIDHT * PLAYERXPOSSCALE) + player1->getPosition().x)
						player2->setPositionx(player1->getPosition().x + (WINDOW_WIDHT * PLAYERXPOSSCALE) - (WINDOW_WIDHT / 2.f));
				}
			}

			else
			{
				if (P2)
				{
					if (player2->getPosition().x >= WINDOW_WIDHT)
						player2->setPositionx(float(WINDOW_WIDHT));
				}
			}
			if (player1->getPosition().x <= 0.f)
				player1->setPositionx(0.f);
		}
		if (P2)
		{
			if (!player2->Dead())
				if (player2->getPosition().x <= 0.f)
					player2->setPositionx(0.f);

		}

		if ((!P2 && player1->Dead()) || (P2 && player1->Dead() && player2->Dead()))
		{
			window->close();
			return 1;
			break;
		}


		//Move the view and the background according to the players
		if (!player1->Dead())
		{
			if (player1->getPosition().x >= ((WINDOW_WIDHT / 2.0f) - (WINDOW_WIDHT * PLAYERXPOSSCALE)))
			{
				view.setCenter(player1->getPosition().x + (WINDOW_WIDHT * PLAYERXPOSSCALE), (WINDOW_HEIGHT / 2.0f));
                if(BackMove)
				Backgrounds.move(sf::Vector2f(player1->getPosition().x + (WINDOW_WIDHT * PLAYERXPOSSCALE) - (WINDOW_WIDHT / 2.0f), 0.0f), player1->getSpeed());
			}
			else
			{
				view.setCenter(WINDOW_WIDHT / 2.0f, WINDOW_HEIGHT / 2.0f);
			}
		}
		else
		{
				view.setCenter(player2->getPosition().x + (WINDOW_WIDHT * PLAYERXPOSSCALE), (WINDOW_HEIGHT / 2.0f));
				if(BackMove)
				Backgrounds.move(sf::Vector2f(player2->getPosition().x + (WINDOW_WIDHT * PLAYERXPOSSCALE) - (WINDOW_WIDHT / 2.0f), 0.0f), player2->getSpeed());
		}

		if(player1->getPosition().x >= LevelEnd)
        {
            BackMove = false;
            view.setCenter(6200.0f, (WINDOW_HEIGHT / 2.0f));
            Platforms.includePlatform(sf::Vector2f( LevelEnd, 0.0f ), sf::Vector2f(1.0f, 1500.0f),  NULL);
        }


        if(boss == false)
        {

            if(player1->getPosition().x >= LevelEnd + 1200.0f)
            {

                window->close();
                return 2;
            }
        }
        else
        {
            if(pBoss->Dead())
            {
                if(player1->getPosition().x >= LevelEnd + 600.0f)
                {
                    window->close();
                    return 3;
                }
            }
        }



       /** if(player1->Dead())
        {
            window->close();
            return 1;
        }**/


		//Check Collisions
		checkCollisions();

		//Clear the window and set the view
		window->clear(sf::Color(171, 106, 140));
		window->setView(view);

		//Draw
		Backgrounds.Draw(window);
		Platforms.Draw(window);
		Players.draw(window);
		Enemies.draw(window);
		Obstacles.Draw(window);
		ObstaclesFixos.Draw(window);

		window->display();

	}
}
