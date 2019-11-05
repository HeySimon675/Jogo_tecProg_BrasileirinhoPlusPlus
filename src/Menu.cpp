#include "Menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

int Menu::execute()
{

	window = new sf::RenderWindow(sf::VideoMode((unsigned int) (WINDOW_WIDHT), (unsigned int) (WINDOW_HEIGHT)), "GAME", sf::Style::Default);


	while (window->isOpen())
	{

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
				//ResizeView();
				break;

			default:
				break;
			}
		}

		if (!menuTexture.loadFromFile(MENU_TEXT))
			std::cout << "ERROR" << std::endl;
		menuSprite.setTexture(menuTexture);

		menuSprite.setPosition(0.0f, 0.0f);

		if (!novoJogo.loadFromFile(NOVO_JOGO))
			std::cout << "ERROR" << std::endl;
		novoJogoSprite.setTexture(novoJogo);

		novoJogoSprite.setPosition(0.0f, 600.0f);

		/**if (!novoJogo.loadFromFile(NOVO_JOGO))
			std::cout << "ERROR" << std::endl;
		novoJogoSprite.setTexture(novoJogo);

		novoJogoSprite.setPosition(50.0f, 600.0f);**/


		if (!carregarJogo.loadFromFile(CARREGAR_JOGO))
			std::cout << "ERROR" << std::endl;
		carregarJogoSprite.setTexture(carregarJogo);

		carregarJogoSprite.setPosition(350.0f, 600.0f);

		if (!faseDois.loadFromFile(FASE_DOIS))
			std::cout << "ERROR" << std::endl;
		faseDoisSprite.setTexture(faseDois);

		faseDoisSprite.setPosition(700.0f, 600.0f);

		if (!rankingText.loadFromFile(RANKING))
			std::cout << "ERROR" << std::endl;
		rankingSprite.setTexture(rankingText);

		rankingSprite.setPosition(1050.0f, 600.0f);

		sf::FloatRect novo = novoJogoSprite.getGlobalBounds();
		sf::FloatRect fase = faseDoisSprite.getGlobalBounds();
		sf::FloatRect load = carregarJogoSprite.getGlobalBounds();
		sf::FloatRect ranking = rankingSprite.getGlobalBounds();

		int mouseX = sf::Mouse::getPosition(*window).x;
		int mouseY = sf::Mouse::getPosition(*window).y;

		float novoJogoX = novoJogoSprite.getPosition().x;
		float novoJogoY = novoJogoSprite.getPosition().y;

		float fase2X = faseDoisSprite.getPosition().x;
		float fase2Y = faseDoisSprite.getPosition().y;

		float loadX = carregarJogoSprite.getPosition().x;
		float loadY = carregarJogoSprite.getPosition().y;

		float rankingX = rankingSprite.getPosition().x;
		float rankinY = rankingSprite.getPosition().y;

		if (mouseX >= novoJogoX && mouseX <= novoJogoX + novo.width
			&& mouseY >= novoJogoY && mouseY <= novoJogoY + novo.height)
		{
			novoJogo.loadFromFile(NOVO_JOGO_RED);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				//novoJogoSprite.setColor(sf::Color::Transparent);
				//faseDoisSprite.setColor(sf::Color::Transparent);
				//carregarJogoSprite.setColor(sf::Color::Transparent);
				//rankingSprite.setColor(sf::Color::Transparent);

				if (!umJogador.loadFromFile(UM_PLAYER))
					std::cout << "ERROR" << std::endl;
				umJogadorSprite.setTexture(umJogador);
				umJogadorSprite.setPosition(100.0f, 50.0f);

				if (!doisJogadores.loadFromFile(DOIS_PLAYERS))
					std::cout << "ERROR" << std::endl;
				doisJogadoresSprite.setTexture(doisJogadores);
				doisJogadoresSprite.setPosition(800.0f, 50.0f);

				if (!ScottT.loadFromFile(SCOTT))
					std::cout << "ERROR" << std::endl;
				ScottS.setTexture(ScottT);

				if (!RamonaT.loadFromFile(RAMONA))
					std::cout << "ERROR" << std::endl;
				RamonaS.setTexture(RamonaT);

				ScottS.setPosition(120.0f, 230.0f);
				RamonaS.setPosition(810.0f, 177.0f);
                fase1 = true;
                //transparent = false;
                if(transparent == true)
                {
                    umJogadorSprite.setColor(sf::Color::White);
                    doisJogadoresSprite.setColor(sf::Color::White);
                    RamonaS.setColor(sf::Color::White);
                    ScottS.setColor(sf::Color::White);
                }
			}
		}

		if (mouseX >= fase2X && mouseX <= fase2X + fase.width
			&& mouseY >= fase2Y && mouseY <= fase2Y + fase.height)
		{
			faseDois.loadFromFile(FASE_DOIS_RED);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                //novoJogoSprite.setColor(sf::Color::Transparent);
				//faseDoisSprite.setColor(sf::Color::Transparent);
				//carregarJogoSprite.setColor(sf::Color::Transparent);
				//rankingSprite.setColor(sf::Color::Transparent);

				if (!umJogador.loadFromFile(UM_PLAYER))
					std::cout << "ERROR" << std::endl;
				umJogadorSprite.setTexture(umJogador);
				umJogadorSprite.setPosition(100.0f, 50.0f);

				if (!doisJogadores.loadFromFile(DOIS_PLAYERS))
					std::cout << "ERROR" << std::endl;
				doisJogadoresSprite.setTexture(doisJogadores);
				doisJogadoresSprite.setPosition(800.0f, 50.0f);

				if (!ScottT.loadFromFile(SCOTT))
					std::cout << "ERROR" << std::endl;
				ScottS.setTexture(ScottT);

				if (!RamonaT.loadFromFile(RAMONA))
					std::cout << "ERROR" << std::endl;
				RamonaS.setTexture(RamonaT);

				ScottS.setPosition(120.0f, 230.0f);
				RamonaS.setPosition(810.0f, 177.0f);
				//transparent = false;
				fase1 = false;

				if(transparent == true)
                {
                    umJogadorSprite.setColor(sf::Color::White);
                    doisJogadoresSprite.setColor(sf::Color::White);
                    RamonaS.setColor(sf::Color::White);
                    ScottS.setColor(sf::Color::White);
                }
            }
		}

		sf::FloatRect pUm = umJogadorSprite.getGlobalBounds();
		sf::FloatRect pDois = doisJogadoresSprite.getGlobalBounds();

		float Player1X = umJogadorSprite.getPosition().x;
		float Player1Y = umJogadorSprite.getPosition().y;

		float Player2X = doisJogadoresSprite.getPosition().x;
		float Player2Y = doisJogadoresSprite.getPosition().y;

		if(fase1)
        {
                if (mouseX >= Player1X && mouseX <= Player1X + pUm.width
                && mouseY >= Player1Y && mouseY <= Player1Y + pUm.height)
                {
                umJogador.loadFromFile(UM_PLAYER_RED);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    window->close();
                    umJogadorSprite.setColor(sf::Color::Transparent);
                    doisJogadoresSprite.setColor(sf::Color::Transparent);
                    RamonaS.setColor(sf::Color::Transparent);
                    ScottS.setColor(sf::Color::Transparent);
                    transparent = true;
                    return 1;
                }
            }
            else
            {
                umJogador.loadFromFile(UM_PLAYER);
            }

            if (mouseX >= Player2X && mouseX <= Player2X + pDois.width
                && mouseY >= Player2Y && mouseY <= Player2Y + pDois.height)
            {
                doisJogadores.loadFromFile(DOIS_PLAYERS_RED);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    window->close();
                    umJogadorSprite.setColor(sf::Color::Transparent);
                    doisJogadoresSprite.setColor(sf::Color::Transparent);
                    RamonaS.setColor(sf::Color::Transparent);
                    ScottS.setColor(sf::Color::Transparent);
                    transparent = true;
                    return 2;

                }
            }
            else
            {
                doisJogadores.loadFromFile(DOIS_PLAYERS);
            }
        }

        if(!fase1)
        {
                if (mouseX >= Player1X && mouseX <= Player1X + pUm.width
                && mouseY >= Player1Y && mouseY <= Player1Y + pUm.height )
            {
                umJogador.loadFromFile(UM_PLAYER_RED);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    window->close();
                    umJogadorSprite.setColor(sf::Color::Transparent);
                    doisJogadoresSprite.setColor(sf::Color::Transparent);
                    RamonaS.setColor(sf::Color::Transparent);
                    ScottS.setColor(sf::Color::Transparent);
                    transparent = true;
                    return 3;

                }
            }
            else
            {
                umJogador.loadFromFile(UM_PLAYER);
            }

            if (mouseX >= Player2X && mouseX <= Player2X + pDois.width
                && mouseY >= Player2Y && mouseY <= Player2Y + pDois.height)
            {
                doisJogadores.loadFromFile(DOIS_PLAYERS_RED);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    window->close();
                    umJogadorSprite.setColor(sf::Color::Transparent);
                    doisJogadoresSprite.setColor(sf::Color::Transparent);
                    RamonaS.setColor(sf::Color::Transparent);
                    ScottS.setColor(sf::Color::Transparent);
                    transparent = true;
                    return 4;
                }
            }
            else
            {
                doisJogadores.loadFromFile(DOIS_PLAYERS);
            }
        }


		if (mouseX >= loadX && mouseX <= loadX + load.width
			&& mouseY >= loadY && mouseY <= loadY + load.height)
		{
			carregarJogo.loadFromFile(CARREGAR_JOGO_RED);
		}

		if (mouseX >= rankingX && mouseX <= rankingX + ranking.width
			&& mouseY >= rankinY && mouseY <= rankinY + ranking.height)
		{
			rankingText.loadFromFile(RANKING_RED);
		}

		window->clear();
		window->draw(menuSprite);
		window->draw(novoJogoSprite);
		window->draw(carregarJogoSprite);
		window->draw(faseDoisSprite);
		window->draw(rankingSprite);
		window->draw(umJogadorSprite);
		window->draw(doisJogadoresSprite);
		window->draw(ScottS);
		window->draw(RamonaS);
		window->display();
	}
}

