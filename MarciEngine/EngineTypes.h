#pragma once

#include <memory>

class EntityBase;

typedef std::shared_ptr<EntityBase> Entity;
typedef std::weak_ptr<EntityBase> EntityPtr;
