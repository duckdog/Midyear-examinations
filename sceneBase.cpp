#include "sceneBase.h"
#include "sceneManage.h"
#include "object.h"
sceneBase::sceneBase(std::shared_ptr<sceneManage> manager,
                     std::shared_ptr<object> objects) :
m_manage(manager),
m_obj(objects){
    
}