int Menu::executeOp1()
{
    window = new sf::RenderWindow(sf::VideoMode((unsigned int) (WINDOW_WIDHT), (unsigned int) (WINDOW_HEIGHT)), "MENU", sf::Style::Default);

    std::cout<<"OPKDAOPSAPK"<<std::endl;
    while(window->isOpen())
    {

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
				//ResizeView();
				break;

			default:
				break;
			}
		}

            std::cout<<"OPKDAOPSAPK"<<std::endl;

            if (!LoseText.loadFromFile(LOSE))
                std::cout << "ERROR" << std::endl;
            LoseSprite.setTexture(LoseText);

            LoseSprite.setPosition(0.0f, 0.0f);

            int mouseX = sf::Mouse::getPosition(*window).x;
            int mouseY = sf::Mouse::getPosition(*window).y;


            if (!IrAoMenuText.loadFromFile(IR_AO_MENU))
                std::cout << "ERROR" << std::endl;
            IrAoMenuSprite.setTexture(IrAoMenuText);

            IrAoMenuSprite.setPosition(357.0f, 600.0f);

            sf::FloatRect menu = IrAoMenuSprite.getGlobalBounds();

            float MenuX = IrAoMenuSprite.getPosition().x;
            float MenuY = IrAoMenuSprite.getPosition().y;

            if (mouseX >= MenuX && mouseX <= MenuX + menu.width
                && mouseY >= MenuY && mouseY <= MenuY + menu.height)
            {
                IrAoMenuText.loadFromFile(IR_AO_MENU_RED);
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    window->close();
                    return 1;
                }
            }
            else
            {
                IrAoMenuText.loadFromFile(IR_AO_MENU);
            }

		window->clear();
		window->draw(LoseSprite);
		window->draw(IrAoMenuSprite);
		window->display();

    }
}

