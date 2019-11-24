#include "Menu.h"

Menu::Menu(): Entidade()
{
    menuPrincipal = true;
    menuPause = true;
    contador = 0;
    naoDuplica = 0;
    sair = false;
    ranking = false;
    novoJogo = false;
    fase1player = false;
    fase2player = false;
    sairOuMenu = true;
    seguirFaseDois = true;
}

Menu::~Menu()
{

}

void Menu::update(){}

int Menu::executar(int i)
{

    int op = -1;
    switch (i)
    {
        case 0:
            op = funMenuPrincipal();
            break;

        case 1:
            op = funMenuPause();
            break;
        case 2:
            op = funMenuSairOuMenu();
            break;
        case 3:
            op = funMenuSeguirFase2();
            break;
    }

    return op;
}

int Menu::opcaoMenuNovoJogo()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && contador <1 && naoDuplica > 7)
    {
        contador++;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && contador > 0 && naoDuplica > 7)
    {
        contador--;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && naoDuplica > 7)
    {
        naoDuplica = 0;
        return contador;
    }

    switch (contador)
    {
        case 0:
            Player1.setColor(sf::Color::Red);
            Player2.setColor(sf::Color::White);
            break;

        case 1:
            Player2.setColor(sf::Color::Red);
            Player1.setColor(sf::Color::White);
            break;
    }

    if(naoDuplica < 100)
    {
        naoDuplica++;
    }

    return -1;
}

int Menu::opcaoMenuPrincipal()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && contador <2 && naoDuplica > 7)
    {
        contador++;
        naoDuplica = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && contador >0 && naoDuplica > 7)
    {
        contador--;
        naoDuplica = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && naoDuplica > 7)
    {
        naoDuplica = 0;
        return contador;
    }

    switch (contador)
    {
        case 0:
            NovoJogo.setColor(sf::Color::Black);
            Ranking.setColor(sf::Color::White);
            Sair.setColor(sf::Color::White);
            break;

        case 1:
            NovoJogo.setColor(sf::Color::White);
            Ranking.setColor(sf::Color::Black);
            Sair.setColor(sf::Color::White);
            break;

        case 2:
            NovoJogo.setColor(sf::Color::White);
            Ranking.setColor(sf::Color::White);
            Sair.setColor(sf::Color::Black);
            break;
    }

    if(naoDuplica < 100)
    {
        naoDuplica++;
    }

    return -1;
}

int Menu::opcaoMenuFase1player()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && contador <1 && naoDuplica > 7)
    {
        contador++;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && contador > 0 && naoDuplica > 7)
    {
        contador--;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && naoDuplica > 10)
    {
        naoDuplica = 0;
        return contador;
    }

    switch (contador)
    {
        case 0:
            Fase1.setColor(sf::Color::Red);
            Fase2.setColor(sf::Color::White);
            break;

        case 1:
            Fase2.setColor(sf::Color::Red);
            Fase1.setColor(sf::Color::White);
            break;
    }

    if(naoDuplica < 100)
    {
        naoDuplica++;
    }

    return -1;
}

int Menu::opcaoMenuFase2player()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && contador <1 && naoDuplica > 7)
    {
        contador++;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && contador > 0 && naoDuplica > 7)
    {
        contador--;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && naoDuplica > 10)
    {
        naoDuplica = 0;
        return contador;
    }

    switch (contador)
    {
        case 0:
            Fase1.setColor(sf::Color::Red);
            Fase2.setColor(sf::Color::White);
            break;

        case 1:
            Fase2.setColor(sf::Color::Red);
            Fase1.setColor(sf::Color::White);
            break;
    }

    if(naoDuplica < 100)
    {
        naoDuplica++;
    }

    return -1;
}

