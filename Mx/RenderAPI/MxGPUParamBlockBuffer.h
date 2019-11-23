#pragma once
#ifndef MX_PARAM_BLOCK_BUFFER_H_
#define MX_PARAM_BLOCK_BUFFER_H_
#include "../Definitions/MxTypes.h"
#include "MxGPUProgram.h"

namespace Mix {

    class GPUBuffer;

    /**
     * \brief A buffer that contains a parameter block used to send parameters to GPU program.
     *
     * \note All access operations will be performed on a cached CPU buffer first and will be send to GPU before rendering begin.
     */
    class GPUParamBlockBuffer {
    public:
        void getData(void* _dst, uint32_t _offset, uint32_t _size) const;

        void setData(void const * const _src, uint32_t _offset, uint32_t _size);

        /** \brief Clear the cached buffer. Buffer in range will be set to 0. */
        void setZero(uint32 _offset, uint32 _size);

        /** \brief Clear whole buffer to 0. */
        void clear() { setZero(0, mSize); }

        uint32 size() const { return mSize; }

        std::byte* data() const { return mCachedBuffer; }

        bool dirty() const { return mDirty; }

        /**
         * \brief Flush all cached data to GPU buffer.
         *
         * \note Manual use of this operation is not recommended, if you do, the synchronization will be up to you.
         */
        void flushToGPU(uint32 _queueIdx);

        static std::shared_ptr<GPUParamBlockBuffer> Create(uint32 _size, GPUBufferUsage _usage);

    protected:
        GPUParamBlockBuffer(uint32 _size, GPUBufferUsage _usage);

        void markDirty() { mDirty = false; }

        GPUBufferUsage mUsage;
        std::byte* mCachedBuffer;
        bool mDirty = false;
        uint32 mSize;
        std::shared_ptr<GPUBuffer> mBuffer;
    };

}

#endif