int Menu::executeOp2()
{
     window = new sf::RenderWindow(sf::VideoMode((unsigned int) (WINDOW_WIDHT), (unsigned int) (WINDOW_HEIGHT)), "MENU", sf::Style::Default);

    while(window->isOpen())
    {

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
				//ResizeView();
				break;

			default:
				break;
			}
		}

        if (!victoryText.loadFromFile(VICTORY))
                std::cout << "ERROR" << std::endl;
            victorySprite.setTexture(victoryText);

            victorySprite.setPosition(0.0f, 0.0f);

            int mouseX = sf::Mouse::getPosition(*window).x;
            int mouseY = sf::Mouse::getPosition(*window).y;


            if (!IrAoMenuText.loadFromFile(IR_AO_MENU))
                std::cout << "ERROR" << std::endl;
            IrAoMenuSprite.setTexture(IrAoMenuText);

            IrAoMenuSprite.setPosition(450.0f, 600.0f);

            if (!IrParaFase2Text.loadFromFile(IR_PARA_FASE))
                std::cout << "ERROR" << std::endl;
            IrParaFase2Sprite.setTexture(IrParaFase2Text);

           IrParaFase2Sprite.setPosition(800.0f, 600.0f);

            sf::FloatRect fase = IrParaFase2Sprite.getGlobalBounds();

            float FaseX = IrParaFase2Sprite.getPosition().x;
            float FaseY = IrParaFase2Sprite.getPosition().y;


            sf::FloatRect menu = IrAoMenuSprite.getGlobalBounds();

            float MenuX = IrAoMenuSprite.getPosition().x;
            float MenuY = IrAoMenuSprite.getPosition().y;

            if (mouseX >= MenuX && mouseX <= MenuX + menu.width
                && mouseY >= MenuY && mouseY <= MenuY + menu.height)
            {
                IrAoMenuText.loadFromFile(IR_AO_MENU_RED);
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    window->close();
                    return 1;
                }
            }
            else
            {
               IrAoMenuText.loadFromFile(IR_AO_MENU);
            }

            if (mouseX >= FaseX && mouseX <= FaseX + fase.width
                && mouseY >= FaseY && mouseY <= FaseY + fase.height)
            {
               IrParaFase2Text.loadFromFile(IR_PARA_FASE_RED);
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    window->close();
                    return 2;
                }
            }
            else
            {
                IrParaFase2Text.loadFromFile(IR_PARA_FASE);
            }

        window->clear();
		window->draw(victorySprite);
		window->draw(IrAoMenuSprite);
		window->draw(IrParaFase2Sprite);
		window->display();
    }

}

