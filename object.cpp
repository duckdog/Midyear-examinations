
#include "object.h"
#include "kobito_00.h"
#include "cinder/Rand.h"
std::list<objectSP>object::m_objects;
object::object(): m_life(-1),m_condition(-1),m_rote_power(.0f),m_rotation(0),m_object_id(ObjectID::Null_object){}


void object::shutdown(){
   
    extern ci::fs::path getDocumentPath();
    ci::fs::path Path = getDocumentPath();
    ci::JsonTree ex_json;
    
    int kobito_s_count = 0;
    
    if(ci::fs::is_regular_file(Path / "Kobito.json")){
        ex_json = JsonTree(loadFile(Path / "Kobito.json"));
    }
    else{
        ex_json.write(Path / "Kobito.json",JsonTree::WriteOptions().createDocument(true));

    }

    ex_json = JsonTree::makeObject("Kobito_s00");
    
    std::list<objectSP>::iterator it = m_objects.begin();
    while(it != m_objects.end()){
        //オブジェクトが小人だったら、データを保存。
        if(ObjectID::Kobito_s00 == (*it)->m_object_id){
            
            ex_json.pushBack(JsonTree(toString(kobito_s_count),(*it)->m_condition));
           
            kobito_s_count++;
        }
        //次のオブジェクト.
        it++;
    }
    
    //小人＿Sの残存数を参照する用のデータを用意.
    ex_json.addChild(JsonTree("kobito_s_count",kobito_s_count - 1));
    ex_json.write(Path / "Kobito.json",JsonTree::WriteOptions().createDocument(true));

}

//いきのこっていた小人を再度表示
void object::survivor_kobitocreate(){
    
    extern ci::fs::path getDocumentPath();
    ci::fs::path Path = getDocumentPath();
    
    if(ci::fs::is_regular_file(Path / "Kobito.json")){
      
      JsonTree ex_json   = JsonTree(loadFile(Path/ "Kobito.json"));
        
      if(ex_json.hasChild("Kobito_s00")){
          
          int kobito_s_count = ex_json["Kobito_s00"]["kobito_s_count"].getValue<int>();
          for(int i = 0; i < kobito_s_count; i++){
            kobito_00::create(Vec2f(randFloat(-100,100),randFloat(-100,100)),ex_json["Kobito_s00"][toString(i)].getValue<int>());
          }
    }
    }
}

std::list<objectSP>::iterator object::earth_date(){
    
    std::list<objectSP>::iterator it = m_objects.begin();
    return (it);
}
void object::exUpdate(){
    std::list<objectSP>::iterator it = m_objects.begin();
    
    
    while(it != m_objects.end()){
        //lifeが0のオブジェクトを消去。
        if(0 == (*it)->m_life){
            it = m_objects.erase(it);
            continue;
        }
        
        //update 実行.
        (*it)->update();
                it++;
    }
}

void object::exDraw(){
    
    std::list<objectSP>::iterator it = m_objects.begin();
    
    while(it != m_objects.end()){
        //draw実行.
        (*it)->draw();
        //次のオブジェクトへ.
        it++;
    }
    
}

void object::exTouchesBegan(TouchEvent event){
    
    std::list<objectSP>::iterator it = m_objects.begin();
    
    while(it != m_objects.end()){
        //touchesBegan実行.
        (*it)->touchesBegan(event);
        //次のオブジェクトへ.
        it++;
    }
    
}

void object::exTouchesMoved(TouchEvent event){
    
    std::list<objectSP>::iterator it = m_objects.begin();
    
    while(it != m_objects.end()){
        //touchevent実行.
        (*it)->touchesMoved(event);
        
        
        //次のオブジェクトへ.
        it++;
    }
    
}
void object::exTouchesEnded(TouchEvent event){
    
    std::list<objectSP>::iterator it = m_objects.begin();
    
    while(it != m_objects.end()){
        //touchevent実行.
        (*it)->touchesEnded(event);
        //次のオブジェクトへ.
        it++;
    }
    
}

//一応用意。つかわないかも？
void object::destroy(){
    std::list<objectSP>::iterator it = m_objects.begin();
    while(it != m_objects.end()){
                it++;
    }
    m_objects.clear();
}