int Menu::funMenuPrincipal()
{
    if(menuPrincipal)
    {
        //std::cout<<"TRUEEE"<<std::endl;

        fundo.setSize(sf::Vector2f(800.0f, 600.0f));
        fundo.setPosition(sf::Vector2f(50.0f, 0.0f));
        fundo.setFillColor(sf::Color::Red);
        gerenciadorGrafico->draw(fundo);

        sf::Font font;
        font.loadFromFile(gerenciadorGrafico->getFont());

        NovoJogo.setString("Novo Jogo");
        Ranking.setString("Ranking");
        Sair.setString("Sair");

        NovoJogo.setFont(font);
        Ranking.setFont(font);
        Sair.setFont(font);

        NovoJogo.setPosition(50.0f, 0.0f);
        Ranking.setPosition(50.0f, 30.0f);
        Sair.setPosition(50.0f, 60.0f);

        gerenciadorGrafico->draw(NovoJogo);
        gerenciadorGrafico->draw(Ranking);
        gerenciadorGrafico->draw(Sair);
        int op = -1;
        op = opcaoMenuPrincipal();
        switch (op)
        {
            case 0:
            {
                menuPrincipal = false;
                novoJogo = true;
            }
                break;

            case 1:
            {
                ranking = true;
                menuPrincipal = false;
            }

                break;

            case 2:
            {
                return 5;
                menuPrincipal = false;
            }
                break;

        }
    }

    if(novoJogo)
    {
        fundo.setSize(sf::Vector2f(800.0f, 600.0f));
        fundo.setPosition(sf::Vector2f(50.0f, 0.0f));
        fundo.setFillColor(sf::Color::Cyan);
        gerenciadorGrafico->draw(fundo);

        sf::Font font;
        font.loadFromFile(gerenciadorGrafico->getFont());

        Player1.setString("Um Jogador");
        Player2.setString("Dois Jogadores");

        Player1.setFont(font);
        Player2.setFont(font);

        Player1.setPosition(50.0f, 0.0f);
        Player2.setPosition(50.0f, 30.0f);

        gerenciadorGrafico->draw(Player1);
        gerenciadorGrafico->draw(Player2);

        int op = -1;
        op = opcaoMenuNovoJogo();


        switch (op)
        {
            case 0:
                novoJogo = false;
                fase1player = true;
                break;

            case 1:
                novoJogo = false;
                fase2player = true;
                break;
        }
    }
    if(fase1player)
    {
        fundo.setSize(sf::Vector2f(800.0f, 600.0f));
        fundo.setPosition(sf::Vector2f(50.0f, 0.0f));
        fundo.setFillColor(sf::Color::Magenta);
        gerenciadorGrafico->draw(fundo);

        sf::Font font;
        font.loadFromFile(gerenciadorGrafico->getFont());

        Fase1.setString("Fase 1");
        Fase2.setString("Fase 2");

        Fase1.setFont(font);
        Fase2.setFont(font);

        Fase1.setPosition(50.0f, 0.0f);
        Fase2.setPosition(50.0f, 30.0f);

        gerenciadorGrafico->draw(Fase1);
        gerenciadorGrafico->draw(Fase2);

        int op = -1;
        op = opcaoMenuFase1player();

        switch (op)
        {
            case 0:
                fase1player = false;
                return 1;
                break;

            case 1:
                fase1player = false;
                return 2;
                break;
        }

    }
    if(fase2player)
    {
        fundo.setSize(sf::Vector2f(800.0f, 600.0f));
        fundo.setPosition(sf::Vector2f(50.0f, 0.0f));
        fundo.setFillColor(sf::Color::Magenta);
        gerenciadorGrafico->draw(fundo);

        sf::Font font;
        font.loadFromFile(gerenciadorGrafico->getFont());

        Fase1.setString("Fase 1");
        Fase2.setString("Fase 2");

        Fase1.setFont(font);
        Fase2.setFont(font);

        Fase1.setPosition(50.0f, 0.0f);
        Fase2.setPosition(50.0f, 30.0f);

        gerenciadorGrafico->draw(Fase1);
        gerenciadorGrafico->draw(Fase2);

        int op = -1;
        op = opcaoMenuFase2player();

        switch (op)
        {
            case 0:
                fase2player = false;
                return 3;
                break;

            case 1:
                fase2player = false;
                return 4;
                break;
        }

    }

}

int Menu::opcaoMenuPause()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && contador <1 && naoDuplica > 7)
    {
        contador++;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && contador > 0 && naoDuplica > 7)
    {
        contador--;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && naoDuplica > 7)
    {
        naoDuplica = 0;
        return contador;
    }

    switch (contador)
    {
        case 0:
            DesPause.setColor(sf::Color::Red);
            Sair.setColor(sf::Color::White);
            break;

        case 1:
            Sair.setColor(sf::Color::Red);
            DesPause.setColor(sf::Color::White);
            break;
    }

    if(naoDuplica < 100)
    {
        naoDuplica++;
    }

    return -1;
}

