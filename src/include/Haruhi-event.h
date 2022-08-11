/**
 * @file event.h
 * @author GongZian (https://github.com/Zian-Andrew-GONG)
 * @brief This is the header file which lasses 
 *        and functions related to abstract events.
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>

#pragma once

namespace Haruhi {

class Loop;

struct EventOps {
  bool once = false;
};

class Event {
  public:
    virtual ~Event() = default;
    // virtual void init(std::shared_ptr<EventOps> ops) = 0;
    /* 返回值显示是否重新加入堆或队列 */
    virtual bool callback() = 0;
    virtual std::string type() const = 0;
};

}