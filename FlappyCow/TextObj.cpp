#include "TextObj.h"


TextObj::TextObj(void)
{
  text_coloring.r = 255;
  text_coloring.g = 255;
  text_coloring.b = 255;
}


TextObj::~TextObj(void)
{
}


bool TextObj::loadFromRenderedText(TTF_Font* gFont, SDL_Renderer* screen)
{
  //Render text surface
  SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, str_value.c_str(), text_coloring);
  if( textSurface != NULL )
  {
    //Create texture from surface pixels
    texture_ = SDL_CreateTextureFromSurface(screen, textSurface );
    if( texture_ != NULL )
    {
      //image dimensions
      width_ = textSurface->w;
      height_ = textSurface->h;
    }

    SDL_FreeSurface( textSurface );
  }

  return texture_ != NULL;
}

void TextObj::Free()
{
  if(texture_ != NULL)
  {
    SDL_DestroyTexture(texture_);
    texture_ = NULL;
  }
}

void TextObj::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
  text_coloring.r = red;
  text_coloring.g = green;
  text_coloring.b = blue;
}

void TextObj::setColor(int type)
{
  if (type == RED_TEXT)
  {
    SDL_Color color = {255, 0, 0};
    text_coloring = color;
  }
  else if (type == WHITE_TEXT)
  {
    SDL_Color color = {255, 255, 255};
    text_coloring = color;
  }
  else
  {
    SDL_Color color = {0, 0, 0};
    text_coloring = color;
  }
}
void TextObj::RenderText(SDL_Renderer* screen, int x, int y, SDL_Rect* clip , double angle , SDL_Point* center , SDL_RendererFlip flip )
{
  //Set rendering space and render to screen
  SDL_Rect renderQuad = { x, y, width_, height_ };

  //Set clip rendering dimensions
  if( clip != NULL )
  {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }

  //Render to screen
  SDL_RenderCopyEx(screen, texture_, clip, &renderQuad, angle, center, flip );
}
