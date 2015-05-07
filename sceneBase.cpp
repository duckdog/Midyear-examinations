#include "sceneBase.h"
#include "sceneManage.h"

sceneBase::sceneBase(std::shared_ptr<sceneManage> manager){
    m_manage = manager;
}