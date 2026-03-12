#ifndef TANK_MINE_H
#define TANK_MINE_H

#include "../object.h"
#include "../../engine/renderer.h"

enum class MineState { INACTIVE, ARMED, EXPLODED };

class Mine : public Object
{
public:
    Mine(double x, double y);
    ~Mine();

    void update(Uint32 dt) override;
    void draw(Renderer &renderer) override;

    bool isArmed() const;
    void explode();
private:
    Uint32 m_timer; // ms from placement
    MineState m_state;
    Uint32 m_time_to_arm; // ms
};

#endif // TANK_MINE_H
