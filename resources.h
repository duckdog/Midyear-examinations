#pragma once
#include "common.h"
#include "cinder/Surface.h"
#include "cinder/ip/Resize.h"
#include <map>

enum SpriteID{
    Player,
    main_bg,//
    kobito_s00,
    Mahojin,
    
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

