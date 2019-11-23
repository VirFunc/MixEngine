#include "MxGPUParamBlockBuffer.h"
#include "../Definitions/MxDefinitions.h"
#include "../Log/MxLog.h"
#include "MxGPUBuffer.h"

namespace Mix {

    GPUParamBlockBuffer::GPUParamBlockBuffer(uint32 _size, GPUBufferUsage _usage) :
        mUsage(_usage), mSize(_size), mBuffer(nullptr) {
        MX_ASSERT(_size > 0 && "Size of param block buffer should be positive");

        mCachedBuffer = new std::byte[mSize];
        clear();
    }

    void GPUParamBlockBuffer::getData(void* _dst, uint32_t _offset, uint32_t _size) const {
        MX_ASSERT(_dst && "Destination buffer CAN NOT be NULL");

#   ifdef MX_DEBUG_MODE

        if (_offset + _size > mSize) {
            MX_LOG_ERROR("GPU parameter block buffer out of range");
            return;
        }

#   endif

        memcpy(static_cast<std::byte*>(_dst) + _offset, mCachedBuffer, _size);
    }

    void GPUParamBlockBuffer::setData(void const* const _src, uint32_t _offset, uint32_t _size) {
        MX_ASSERT(_src && "Source buffer CAN NOT be NULL");

#   ifdef MX_DEBUG_MODE

        if (_offset + _size > mSize) {
            MX_LOG_ERROR("GPU parameter block buffer out of range");
            return;
        }

#   endif

        memcpy(static_cast<std::byte*>(mCachedBuffer) + _offset, _src, _size);
        markDirty();
    }

    void GPUParamBlockBuffer::setZero(uint32 _offset, uint32 _size) {
#   ifdef MX_DEBUG_MODE

        if (_offset + _size > mSize) {
            MX_LOG_ERROR("GPU parameter block buffer out of range");
            return;
        }

#   endif

        memset(mCachedBuffer + _offset, 0, _size);
        markDirty();
    }

    void GPUParamBlockBuffer::flushToGPU(uint32 _queueIdx) {
        mBuffer->setData(mCachedBuffer, 0, mSize, _queueIdx);
        mDirty = false;
    }

    std::shared_ptr<GPUParamBlockBuffer> GPUParamBlockBuffer::Create(uint32 _size, GPUBufferUsage _usage) {
        // TODO Implement this after GPUBufferManager finished
    }
}
