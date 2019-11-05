#include "Boss.h"

Boss::Boss(const char* textureFile, float speed, float jumpHeight)
{
	sf::Vector2f position;
	position.x = 0.0f;
	position.y = 0.0f;

	sf::Vector2f size;
	size.x = 0.0f;
	size.y = 0.0f;

	sf::Vector2u imgCount;
	imgCount.x = 0;
	imgCount.y = 0;

	InitializeBoss(position, size, textureFile, imgCount, speed, jumpHeight);
}

Boss::~Boss()
{
}

void Boss::InitializeBoss(sf::Vector2f position, sf::Vector2f size, const char * textureFile, sf::Vector2u imgCount, float speed, float jumpHeight)
{
	InitializeEnemy(position, size, textureFile, imgCount, speed, jumpHeight);
	row = 0;
	faceRight = false;
}

void Boss::calcMovement(const float deltaTime, sf::Vector2f position1, sf::Vector2f position2)
{
   row = 0;

     std::cout<< totalTime << std::endl;


     if(base.getPosition().x - position1.x <= 1000.0f || base.getPosition().x - position2.x <= 1000.0f )
     {
          totalTime+= deltaTime;
          if(totalTime>= 3.0f && totalTime < 4.0f)
          {
                if(base.getPosition().x >= 5650.0f)
                {
                    row = 1;
                    faceRight = false;
                    velocity.x -= 200.0f;
                }
                else
                {
                    row = 0;
                    faceRight = true;
                    velocity.x = 0;
                }
          }
          if(totalTime >= 4.0f && totalTime <= 6.5f)
          {
              velocity.x = 0;
              row = 0;
          }
          if(totalTime >= 6.5f && totalTime< 7.5f)
          {
              if(base.getPosition().x <= 6700)
              {
                  row = 1;
                  faceRight = true;
                  velocity.x +=200.0f;
              }
              else
              {
                    row = 0;
                    faceRight = false;
                    velocity.x =0;
              }
          }
          if(totalTime >= 7.5f && totalTime < 10.0f)
          {
              velocity.x = 0;
              row = 0;
          }
          if(totalTime >= 10.0f)
          {
              totalTime = 3.0f;
          }

     }

      velocity.y += 981.0f * deltaTime;

}

void Boss::calcMovement(const float deltaTime, sf::Vector2f position1)
{
	row = 0;

     std::cout<< totalTime << std::endl;


     if(base.getPosition().x - position1.x <= 1000.0f)
     {
          totalTime+= deltaTime;
          if(totalTime>= 3.0f && totalTime < 4.0f)
          {
                if(base.getPosition().x >= 5650.0f)
                {
                    row = 1;
                    faceRight = false;
                    velocity.x -= 200.0f;
                }
                else
                {
                    row = 0;
                    faceRight = true;
                    velocity.x = 0;
                }
          }
          if(totalTime >= 4.0f && totalTime <= 6.5f)
          {
              velocity.x = 0;
              row = 0;
          }
          if(totalTime >= 6.5f && totalTime< 7.5f)
          {
              if(base.getPosition().x <= 6700)
              {
                  row = 1;
                  faceRight = true;
                  velocity.x +=200.0f;
              }
              else
              {
                    row = 0;
                    faceRight = false;
                    velocity.x =0;
              }
          }
          if(totalTime >= 7.5f && totalTime < 10.0f)
          {
              velocity.x = 0;
              row = 0;
          }
          if(totalTime >= 10.0f)
          {
              totalTime = 3.0f;
          }

     }

      velocity.y += 981.0f * deltaTime;
}
