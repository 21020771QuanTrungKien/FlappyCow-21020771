
#ifndef MAIN_Obj_H_
#define MAIN_Obj_H_

#include "CommonFunc.h"

class PlayerObj : public BaseObj
{
public:
  PlayerObj();
  ~PlayerObj();

  bool LoadImg(std::string path, SDL_Renderer* screen);
  void Show(SDL_Renderer* des);
  void HandleInputAction(SDL_Event events, SDL_Renderer* screen); 

  void DoFalling(SDL_Renderer* des);
  bool GetFalling() const { return is_falling_; }
  void SetFalling(bool falling) { is_falling_ = falling; }
  void DoGround(SDL_Renderer* screen);
  bool GetIsDie() const { return death_; }
private:
  bool is_falling_;
  float x_value;
  float y_value;
  float gravity;
  bool death_;
};
#endif