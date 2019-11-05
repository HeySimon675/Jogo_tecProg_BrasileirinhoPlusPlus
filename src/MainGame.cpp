#include "MainGame.h"



MainGame::MainGame()
{

}


MainGame::~MainGame()
{
    delete menu;
}

void MainGame::Execute()
{

	menu = new Menu;
	int op = -1;
    int op2 = -1;
    int op3 = -1;

	while (op != 0)
	{

		op = menu->execute();

		switch (op)
		{
		case 1:
		{
			createLevel_1_1(builder1);
			Level* level1 = builder1.getLevel();
			op2 = level1->Execute();
             std::cout<<op2<<std::endl;
            switch(op2)
            {
                case 0:
                {
                    break;
                }
                case 1:
                {
                     std::cout<<"OPSKAOPDKSAOPK"<<std::endl;
                    op3 = menu->executeOp1();
                    if(op3 == 1)
                        break;
                }
                case 2:
                {
                  op3=  menu->executeOp2();
                  if(op3 == 1)
                  {
                      break;
                  }
                  if(op3 == 2)
                  {
                    createLevel_2_1(builder2);
                    Level* level2 = builder2.getLevel();
                    op2 = level2->Execute();
                    if(op2 == 1)
                    {
                        op3=menu->executeOp1();
                        if(op3 == 1)
                            break;
                    }
                    if(op2 == 3)
                    {
                        op3=menu->executeOp3();
                        if(op3 == 1)
                            break;
                    }
                    break;
                  }
                  break;
                }
            }
			break;
		}
		case 2:
		{
			createLevel_1_2(builder1);
			Level* level1 = builder1.getLevel();
			op2 = level1->Execute();
             std::cout<<op2<<std::endl;
            switch(op2)
            {
                case 0:
                {
                    break;
                }
                case 1:
                {
                     std::cout<<"OPSKAOPDKSAOPK"<<std::endl;
                    op3 = menu->executeOp1();
                    if(op3 == 1)
                        break;
                }
                case 2:
                {
                  op3=  menu->executeOp2();
                  if(op3 == 1)
                  {
                      break;
                  }
                  if(op3 == 2)
                  {
                    createLevel_2_2(builder2);
                    Level* level2 = builder2.getLevel();
                    op2 = level2->Execute();
                    if(op2 == 1)
                    {
                        op3=menu->executeOp1();
                        if(op3 == 1)
                            break;
                    }
                    if(op2 == 3)
                    {
                        op3=menu->executeOp3();
                        if(op3 == 1)
                            break;
                    }
                    break;
                  }
                  break;
                }
            }
			break;
		}

		case 3:
        {
            createLevel_2_1(builder2);
            Level* level2 = builder2.getLevel();
            op2 = level2->Execute();
            switch(op2)
            {
                case 0:
                {
                    break;
                }
                case 1:
                {
                    op3 = menu->executeOp1();
                    if(op3 == 1)
                        break;
                }
                case 3:
                {
                  op3=  menu->executeOp3();
                  if(op3 == 1)
                  {
                      break;
                  }
                }
            }
            break;
        }

        case 4:
        {
            createLevel_2_2(builder2);
            Level* level2 = builder2.getLevel();
            op2 = level2->Execute();
            switch(op2)
            {
                case 0:
                {
                    break;
                }
                case 1:
                {
                    op3 = menu->executeOp1();
                    if(op3 == 1)
                        break;
                }
                case 3:
                {
                  op3=  menu->executeOp3();
                  if(op3 == 1)
                  {
                      break;
                  }
                }
            }
            break;
        }

		}
	}


}