int Menu::funMenuPause()
{
    if(menuPause)
    {
        fundo.setSize(sf::Vector2f(800.0f, 600.0f));
        fundo.setPosition(sf::Vector2f(0.0f, 0.0f));
        fundo.setFillColor(sf::Color::Blue);
        gerenciadorGrafico->draw(fundo);

        sf::Font font;
        font.loadFromFile(gerenciadorGrafico->getFont());

        DesPause.setString("Voltar para o Jogo");
        Sair.setString("Sair");

        DesPause.setFont(font);
        Sair.setFont(font);

        DesPause.setPosition(0.0f, 0.0f);
        Sair.setPosition(0.0f, 30.0f);

        gerenciadorGrafico->draw(DesPause);
        gerenciadorGrafico->draw(Sair);

        int op = -1;
        op = opcaoMenuPause();

        switch(op)
        {
            case 0:
                menuPause = false;
                return 6;
                break;
            case 1:
                menuPause = false;
                return 5;
                break;
        }

    }
}

int Menu::opcaoMenuSairOuMenu()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && contador <1 && naoDuplica > 7)
    {
        contador++;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && contador > 0 && naoDuplica > 7)
    {
        contador--;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && naoDuplica > 7)
    {
        naoDuplica = 0;
        return contador;
    }

    switch (contador)
    {
        case 0:
            MenuPrincipalText.setColor(sf::Color::Red);
            Sair.setColor(sf::Color::White);
            break;

        case 1:
            Sair.setColor(sf::Color::Red);
            MenuPrincipalText.setColor(sf::Color::White);
            break;
    }

    if(naoDuplica < 100)
    {
        naoDuplica++;
    }

    return -1;
}

int Menu::funMenuSairOuMenu()
{
    if(sairOuMenu)
    {
        fundo.setSize(sf::Vector2f(800.0f, 600.0f));
        fundo.setPosition(sf::Vector2f(0.0f, 0.0f));
        fundo.setFillColor(sf::Color::Blue);
        gerenciadorGrafico->draw(fundo);

        sf::Font font;
        font.loadFromFile(gerenciadorGrafico->getFont());

        MenuPrincipalText.setString("Voltar para o Menu");
        Sair.setString("Sair");

        MenuPrincipalText.setFont(font);
        Sair.setFont(font);

        MenuPrincipalText.setPosition(0.0f, 0.0f);
        Sair.setPosition(0.0f, 30.0f);

        gerenciadorGrafico->draw(MenuPrincipalText);
        gerenciadorGrafico->draw(Sair);

        int op = -1;
        op = opcaoMenuSairOuMenu();

        switch(op)
        {
            case 0:
                sairOuMenu = false;
                return 0;
                break;
            case 1:
                sairOuMenu = false;
                return 5;
                break;
        }

    }
}

int Menu::opcaoMenuSeguiFase2()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && contador <1 && naoDuplica > 7)
    {
        contador++;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && contador > 0 && naoDuplica > 7)
    {
        contador--;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && naoDuplica > 7)
    {
        naoDuplica = 0;
        return contador;
    }

    switch (contador)
    {
        case 0:
            SeguirFaseDois.setColor(sf::Color::Red);
            Sair.setColor(sf::Color::White);
            break;

        case 1:
            Sair.setColor(sf::Color::Red);
            SeguirFaseDois.setColor(sf::Color::White);
            break;
    }

    if(naoDuplica < 100)
    {
        naoDuplica++;
    }

    return -1;
}

int Menu::funMenuSeguirFase2()
{
    if(seguirFaseDois)
    {
        fundo.setSize(sf::Vector2f(800.0f, 600.0f));
        fundo.setPosition(sf::Vector2f(0.0f, 0.0f));
        fundo.setFillColor(sf::Color::Blue);
        gerenciadorGrafico->draw(fundo);

        sf::Font font;
        font.loadFromFile(gerenciadorGrafico->getFont());

        SeguirFaseDois.setString("Ir para segunda fase");
        Sair.setString("Sair");

        SeguirFaseDois.setFont(font);
        Sair.setFont(font);

        SeguirFaseDois.setPosition(0.0f, 0.0f);
        Sair.setPosition(0.0f, 30.0f);

        gerenciadorGrafico->draw(SeguirFaseDois);
        gerenciadorGrafico->draw(Sair);

        int op = -1;
        op = opcaoMenuSairOuMenu();

        switch(op)
        {
            case 0:
                seguirFaseDois = false;
                return 7;
                break;
            case 1:
                seguirFaseDois = false;
                return 5;
                break;
        }

    }
}


void Menu::draw(sf::Text text)
{
    //gerenciadorGrafico->draw(text);
}

sf::Font Menu::getFont()
{
    font.loadFromFile(gerenciadorGrafico->getFont());
    return font;
}
