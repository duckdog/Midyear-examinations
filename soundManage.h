#include "common.h"

#include "cinder/audio/Context.h"
#include "cinder/audio/SamplePlayerNode.h"
#include "cinder/audio/NodeEffects.h"


enum SoundID{
    test,
    
    All_sound,
};



class soundManage{
private:
    
    soundManage();
  //  std::map<SoundID, mBufferPlayerNode> m_sound;//:キーを指定、テクスチャを保持
    
public:
    
    
    
    static soundManage& getinstace();
    void add(const SoundID&,const std::string&);
    
    void remove(const SoundID);
    void clear();
    
    gl::Texture getsprite(const SoundID);
    
    
};

