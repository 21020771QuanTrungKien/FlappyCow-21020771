#include "BaseObj.h"
BaseObj::BaseObj()
{
    p_Obj_ = NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 0;
    rect_.h = 0;
}

BaseObj::~BaseObj()
{
    Free();
}

bool BaseObj::LoadImageFile(std::string path, SDL_Renderer* screen)
{
    Free();
    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface != NULL)
    {  
        Uint32 key = SDL_MapRGB(loadedSurface->format,
                                COLOR_KEY_R,
                                COLOR_KEY_G,
                                COLOR_KEY_B);
        SDL_SetColorKey(loadedSurface, SDL_TRUE, key);

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);
        if (newTexture != NULL)
        {
            //Get image dimensions
            rect_.w = loadedSurface->w;
            rect_.h = loadedSurface->h;
        }

        SDL_FreeSurface(loadedSurface);
    }

    p_Obj_ = newTexture;
    return p_Obj_ != NULL;
}

void BaseObj::Free()
{
    if (p_Obj_ != NULL)
    {
        SDL_DestroyTexture(p_Obj_);
        p_Obj_ = NULL;
        rect_.w = 0;
        rect_.h = 0;
    }
}

void BaseObj::Render(SDL_Renderer* des, const SDL_Rect* clip )
{
    SDL_Rect renderQuad = { rect_.x, rect_.y, rect_.w, rect_.h };
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopy(des, p_Obj_, clip, &renderQuad);
}