
#include "newMessage.h"


newMessage::newMessage() :
m_id(SpriteID::new_message),
m_pass("new_message.png")
{
    
    extern ci::fs::path getDocumentPath();
    ci::fs::path Path = getDocumentPath();
    JsonTree ex_json;
  
    if(ci::fs::is_regular_file(Path / "Message.json")){
        
        JsonTree ex_json = JsonTree(loadFile(Path / "Message.json"));
        
        is_create_newmessage = ex_json["Message.unread"].getValue<bool>();
        
    }
    else{
        ex_json = ci::JsonTree::makeObject(("Message"));
        ex_json.addChild(JsonTree("unread",false));
        is_create_newmessage = false;
        ex_json.write(Path / "Message.json",JsonTree::WriteOptions().createDocument(true));
    }

    resourceManage::getinstace().add(m_id,m_pass);
    m_texture =resourceManage::getinstace().getsprite(m_id);
    defalt_size = Area(0,0,newMessageW,newMessageH);
    re_size = Area (-getWindowWidth() * 0.5 + 10, -getWindowHeight() / 5,
                    newMessageResizeW　+ (-getWindowWidth() * 0.5) + 10,newMessageResizeH + (-getWindowHeight() / 5));
    
    alpfa = 1;
}


newMessageSP newMessage::create(){
    newMessageSP obj = newMessageSP(new newMessage());
    obj->m_object_id = ObjectID::New_Message;
    
    object::m_objects.push_back(obj);
}

void newMessage::checkCreateMessage(){
    int turn =  ((*object::earth_date())->m_rotation /360);
    
    if(turn == 10){ is_create_newmessage = true; saveUnreadMessage();}
    if(turn == 20){ is_create_newmessage = true; saveUnreadMessage();}
    if(turn == 30){ is_create_newmessage = true; saveUnreadMessage();}
    if(turn == 40){ is_create_newmessage = true; saveUnreadMessage();}
    if(turn == 50){ is_create_newmessage = true; saveUnreadMessage();}
    if(turn == 60){ is_create_newmessage = true; saveUnreadMessage();}
    
    
    extern ci::fs::path getDocumentPath();
    ci::fs::path Path = getDocumentPath();
    JsonTree ex_json;
    if(ci::fs::is_regular_file(Path / "Message.json")){
        JsonTree ex_json = JsonTree(loadFile(Path / "Message.json"));
        is_create_newmessage = ex_json["Message.unread"].getValue<bool>();
        
    }

}

void newMessage::saveUnreadMessage(){
    extern ci::fs::path getDocumentPath();
    ci::fs::path Path = getDocumentPath();
    JsonTree ex_json;
    
    if(ci::fs::is_regular_file(Path / "Message.json")){
        ex_json = ci::JsonTree::makeObject(("Message"));
        ex_json.addChild(JsonTree("unread",true));
        ex_json.write(Path / "Message.json",JsonTree::WriteOptions().createDocument(true));
    }

}

void newMessage::update(){
    animation_count += 0.05f;
    alpfa = 1.5 - std::abs(sin(animation_count));
    checkCreateMessage();
}
void newMessage::draw(){
    if(is_create_newmessage){
    gl::pushModelView();
    gl::color(ColorA(1,1,1,alpfa));
    gl::translate(1,1,1);
    gl::rotate(Vec3f(std::abs(sin(animation_count)) * 5,10,0));
    gl::scale(1,1,1);
    gl::draw(m_texture,defalt_size,re_size);
    gl::popModelView();
    }
}