int Menu::executeOp3()
{
     window = new sf::RenderWindow(sf::VideoMode((unsigned int) (WINDOW_WIDHT), (unsigned int) (WINDOW_HEIGHT)), "MENU", sf::Style::Default);

    while(window->isOpen())
    {
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
				//ResizeView();
				break;

			default:
				break;
			}
		}

        if (!victoryText.loadFromFile(VICTORY))
                std::cout << "ERROR" << std::endl;
            victorySprite.setTexture(victoryText);

            victorySprite.setPosition(0.0f, 0.0f);

            int mouseX = sf::Mouse::getPosition(*window).x;
            int mouseY = sf::Mouse::getPosition(*window).y;


            if (!IrAoMenuText.loadFromFile(IR_AO_MENU))
                std::cout << "ERROR" << std::endl;
            IrAoMenuSprite.setTexture(IrAoMenuText);

            IrAoMenuSprite.setPosition(450.0f, 600.0f);

            sf::FloatRect menu = IrAoMenuSprite.getGlobalBounds();

            float MenuX = IrAoMenuSprite.getPosition().x;
            float MenuY = IrAoMenuSprite.getPosition().y;

            if (mouseX >= MenuX && mouseX <= MenuX + menu.width
                && mouseY >= MenuY && mouseY <= MenuY + menu.height)
            {
                IrAoMenuText.loadFromFile(IR_AO_MENU_RED);
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    window->close();
                    return 1;
                }
            }
            else
            {
                IrAoMenuText.loadFromFile(IR_AO_MENU);
            }

        window->clear();
		window->draw(victorySprite);
		window->draw(IrAoMenuSprite);
		window->display();
    }
}
