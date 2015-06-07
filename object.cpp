
#include "object.h"
#include "kobito_00.h"
#include "kobito_M00.h"
#include "kobito_L00.h"
#include "cinder/Rand.h"
std::list<objectSP>object::m_objects;
object::object(): m_life(-1),m_condition(-1),m_rote_power(.0f),m_rotation(0),m_object_id(ObjectID::Null_object)
{
    
 
}


void object::shutdown(){
   
    extern ci::fs::path getDocumentPath();
    ci::fs::path Path = getDocumentPath();
    ci::JsonTree ex_json[3];
    
    int kobito_s_count = 0;
    int kobito_m_count = 0;
    int kobito_l_count = 0;
    
    if(ci::fs::is_regular_file(Path / "Kobito_s.json") &&
       ci::fs::is_regular_file(Path / "Kobito_m.json") &&
       ci::fs::is_regular_file(Path / "Kobito_l.json")){
        
        ex_json[0] = JsonTree(loadFile(Path / "Kobito_s.json"));
        ex_json[1] = JsonTree(loadFile(Path / "Kobito_m.json"));
        ex_json[2] = JsonTree(loadFile(Path / "Kobito_l.json"));
        
    }
    else{
        ex_json[0].write(Path / "Kobito_s.json",JsonTree::WriteOptions().createDocument(true));
        ex_json[1].write(Path / "Kobito_m.json",JsonTree::WriteOptions().createDocument(true));
        ex_json[2].write(Path / "Kobito_l.json",JsonTree::WriteOptions().createDocument(true));


    }

    ex_json[0] = JsonTree::makeObject("Kobito_s00");
    ex_json[1] = JsonTree::makeObject("Kobito_m00");
    ex_json[2] = JsonTree::makeObject("Kobito_l00");

    
    std::list<objectSP>::iterator it = m_objects.begin();
    while(it != m_objects.end()){
        //オブジェクトが小人だったら、データを保存。
        if(ObjectID::Kobito_s00 == (*it)->m_object_id){
            
            ex_json[0].pushBack(JsonTree(toString(kobito_s_count),(*it)->m_condition));
           
            kobito_s_count++;
        }
        else if(ObjectID::Kobito_m00 == (*it)->m_object_id){
            
            ex_json[1].pushBack(JsonTree(toString(kobito_m_count),(*it)->m_condition));
            
            kobito_m_count++;
        }
        else  if(ObjectID::Kobito_l00 == (*it)->m_object_id){
            
            ex_json[2].pushBack(JsonTree(toString(kobito_l_count),(*it)->m_condition));
            
            kobito_l_count++;
        }


        //次のオブジェクト.
        it++;
    }
    
    //小人＿Sの残存数を参照する用のデータを用意.0を1体をカウントするので１を引いた数を保存.
    ex_json[0].addChild(JsonTree("kobito_s_count",kobito_s_count - 1));
    ex_json[1].addChild(JsonTree("kobito_m_count",kobito_m_count - 1));
    ex_json[2].addChild(JsonTree("kobito_l_count",kobito_l_count - 1));
    
    ex_json[0].write(Path / "Kobito_s.json",JsonTree::WriteOptions().createDocument(true));
    ex_json[1].write(Path / "Kobito_m.json",JsonTree::WriteOptions().createDocument(true));
    ex_json[2].write(Path / "Kobito_l.json",JsonTree::WriteOptions().createDocument(true));
    

}

//いきのこっていた小人を再度表示
void object::survivor_kobitocreate(){
    
    extern ci::fs::path getDocumentPath();
    ci::fs::path Path = getDocumentPath();
    JsonTree ex_json;
    
    //小人Sを確認.
    if(ci::fs::is_regular_file(Path / "Kobito_s.json")){
      
       ex_json   = JsonTree(loadFile(Path/ "Kobito_s.json"));
        
    //  if(ex_json.hasChild("Kobito_s00")){
          
          int kobito_s_count = ex_json["Kobito_s00"]["kobito_s_count"].getValue<int>();
          for(int i = 0; i <= kobito_s_count; i++){
            kobito_00::create(Vec2f(randFloat(-150,150),randFloat(0,200)),ex_json["Kobito_s00"][toString(i)].getValue<int>());
          }
      }
   // }
    //小人M
    if(ci::fs::is_regular_file(Path / "Kobito_m.json")){

      ex_json   = JsonTree(loadFile(Path/ "Kobito_m.json"));

      if(ex_json.hasChild("Kobito_m00")){
          
        int kobito_m_count = ex_json["Kobito_m00"]["kobito_m_count"].getValue<int>();
          
        for(int i = 0; i <= kobito_m_count; i++){
            kobito_M00::create(Vec2f(randFloat(-150,150),randFloat(0,200)),ex_json["Kobito_m00"][toString(i)].getValue<int>());
        }
      }
    }
    //小人L
    if(ci::fs::is_regular_file(Path / "Kobito_l.json")){

      ex_json   = JsonTree(loadFile(Path/ "Kobito_l.json"));

      if(ex_json.hasChild("Kobito_l00")){
          
        int kobito_l_count = ex_json["Kobito_l00"]["kobito_l_count"].getValue<int>();
        for(int i = 0; i <= kobito_l_count; i++){
            kobito_L00::create(Vec2f(randFloat(-150,150),randFloat(0,200)),ex_json["Kobito_l00"][toString(i)].getValue<int>());
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



