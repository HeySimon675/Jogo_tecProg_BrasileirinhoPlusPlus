#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include "Level.h"

class Menu
{
public:
	Menu();
	~Menu();
	int execute();
	int executeOp1();
	int executeOp2();
	int executeOp3();
	//void draw(sf::RenderWindow *window);

private:

	Level* level;
	sf::RenderWindow* window;

	const char* MENU_TEXT = "Textures/JogoInicio.png";
	const char* NOVO_JOGO = "Textures/NewGameButton.png";
	const char* NOVO_JOGO_RED = "Textures/NovoJogoRedButton.png";
	const char* CARREGAR_JOGO = "Textures/CarregarJogo.png";
	const char* CARREGAR_JOGO_RED = "Textures/CarregarJogoRed.png";
	const char* FASE_DOIS = "Textures/FaseDoisMenu.png";
	const char* FASE_DOIS_RED = "Textures/FaseDoisMenuRed.png";
	const char* UM_PLAYER = "Textures/UmJogador.png";
	const char* UM_PLAYER_RED = "Textures/UmJogadorRed.png";
	const char* DOIS_PLAYERS = "Textures/DoisJogadores.png";
	const char* DOIS_PLAYERS_RED = "Textures/DoisJogadoresRed.png";
	const char* SCOTT = "Textures/Scott.png";
	const char* RAMONA = "Textures/Ramona.png";
	const char* RANKING = "Textures/Ranking.png";
	const char* RANKING_RED = "Textures/RankingRed.png";
	const char* LOSE = "Textures/Derrota.png";
	const char* VICTORY = "Textures/Vitoria.png";
	const char* IR_AO_MENU = "Textures/IrAoMenu.png";
	const char* IR_AO_MENU_RED = "Textures/IrAoMenuRed.png";
	const char* IR_PARA_FASE = "Textures/IrParaFase2.png";
	const char* IR_PARA_FASE_RED = "Textures/IrParaFase2Red.png";

	const float WINDOW_WIDHT = 1366.0f;
	const float WINDOW_HEIGHT = 768.0f;

	sf::Texture menuTexture;
	sf::Sprite menuSprite;

	sf::Texture novoJogo;
	sf::Sprite novoJogoSprite;

	sf::Texture rankingText;
	sf::Sprite rankingSprite;

	sf::Texture carregarJogo;
	sf::Sprite carregarJogoSprite;

	sf::Texture faseDois;
	sf::Sprite faseDoisSprite;

	sf::Texture umJogador;
	sf::Sprite umJogadorSprite;

	sf::Texture doisJogadores;
	sf::Sprite doisJogadoresSprite;

	sf::Texture ScottT;
	sf::Sprite ScottS;

	sf::Texture RamonaT;
	sf::Sprite RamonaS;

	sf::Texture LoseText;
	sf::Sprite LoseSprite;

	sf::Texture IrAoMenuText;
	sf::Sprite IrAoMenuSprite;

	sf::Texture victoryText;
	sf::Sprite victorySprite;

	sf::Texture IrParaFase2Text;
	sf::Sprite IrParaFase2Sprite;


	bool LayerOne;
	bool fase1;
	bool transparent;

};

