
#include "kobito_L00.h"
#include "cinder/Rand.h"
#include "timeManage.h"

#include <vector>
kobito_L00::kobito_L00() :
m_id(SpriteID::kobito_l00),m_pass(("kobito_L00.png")),
alpfa(0)
{
    // 出力デバイスをゲット
    auto ctx = audio::Context::master();
    
    // オーディオデータを読み込んで初期化
    audio::SourceFileRef sourceFile = audio::load(loadAsset("create.wav"));
    audio::BufferRef buffer =sourceFile->loadBuffer();
    mBufferPlayerNode= ctx->makeNode(new audio::BufferPlayerNode(buffer));
    
    gain = ctx->makeNode(new audio::GainNode(0.3f));
    // 読み込んだオーディオを出力デバイスに関連付けておく
    mBufferPlayerNode >> gain >> ctx->getOutput();
    //gain >> ctx->getOutput();
    //gain >> ctx->getOutput();
    
    is_play = false;
    // 出力デバイスを有効にする
    ctx->enable();
}

kobito_L00SP kobito_L00::create(Vec2f touchpos){
    
    
    if((object::m_objects.size() - 2) < 50){
        kobito_L00SP obj = kobito_L00SP(new kobito_L00());
        
        resourceManage::getinstace().add(obj->m_id,obj->m_pass);
        obj->m_object_id      = ObjectID::Kobito_l00;
        obj->m_rote_power     = 0.01f;
        obj->ry               = 0;
        obj->m_condition      = 60 * 60;
        obj->random_dir       = randBool();
        obj->obj_number       = 0 + (object::m_objects.size() - 2); //召喚円と地球分を引いた数。
        obj->m_color          = Color(1,1,1);
        obj->m_animationframe = 0;
        obj->m_pos            = touchpos - Vec2f(kobito_L00Resize * 0.5, kobito_L00Resize );
        obj->m_resize         = Area(obj->m_pos.x,obj->m_pos.y,
                                     kobito_L00Resize + obj->m_pos.x,kobito_L00Resize + obj->m_pos.y);
        obj->move_interval  = randInt(0,60);
        
        
        object::m_objects.push_back(obj);
        
        return obj;
    }
    
    return nullptr;
    
}
kobito_L00SP kobito_L00::create(Vec2f pos,int condition){
    
    kobito_L00SP obj = kobito_L00SP(new kobito_L00());
    
    obj->m_object_id    = ObjectID::Kobito_l00;
    obj->m_rote_power   = 0.01f;
    obj->ry             = 0;
    obj->m_condition    = 60 * 60;
    obj->random_dir     = randBool();
    obj->obj_number     = 0 + (object::m_objects.size() - 2); //召喚円と地球分を引いた数。
    obj->m_color        = Color(1,1,1);
    obj->m_animationframe = 0;
    obj->m_pos          = Vec2f(pos);
    resourceManage::getinstace().add(obj->m_id,obj->m_pass);
    obj->m_resize       = Area(obj->m_pos.x,obj->m_pos.y,
                               kobito_L00Resize + obj->m_pos.x,kobito_L00Resize + obj->m_pos.y);
    
    obj->move_interval  = randInt(0,60);
    object::m_objects.push_back(obj);
    
    
    return obj;
}


void kobito_L00::update(){
    
    //
    //   animatons
    //   移動、画像アニメーション等
    //
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(alpfa <= 1) alpfa += 0.045f;
    for(int i = 0; i <= timeManage::getInstance().gaptime * 60; i++ ){
        
        m_condition--;
        
        //地球にrotation.
        std::list<objectSP>::iterator it = m_objects.begin();
        (*it)->m_rotation += m_rote_power;
        
        
        if(m_condition <= 0){
            m_condition  = 0;
            m_rote_power = 0;
            break;
        }
    }
    //移動設定
    if(  m_pos.y >= 0 + obj_number && m_condition != 0) m_pos.y--;
    // 画面内を左右に移動。
    if(m_pos.x >= -getWindowWidth() * 0.5 && m_pos.x <= getWindowWidth() * 0.5 - kobito_L00Resize
       && m_condition != 0){
        
        if(m_animationframe == 0){
            random_dir = randBool();
            move_interval = randInt(-20,60);
        }
        else if(m_animationframe < 30 + move_interval){
            if(random_dir) m_pos.x += 1;
            else m_pos.x -= 1;
        }
    }
    //画面外に出たら、画面内に強制的に戻す.
    if(m_pos.x < -getWindowWidth() * 0.5) m_pos.x =  -getWindowWidth() * 0.5;
    if(m_pos.x > getWindowWidth() * 0.5 - kobito_L00Resize) m_pos.x = getWindowWidth() * 0.5 - kobito_L00Resize;
    
    //小人画像のアニメーション
    m_animationframe++;
    
    if(random_dir && m_condition > 0){
        if((m_animationframe / 10) % 2 == 0){
            m_default_size = Area(0 + kobito_L00W,0,kobito_L00W * 2,kobito_L00H);
        }
        else{
            m_default_size = Area(0,0,kobito_L00W,kobito_L00H);
        }
    }else if(!random_dir && m_condition > 0){
        if((m_animationframe / 10) % 2 == 0){
            m_default_size = Area(0 + kobito_L00W,kobito_L00H,kobito_L00W * 2,kobito_L00H * 2);
        }
        else{
            m_default_size = Area(0,kobito_L00H,kobito_L00W,kobito_L00H * 2);
        }
    }else{
        if((m_animationframe / 30) % 2 == 0){
            m_default_size = Area(0 + kobito_L00W,kobito_L00H * 2,kobito_L00W * 2,kobito_L00H *  3);
        }
        else{
            m_default_size = Area(0,kobito_L00H * 2,kobito_L00W,kobito_L00H * 3);
        }
        
    }
    
    //アニメーションカウントが増えすぎるを防止.
    if(m_animationframe > 60) m_animationframe = 0;
    
    
}

void kobito_L00::draw(){
    gl::pushModelView();
    gl::color(ColorA(1,1,1,alpfa));
    m_resize = Area(m_pos.x,m_pos.y,kobito_L00Resize + m_pos.x,kobito_L00Resize + m_pos.y);
    gl::draw(resourceManage::getinstace().getsprite(m_id),m_default_size,m_resize);
    
    gl::popModelView();
}



void kobito_L00::touchesBegan(TouchEvent event){
    //vector 型だったので、タッチイベントの要素（関数）を取り出すために　touchIter を作成。かな？
    for (std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
         touchIter != event.getTouches().end();
         touchIter++) {
        
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
        
        //取得したタッチ位置とオブジェクトの位置の当たり判定,
        //オブジェクトの領域にはいっていればremove.
        if(TouchPos.x > m_pos.x && TouchPos.x < m_pos.x + kobito_L00Resize &&
           TouchPos.y > m_pos.y && TouchPos.y < m_pos.y + kobito_L00Resize){
            
            
        }
    }
    
    
}

void kobito_L00::touchesMoved(TouchEvent event){
    for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
        
        if(TouchPos.x > m_pos.x && TouchPos.x < m_pos.x + kobito_L00Resize &&
           TouchPos.y > m_pos.y && TouchPos.y < m_pos.y + kobito_L00Resize){
            
            if(m_condition == 0){
                mBufferPlayerNode->start();
                m_life = 0;
            }
            
            // object::remove();
        }
        
        
    }
}
