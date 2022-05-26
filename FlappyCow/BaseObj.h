
#ifndef BASIC_Obj_H_
#define BASIC_Obj_H_

#include "CommonFunc.h"

class BaseObj
{
public:
  BaseObj();
  ~BaseObj();
  virtual bool LoadImageFile(std::string path, SDL_Renderer* screen);
  void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
  
  void Free();
  void SetRect(const int& x, const int& y) {rect_.x = x, rect_.y = y;};
  SDL_Rect GetRect() const {return rect_;}
  SDL_Texture* GetObj() {return p_Obj_;}
protected:
  SDL_Texture* p_Obj_;
  SDL_Rect rect_;
};


#endif