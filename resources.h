#pragma once
#include "common.h"
#include "cinder/Surface.h"
#include "cinder/ip/Resize.h"
#include <map>

enum SpriteID{
    fade,
    main_bg,
    kobito_s00,
    kobito_m00,
    kobito_l00,
    kobito_icon,
    new_message,
    message_icon,
    message_base,
    message_00,
    message_01,
    message_02,
    message_03,
    message_04,
    message_05,
    message_06,

    summons_circle,
    tikyu,
    title_0,
    title_1,
    title_2,
    title_3,
    title_4,
    title_5,
    number,
    menuicon,
    closeicon,
    
    introdaction_0,
    introdaction_1,
    introdaction_2,
    introdaction_3,
    tutorial_0,
    tutorial_1,
    tutorial_2,
    tutorial_3,
    tutorial_4,
    tutorial_end,
    
    
    ALL_sprite,
};

/*struct spriteInfo{
    SpriteID m_id;
    std::string m_pass;
};*/

class resourceManage{
private:
    
    resourceManage();
    std::map<SpriteID, gl::Texture> m_graph;//:キーを指定、テクスチャを保持
    
public:
    
    //画像情報宣言用の変数.
    Surface mSurfaceComposite;
    SpriteID m_id;
    std::string m_pass;
    
    static resourceManage& getinstace();
    void add(const SpriteID&,const std::string&);
    void add(const SpriteID&,const std::string&,
             const Area usearea,const Area posarea);

    void remove(const SpriteID);
    void clear();
    
   gl::Texture getsprite(const SpriteID);
    
    
};

