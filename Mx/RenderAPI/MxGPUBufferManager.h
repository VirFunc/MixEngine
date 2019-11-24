#pragma once
#ifndef MX_GPU_BUFFER_MANAGER_H_
#define MX_GPU_BUFFER_MANAGER_H_

#include <memory>
#include "../Definitions/MxTypes.h"
#include "MxGPUParamBlockBuffer.h"
#include "../Engine/MxModuleBase.h"

namespace Mix {

    class VertexBuffer;
    struct VertexBufferDesc;
    class IndexBuffer;
    struct IndexBufferDesc;
    class GPUBuffer;
    struct GPUBufferDesc;
    class GPUParamBlockBuffer;


    class GPUBufferManager :public TModule<GPUBufferManager> {
    public:
        ~GPUBufferManager() = default;

        virtual std::shared_ptr<VertexBuffer> createVertexBuffer(const VertexBufferDesc* _desc) = 0;

        virtual std::shared_ptr<IndexBuffer> createIndexBuffer(const IndexBufferDesc& _desc) = 0;

        virtual std::shared_ptr<GPUBuffer> createGPUBuffer(const GPUBufferDesc& _desc) = 0;

        virtual std::shared_ptr<GPUParamBlockBuffer> createGPUParamBlockBuffer(uint32 _size, GPUBufferUsage _usage) = 0;

    };
}

#endif
