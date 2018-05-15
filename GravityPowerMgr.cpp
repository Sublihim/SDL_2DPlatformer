#include "GravityPowerMgr.h"
#include "MainConstants.h"
#include <math.h>
#include <iostream>

GravityPowerMgr::GravityPowerMgr()
{
    cur_step = 0;

    p_begin_position.x = 0;
    p_begin_position.y = 0;

    p_cur_position.x = 0;
    p_cur_position.y = 0;

    angle = 0;
    sina = 0;
    cosa = 1;


    delta_t = 0;
    speed = 0;

    g = -9.81;
}

GravityPowerMgr::~GravityPowerMgr()
{

}

void GravityPowerMgr::setBeginPoint(int x, int y)
{
    p_begin_position.x = x;
    p_begin_position.y = y;  
    p_cur_position.x = x;
    p_cur_position.y = y;
}

void GravityPowerMgr::setSpeed(int v)
{
    speed = v;
}

void GravityPowerMgr::setAngle(int a)
{
    angle = a;
    sina = sin(angle * PI_by_180);
    cosa = cos(angle * PI_by_180);
}

void GravityPowerMgr::setTimeStep(float dt)
{
    if(dt < 0)
        dt = 0;
    delta_t = dt;
}

void GravityPowerMgr::setAccelOfGravity(float ag)
{
    if(ag < 0)
        ag = 0;
    g = ag;
}

void GravityPowerMgr::resetStep()
{
    cur_step = 0;
}

SDL_Point GravityPowerMgr::affectWithGravityPower(int step)
{
    float t;
    if(step > -1)
        t = delta_t * step;
    else
    {
        t = delta_t * cur_step;
        cur_step++;
    }

    p_cur_position.x = p_begin_position.x + speed * t * cosa;
    p_cur_position.y = p_begin_position.y + speed * t * sina - g * t * t / 2;

    return p_cur_position;
}
