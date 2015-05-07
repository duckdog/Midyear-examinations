#include "sceneBase.hpp"
#include "sceneManage.hpp"

sceneBase::sceneBase(std::shared_ptr<sceneManage> manager){
    m_manage = manager;
}