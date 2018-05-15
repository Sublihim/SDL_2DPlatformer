#ifndef GRAVITYPOWERMGR_H
#define GRAVITYPOWERMGR_H

#include <SDL2/SDL.h>

class GravityPowerMgr
{
private:
    SDL_Point p_cur_position;
    SDL_Point p_begin_position;

    int angle;
    float sina, cosa;

    int speed;
    int cur_step;
    float g, delta_t;
public:
    GravityPowerMgr();
    ~GravityPowerMgr();
    void setBeginPoint(int x, int y);
    void setSpeed(int v);
    void setAngle(int a);
    void setTimeStep(float dt);
    void setAccelOfGravity(float ag);
    void resetStep();
    SDL_Point affectWithGravityPower(int step = -1);
};

#endif // GRAVITYPOWERMGR_H
