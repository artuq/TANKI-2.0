#include "mine.h"
#include "../../appconfig.h"

Mine::Mine(double x, double y)
    : Object(x, y, ST_BRICK), m_timer(0), m_state(MineState::INACTIVE)
{
    m_time_to_arm = AppConfig::mine_cooldown;
    dest_rect = { (int)pos_x, (int)pos_y, AppConfig::tile_size.w, AppConfig::tile_size.h };
    collision_rect = dest_rect;
    to_erase = false;
}

Mine::~Mine() {}

void Mine::update(Uint32 dt)
{
    if (to_erase) return;
    m_timer += dt;
    if (m_state == MineState::INACTIVE && m_timer >= m_time_to_arm)
    {
        m_state = MineState::ARMED;
    }
    dest_rect.x = (int)pos_x;
    dest_rect.y = (int)pos_y;
    collision_rect = dest_rect;
}

void Mine::draw(Renderer &renderer)
{
    if (to_erase) return;
    if (m_state == MineState::ARMED)
        renderer.drawRect(dest_rect, {200, 30, 30, 255}, true);
    else
        renderer.drawRect(dest_rect, {120, 120, 120, 255}, true);
}

bool Mine::isArmed() const { return m_state == MineState::ARMED; }

void Mine::explode()
{
    m_state = MineState::EXPLODED;
    to_erase = true;
}
