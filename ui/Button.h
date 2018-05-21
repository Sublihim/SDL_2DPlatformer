#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <SDL2/SDL.h>
#include <string>
#include <memory>
#include "../utils/SPointerStrategy.h"
#include "FontMgr.h"

namespace ui {

class Button : public utils::Creator<Button>
{
private:
    std::string s_caption;
    SDL_Rect btn;
    FontMgrPtr font_caption {nullptr};
    SDL_Color font_color;
    int font_margin_left_right;
    int font_margin_up_dowm;
public:
    Button();
    ~Button();
    void setCaption(std::string caption);
    void setPosition(int x, int y);
    void setSize(int w, int h);
    bool checkHover(int x, int y);
    void draw(SDL_Renderer *renderer);
};

using ButtonPtr = std::shared_ptr<Button>;

} // namespace ui

#endif // BUTTON_H_INCLUDED
