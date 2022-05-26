
#include "PlayerObj.h"

PlayerObj::PlayerObj()
{
    is_falling_ = false;
    y_value = 0;
    gravity = 0.4;
}

PlayerObj::~PlayerObj()
{
  Free();
}

void PlayerObj::HandleInputAction(SDL_Event events, SDL_Renderer* screen) 
{
  if( events.type == SDL_KEYDOWN )
  {
    switch( events.key.keysym.sym )
    {
    case SDLK_SPACE:
      {
        if (is_falling_ == false)
        {
            y_value = -6;
        }
      }
    }
  }
  
}


bool PlayerObj::LoadImg(std::string path, SDL_Renderer* screen)
{
  bool ret = BaseObj::LoadImageFile(path, screen);
  return ret;
}

void PlayerObj::Show(SDL_Renderer* des)
{
   BaseObj::Render(des);
}

void PlayerObj::DoFalling(SDL_Renderer* des)
{
    y_value += gravity;
    rect_.y += y_value;
    if ((rect_.y + rect_.h) >= GROUND_MAP)
    {
        LoadImg("img//cow2.png", des);
        is_falling_ = true;
        DoGround(des);
    }
}

void PlayerObj::DoGround(SDL_Renderer* screen)
{
    y_value = 0;
    rect_.y = GROUND_MAP - rect_.h;
    death_ = true;
}