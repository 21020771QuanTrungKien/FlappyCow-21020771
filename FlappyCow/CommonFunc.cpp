
#include "CommonFunc.h"

int SDLCommonFunc::ShowMenu(SDL_Renderer* g_screen, TTF_Font* font, 
                            const std::string& menu1, 
                            const std::string& menu2,
                            const std::string& img_name)
{
    char* ch1 = (char*)menu1.c_str();
    char* ch2 = (char*)menu2.c_str();
    char* img_file = (char*)img_name.c_str();

    int size1 = menu1.length();
    int size2 = menu2.length();

    int time = 0;
    int x = 0;
    int y = 0;
    const int kMenu = 2;
    char* labels[kMenu];

    labels[0] = new char [size1 + 1];
    labels[1] = new char[size2 + 1];

    strcpy_s(labels[0], size1+1, ch1);
    strcpy_s(labels[1], size2+1, ch2);

    SDL_Texture* menu[kMenu];
    bool selected[kMenu] = { 0, 0 };
    SDL_Color color[2] = { { 255, 255, 255 },{ 255, 0, 0 } };

    TextObj text_Obj[kMenu];
    text_Obj[0].SetText(labels[0]);
    text_Obj[0].setColor(color[0].r, color[0].g, color[0].b);

    text_Obj[0].loadFromRenderedText(font, g_screen);

    text_Obj[1].SetText(labels[1]);
    text_Obj[1].setColor(color[0].r, color[0].g, color[0].b);
    text_Obj[1].loadFromRenderedText(font, g_screen);


    SDL_Rect pos[kMenu];
    pos[0].x = SCREEN_WIDTH*0.3 +10 ;
    pos[0].y = SCREEN_HEIGHT*0.8 - 150;
    pos[1].x = SCREEN_WIDTH*0.3 + 140 ;
    pos[1].y = SCREEN_HEIGHT*0.8 - 50 ;

    BaseObj gBackground;
    bool ret = gBackground.LoadImageFile(img_file, g_screen);

    SDL_Event event;
    while (1)
    {
        time = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                text_Obj[0].Free();
                text_Obj[0].Free();
                gBackground.Free();
                return 1;
            case SDL_MOUSEMOTION:
                x = event.motion.x;
                y = event.motion.y;
                for (int i = 0; i < kMenu; ++i)
                {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
                        y >= pos[i].y && y <= pos[i].y + pos[i].h)
                    {
                        if (!selected[i])
                        {
                            selected[i] = 1;
                            text_Obj[i].SetText(labels[i]);
                            text_Obj[i].setColor(color[1].r, color[1].g, color[1].b);
                            text_Obj[i].loadFromRenderedText(font, g_screen);
                        }
                    }
                    else
                    {
                        if (selected[i])
                        {
                            selected[i] = 0;
                            text_Obj[i].Free();
                            text_Obj[i].SetText(labels[i]);
                            text_Obj[i].setColor(color[0].r, color[0].g, color[0].b);
                            text_Obj[i].loadFromRenderedText(font, g_screen);
                        }
                    }
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                x = event.button.x;
                y = event.button.y;
                for (int i = 0; i < kMenu; ++i) {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
                        y >= pos[i].y && y <= pos[i].y + pos[i].h)
                    {
                        text_Obj[0].Free();
                        text_Obj[1].Free();
                        gBackground.Free();
                        return i;
                    }
                }
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    text_Obj[0].Free();
                    text_Obj[1].Free();
                    gBackground.Free();
                    return 1;
                }
            }
        }

        gBackground.Render(g_screen, NULL);

        for (int i = 0; i < kMenu; ++i)
        {
            text_Obj[i].RenderText(g_screen, pos[i].x, pos[i].y);
            pos[i].w = text_Obj[i].getWidth();
            pos[i].h = text_Obj[i].getHeight();
        }


        SDL_RenderPresent(g_screen);
        if (1000 / 30 > (SDL_GetTicks() - time))
            SDL_Delay(1000 / 30 - (SDL_GetTicks() - time));
    }

    return 0;
}


int SDLCommonFunc::Random_(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

bool SDLCommonFunc::Collision(const SDL_Rect& Obj1, const SDL_Rect& Obj2) 
{
  int left_a = Obj1.x;
  int right_a = Obj1.x + Obj1.w;
  int top_a = Obj1.y;
  int bottom_a = Obj1.y + Obj1.h;

  int left_b = Obj2.x;
  int right_b = Obj2.x + Obj2.w;
  int top_b = Obj2.y;
  int bottom_b = Obj2.y + Obj2.h;

// AABB collision
  if (top_b < bottom_a && (left_b < right_a) && (right_b > left_a) && (bottom_b > top_a)) return true;
  else return false;
}

