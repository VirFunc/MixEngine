#pragma once
#ifndef MX_GPU_QUERY_MANAGER_H_
#define MX_GPU_QUERY_MANAGER_H_
#include <memory>
#include "../Engine/MxModuleBase.h"


namespace Mix {

    class GPUEventQuery;
    class GPUTimeQuery;

    class GPUQueryManager :public TModule<GPUQueryManager> {
    public:

        virtual std::shared_ptr<GPUEventQuery> createEventQuery() const = 0;

        virtual std::shared_ptr<GPUTimeQuery> createTimeQuery() const = 0;

    };
}

#endif