void MainGame::createLevel_1_1(LevelBuilder& builder)
{
	builder.BuildLevel();
	builder.BuildBackground(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT));
	builder.BuildBackground_1(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_3.png", -0.01f, -15.2f);
	builder.BuildBackground_1(sf::Vector2f(WINDOW_WIDHT, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_3.png", -0.01f, -15.2f);
	builder.BuildBackground_1(sf::Vector2f(-300.0f, -230.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_2.png", -0.02, -20.0f);
	builder.BuildBackground_1(sf::Vector2f(WINDOW_WIDHT - 300, -230.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_2.png", -0.02, -20.0f);
	builder.BuildBackground_2(sf::Vector2f(0.0f, 100.0f), sf::Vector2f(7000.0f, 500.0f), "Textures/FundoParado.png");
	builder.BuildPlayer(sf::Vector2f(100.0f, 610.0f), sf::Vector2f(40.0f, 80.0f));
	builder.BuildPlatform(sf::Vector2f(500.0f, 650.0f), sf::Vector2f(1420.0f, 100.0f), "Textures/Plataforma.png");
    builder.BuildPlatform(sf::Vector2f(1900.0f, 650.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma.png");
	builder.BuildPlatform(sf::Vector2f(2900.0f, 650.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma.png");
	builder.BuildPlatform(sf::Vector2f(3900.0f, 650.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma.png");
	builder.BuildPlatform(sf::Vector2f(3900.0f, 650.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma.png");
	builder.BuildPlatform(sf::Vector2f(4900.0f, 650.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma.png");
	builder.BuildPlatform(sf::Vector2f(5900.0f, 650.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma.png");
	builder.BuildPlatform(sf::Vector2f(6900.0f, 650.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma.png");
    builder.BuildPlatform(sf::Vector2f(500.0f, 750.0f), sf::Vector2f(1420.0f, 100.0f), "Textures/Plataforma2.png");
    builder.BuildPlatform(sf::Vector2f(1900.0f, 750.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma2.png");
	builder.BuildPlatform(sf::Vector2f(2900.0f, 750.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma2.png");
	builder.BuildPlatform(sf::Vector2f(3900.0f, 750.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma2.png");
	builder.BuildPlatform(sf::Vector2f(4900.0f, 750.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma2.png");
	builder.BuildPlatform(sf::Vector2f(5900.0f, 750.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma2.png");
	builder.BuildPlatform(sf::Vector2f(6900.0f, 750.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma2.png");
	builder.BuildObstacle(sf::Vector2f(250.0f, 550.0f), sf::Vector2f(100.0f, 100.0f), "Textures/boxAlt.png");
	builder.BuildObstacleFixos(sf::Vector2f(1150.0f, 550.0f), sf::Vector2f(120.0f, 240.0f), "Textures/boxWarning.png");
	//builder.BuildObstacleFixos(sf::Vector2f(750.0f, 450.0f), sf::Vector2f(100.0f, 100.0f), "Textures/boxWarning.png");

    int xrandEnem1, xrandEnem2, xrandCaixas, xrandPlat;
	int i=0;
	int j=0;
	int k=0;
	int l= 0;
	float enemy1Pos = 2300.0f;
	float enemy2Pos = 4500.0f;
	float caixaPos = 2000.0f;
	float platPos = 2000.0f;
    srand(time(NULL));
	xrandEnem1 = rand()%5 + 1;
	xrandEnem2 = rand()%5 + 1;
	xrandCaixas = rand()%5 +1;
	xrandPlat = rand()%10;

	while(i < xrandEnem1)
    {
        builder.BuildEnemy1(sf::Vector2f(enemy1Pos, 610.0f), sf::Vector2f(40.f, 80.f));
        enemy1Pos+=200.0f;
        i++;
    }

    while(j < xrandEnem2)
    {
        builder.BuildEnemy2(sf::Vector2f(enemy2Pos, 610.0f), sf::Vector2f(40.f, 80.f));
        enemy2Pos+=200.0f;
        j++;
    }

    while(k < xrandCaixas)
    {
        builder.BuildObstacle(sf::Vector2f(caixaPos, 550.0f), sf::Vector2f(100.0f, 100.0f), "Textures/boxAlt.png");
        caixaPos+=400.0f;
        k++;
    }

    while(l<xrandPlat)
    {
        builder.BuildPlatform(sf::Vector2f(platPos, 420.0f), sf::Vector2f(400.0f, 10.0f), "Textures/Plataforma.png");
        platPos+= 700.0f;
        l++;
    }
    builder.BuildBoss(sf::Vector2f(6800.0f, 610.0f), sf::Vector2f(85.f, 170.f));
}

void MainGame::createLevel_1_2(LevelBuilder& builder)
{
	builder.BuildLevel();
	builder.BuildBackground(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT));
	builder.BuildBackground_1(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_3.png", -0.01f, -15.2f);
	builder.BuildBackground_1(sf::Vector2f(WINDOW_WIDHT, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_3.png", -0.01f, -15.2f);
	builder.BuildBackground_1(sf::Vector2f(-300.0f, -230.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_2.png", -0.02, -20.0f);
	builder.BuildBackground_1(sf::Vector2f(WINDOW_WIDHT - 300, -230.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_2.png", -0.02, -20.0f);
	builder.BuildBackground_2(sf::Vector2f(0.0f, 100.0f), sf::Vector2f(7000.0f, 500.0f), "Textures/FundoParado.png");
	builder.BuildPlayer(sf::Vector2f(100.0f, 610.0f), sf::Vector2f(40.0f, 80.0f));
	builder.BuildPlayer2(sf::Vector2f(60.0f, 610.0f), sf::Vector2f(40.0f, 80.0f));
	builder.BuildPlatform(sf::Vector2f(500.0f, 650.0f), sf::Vector2f(1420.0f, 100.0f), "Textures/Plataforma.png");
    builder.BuildPlatform(sf::Vector2f(1900.0f, 650.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma.png");
	builder.BuildPlatform(sf::Vector2f(2900.0f, 650.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma.png");
	builder.BuildPlatform(sf::Vector2f(3900.0f, 650.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma.png");
	builder.BuildPlatform(sf::Vector2f(3900.0f, 650.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma.png");
	builder.BuildPlatform(sf::Vector2f(4900.0f, 650.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma.png");
	builder.BuildPlatform(sf::Vector2f(5900.0f, 650.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma.png");
	builder.BuildPlatform(sf::Vector2f(6900.0f, 650.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma.png");
    builder.BuildPlatform(sf::Vector2f(500.0f, 750.0f), sf::Vector2f(1420.0f, 100.0f), "Textures/Plataforma2.png");
    builder.BuildPlatform(sf::Vector2f(1900.0f, 750.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma2.png");
	builder.BuildPlatform(sf::Vector2f(2900.0f, 750.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma2.png");
	builder.BuildPlatform(sf::Vector2f(3900.0f, 750.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma2.png");
	builder.BuildPlatform(sf::Vector2f(4900.0f, 750.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma2.png");
	builder.BuildPlatform(sf::Vector2f(5900.0f, 750.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma2.png");
	builder.BuildPlatform(sf::Vector2f(6900.0f, 750.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Plataforma2.png");
	builder.BuildObstacle(sf::Vector2f(250.0f, 550.0f), sf::Vector2f(100.0f, 100.0f), "Textures/boxAlt.png");
	builder.BuildObstacleFixos(sf::Vector2f(1150.0f, 550.0f), sf::Vector2f(100.0f, 200.0f), "Textures/boxWarning.png");
	//builder.BuildObstacleFixos(sf::Vector2f(750.0f, 450.0f), sf::Vector2f(100.0f, 100.0f), "Textures/boxWarning.png");

	int xrandEnem1, xrandEnem2, xrandCaixas, xrandPlat;
	int i=0;
	int j=0;
	int k=0;
	int l= 0;
	float enemy1Pos = 2300.0f;
	float enemy2Pos = 4500.0f;
	float caixaPos = 2000.0f;
	float platPos = 2000.0f;
    srand(time(NULL));
	xrandEnem1 = rand()%5 + 1;
	xrandEnem2 = rand()%5 + 1;
	xrandCaixas = rand()%5 +1;
	xrandPlat = rand()%10;

	while(i < xrandEnem1)
    {
        builder.BuildEnemy1(sf::Vector2f(enemy1Pos, 610.0f), sf::Vector2f(40.f, 80.f));
        enemy1Pos+=200.0f;
        i++;
    }

    while(j < xrandEnem2)
    {
        builder.BuildEnemy2(sf::Vector2f(enemy2Pos, 610.0f), sf::Vector2f(40.f, 80.f));
        enemy2Pos+=200.0f;
        j++;
    }

    while(k < xrandCaixas)
    {
        builder.BuildObstacle(sf::Vector2f(caixaPos, 550.0f), sf::Vector2f(100.0f, 100.0f), "Textures/boxAlt.png");
        caixaPos+=400.0f;
        k++;
    }

    while(l<xrandPlat)
    {
        builder.BuildPlatform(sf::Vector2f(platPos, 420.0f), sf::Vector2f(400.0f, 10.0f), "Textures/Plataforma.png");
        platPos+= 700.0f;
        l++;
    }
    builder.BuildBoss(sf::Vector2f(6800.0f, 610.0f), sf::Vector2f(85.f, 170.f));
}

void MainGame::createLevel_2_1(LevelBuilder& builder)
{
    builder.BuildLevel();
	builder.BuildBackground(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT));
	builder.BuildBackground_1(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_3.png", -0.01f, -15.2f);
	builder.BuildBackground_1(sf::Vector2f(WINDOW_WIDHT, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_3.png", -0.01f, -15.2f);
	builder.BuildBackground_1(sf::Vector2f(-300.0f, -230.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_2.png", -0.02, -20.0f);
	builder.BuildBackground_1(sf::Vector2f(WINDOW_WIDHT - 300, -230.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_2.png", -0.02, -20.0f);
	builder.BuildBackground_2(sf::Vector2f(0.0f, 100.0f), sf::Vector2f(7000.0f, 500.0f), "Textures/FUNDO2.png");
	builder.BuildPlayer(sf::Vector2f(100.0f, 610.0f), sf::Vector2f(40.0f, 80.0f));
	builder.BuildPlatform(sf::Vector2f(500.0f, 700.0f), sf::Vector2f(1500.0f, 200.0f), "Textures/PlataformaFase2.png");
    builder.BuildPlatform(sf::Vector2f(1900.0f, 700.0f), sf::Vector2f(1000.0f, 200.0f), "Textures/PlataformaFase2.png");
	builder.BuildPlatform(sf::Vector2f(2900.0f, 700.0f), sf::Vector2f(1000.0f, 200.0f), "Textures/PlataformaFase2.png");
	builder.BuildPlatform(sf::Vector2f(3900.0f, 700.0f), sf::Vector2f(1000.0f, 200.0f), "Textures/PlataformaFase2.png");
	builder.BuildPlatform(sf::Vector2f(3900.0f, 700.0f), sf::Vector2f(1000.0f, 200.0f), "Textures/PlataformaFase2.png");
	builder.BuildPlatform(sf::Vector2f(4900.0f, 700.0f), sf::Vector2f(1000.0f, 200.0f), "Textures/PlataformaFase2.png");
	builder.BuildPlatform(sf::Vector2f(5900.0f, 700.0f), sf::Vector2f(1000.0f, 200.0f), "Textures/PlataformaFase2.png");
	builder.BuildPlatform(sf::Vector2f(6900.0f, 700.0f), sf::Vector2f(1000.0f, 200.0f), "Textures/PlataformaFase2.png");
	builder.BuildPlatform(sf::Vector2f(6100.0f, 420.0f), sf::Vector2f(200.0f, 10.0f), "Textures/PlataformaFase2.png");
	int xrandEnem1, xrandEnem2, xrandCaixas, xrandPlat;
	int i=0;
	int j=0;
	int k=0;
	int l= 0;
	float enemy1Pos = 2300.0f;
	float enemy2Pos = 4500.0f;
	float caixaPos = 2000.0f;
	float platPos = 2000.0f;
    srand(time(NULL));
	xrandEnem1 = rand()%5 + 1;
	xrandEnem2 = rand()%5 + 1;
	xrandCaixas = rand()%5 +1;
	xrandPlat = rand()%10;

	while(i < xrandEnem1)
    {
        builder.BuildEnemy1(sf::Vector2f(enemy1Pos, 610.0f), sf::Vector2f(40.f, 80.f));
        enemy1Pos+=200.0f;
        i++;
    }

    while(j < xrandEnem2)
    {
        builder.BuildEnemy2(sf::Vector2f(enemy2Pos, 610.0f), sf::Vector2f(40.f, 80.f));
        enemy2Pos+=200.0f;
        j++;
    }

    while(k < xrandCaixas)
    {
        builder.BuildObstacle(sf::Vector2f(caixaPos, 550.0f), sf::Vector2f(100.0f, 100.0f), "Textures/boxAlt.png");
        caixaPos+=400.0f;
        k++;
    }

    while(l<xrandPlat)
    {
        builder.BuildPlatform(sf::Vector2f(platPos, 420.0f), sf::Vector2f(400.0f, 10.0f), "Textures/PlataformaFase2.png");
        platPos+= 700.0f;
        l++;
    }
    builder.BuildBoss(sf::Vector2f(6800.0f, 610.0f), sf::Vector2f(85.f, 170.f));

}

void MainGame::createLevel_2_2(LevelBuilder& builder)
{
    builder.BuildLevel();
	builder.BuildBackground(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT));
	builder.BuildBackground_1(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_3.png", -0.01f, -15.2f);
	builder.BuildBackground_1(sf::Vector2f(WINDOW_WIDHT, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_3.png", -0.01f, -15.2f);
	builder.BuildBackground_1(sf::Vector2f(-300.0f, -230.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_2.png", -0.02, -20.0f);
	builder.BuildBackground_1(sf::Vector2f(WINDOW_WIDHT - 300, -230.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_2.png", -0.02, -20.0f);
	builder.BuildBackground_2(sf::Vector2f(0.0f, 100.0f), sf::Vector2f(7000.0f, 500.0f), "Textures/FUNDO2.png");
	builder.BuildPlayer(sf::Vector2f(100.0f, 610.0f), sf::Vector2f(40.0f, 80.0f));
	builder.BuildPlayer2(sf::Vector2f(100.0f, 610.0f), sf::Vector2f(40.0f, 80.0f));
	builder.BuildPlatform(sf::Vector2f(500.0f, 700.0f), sf::Vector2f(1500.0f, 200.0f), "Textures/PlataformaFase2.png");
    builder.BuildPlatform(sf::Vector2f(1900.0f, 700.0f), sf::Vector2f(1000.0f, 200.0f), "Textures/PlataformaFase2.png");
	builder.BuildPlatform(sf::Vector2f(2900.0f, 700.0f), sf::Vector2f(1000.0f, 200.0f), "Textures/PlataformaFase2.png");
	builder.BuildPlatform(sf::Vector2f(3900.0f, 700.0f), sf::Vector2f(1000.0f, 200.0f), "Textures/PlataformaFase2.png");
	builder.BuildPlatform(sf::Vector2f(3900.0f, 700.0f), sf::Vector2f(1000.0f, 200.0f), "Textures/PlataformaFase2.png");
	builder.BuildPlatform(sf::Vector2f(4900.0f, 700.0f), sf::Vector2f(1000.0f, 200.0f), "Textures/PlataformaFase2.png");
	builder.BuildPlatform(sf::Vector2f(5900.0f, 700.0f), sf::Vector2f(1000.0f, 200.0f), "Textures/PlataformaFase2.png");
	builder.BuildPlatform(sf::Vector2f(6900.0f, 700.0f), sf::Vector2f(1000.0f, 200.0f), "Textures/PlataformaFase2.png");
	builder.BuildPlatform(sf::Vector2f(6100.0f, 420.0f), sf::Vector2f(200.0f, 10.0f), "Textures/PlataformaFase2.png");

	int xrandEnem1, xrandEnem2, xrandCaixas, xrandPlat;
	int i=0;
	int j=0;
	int k=0;
	int l= 0;
	float enemy1Pos = 2300.0f;
	float enemy2Pos = 4500.0f;
	float caixaPos = 2000.0f;
	float platPos = 2000.0f;
    srand(time(NULL));
	xrandEnem1 = rand()%5 + 1;
	xrandEnem2 = rand()%5 + 1;
	xrandCaixas = rand()%5 +1;
	xrandPlat = rand()%10;

	while(i < xrandEnem1)
    {
        builder.BuildEnemy1(sf::Vector2f(enemy1Pos, 610.0f), sf::Vector2f(40.f, 80.f));
        enemy1Pos+=200.0f;
        i++;
    }

    while(j < xrandEnem2)
    {
        builder.BuildEnemy2(sf::Vector2f(enemy2Pos, 610.0f), sf::Vector2f(40.f, 80.f));
        enemy2Pos+=200.0f;
        j++;
    }

    while(k < xrandCaixas)
    {
        builder.BuildObstacle(sf::Vector2f(caixaPos, 550.0f), sf::Vector2f(100.0f, 100.0f), "Textures/boxAlt.png");
        caixaPos+=400.0f;
        k++;
    }

    while(l<xrandPlat)
    {
        builder.BuildPlatform(sf::Vector2f(platPos, 420.0f), sf::Vector2f(400.0f, 10.0f), "Textures/PlataformaFase2.png");
        platPos+= 700.0f;
        l++;
    }
    builder.BuildBoss(sf::Vector2f(6800.0f, 610.0f), sf::Vector2f(85.f, 170.f));
}

