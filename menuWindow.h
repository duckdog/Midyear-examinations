#pragma once
#include "common.h"
#include "resources.h"


class menuWindow;
typedef std::unique_ptr<menuWindow> menuWindowSP;

class menuWindow{
public:
    menuWindow();
    ~menuWindow(){}
    
    void normaldraw(bool falseis_menu_png_trueis_close_png,Vec3f translate,Vec3f scale);
    void draw(bool falseis_menu_png_trueis_close_png);
    void update();
 
    
    void touchesBegan(TouchEvent event,Vec3f translate,Vec3f scale);
    void touchesBegan(TouchEvent event);
    void touchesMoved(TouchEvent event);
    void touchesEnded(TouchEvent event);
    bool changescene();
private:
    int touch_count;
    float effect_count;
    Vec2f m_touch_starting_pos;
    Vec3f m_pos[2];
    float rx,ry,rz;
    Vec3f m_scale;
    Vec3f m_tgt_scale;
    const SpriteID m_id[2];
    const std::string m_pass[2];
    
    bool is_changescene;
    bool is_touch;
    bool is_touchmove;
    bool is_close;
};