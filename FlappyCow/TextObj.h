

#ifndef TEXT_Obj_H_
#define TEXT_Obj_H_
#include "CommonFunc.h"

class TextObj
{
public:
  TextObj(void);
  ~TextObj(void);

  enum TextColor
  {
    RED_TEXT  = 0,
    WHITE_TEXT = 1,
    BLACK_TEXT = 2,
  };

  bool loadFromRenderedText(TTF_Font* gFont, SDL_Renderer* screen);
  void Free();

  void setColor(Uint8 red, Uint8 green, Uint8 blue);
  void setColor(int type);

  void RenderText(SDL_Renderer* screen, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

  int getWidth() const {return width_;}
  int getHeight() const {return height_;}
  void SetText(const std::string& text) {str_value = text;}
  std::string GetText() const {return str_value;}

private:
  std::string str_value;
  SDL_Color text_coloring;
  SDL_Texture* texture_;
  int width_;
  int height_;

};

#endif

