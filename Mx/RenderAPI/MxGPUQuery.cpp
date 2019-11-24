#include "MxGPUQuery.h"
#include "MxGPUQueryManager.h"

namespace Mix {

    std::shared_ptr<GPUTimeQuery> GPUTimeQuery::Create() {
        return GPUQueryManager::Get()->createTimeQuery();
    }

    std::shared_ptr<GPUEventQuery> GPUEventQuery::Create() {
        return GPUQueryManager::Get()->createEventQuery();
    }
}
