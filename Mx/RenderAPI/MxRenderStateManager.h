#pragma once
#ifndef MX_RENDER_STATE_MANAGER_H_
#define MX_RENDER_STATE_MANAGER_H_
#include "../Engine/MxModuleBase.h"


namespace Mix {
    class GPUPipelineParamsInfo;
    class GPUParams;
    class GraphicsPipelineState;
    struct GraphicsPipelineStateDesc;
    struct GraphicsParamsDesc;
    struct ComputeParamsDesc;

    class RenderStateManager :public TModule<RenderStateManager> {
    public:
        RenderStateManager() = default;

        virtual std::shared_ptr<GPUPipelineParamsInfo> createGPUPipelineParamsInfo(const GraphicsParamsDesc& _desc) const;

        virtual std::shared_ptr<GPUPipelineParamsInfo> createGPUPipelineParamsInfo(const ComputeParamsDesc& _desc) const;

        virtual std::shared_ptr<GPUParams> createGPUParams(const std::shared_ptr<GPUPipelineParamsInfo>& _info) const;

        virtual std::shared_ptr<GraphicsPipelineState> createGraphicsPipelineState(const GraphicsPipelineStateDesc& _desc);

    private:

    };
}

#endif
