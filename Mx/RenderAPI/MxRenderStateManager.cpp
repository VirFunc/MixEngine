#include "MxRenderStateManager.h"
#include "../../MixEngine.h"
#include "MxGPUParams.h"

namespace Mix {
    std::shared_ptr<GPUPipelineParamsInfo> RenderStateManager::createGPUPipelineParamsInfo(const GraphicsParamsDesc& _desc) const {
        return std::shared_ptr<GPUPipelineParamsInfo>(new GPUPipelineParamsInfo(_desc));
    }

    std::shared_ptr<GPUPipelineParamsInfo> RenderStateManager::createGPUPipelineParamsInfo(const ComputeParamsDesc& _desc) const {
        return std::shared_ptr<GPUPipelineParamsInfo>(new GPUPipelineParamsInfo(_desc));
    }

    std::shared_ptr<GPUParams> RenderStateManager::createGPUParams(const std::shared_ptr<GPUPipelineParamsInfo>& _info) const {
        return std::shared_ptr<GPUParams>(new GPUParams(_info));
    }

    std::shared_ptr<GraphicsPipelineState> RenderStateManager::createGraphicsPipelineState(const GraphicsPipelineStateDesc& _desc) {
        return std::shared_ptr<GraphicsPipelineState>(new GraphicsPipelineState(_desc));
    }
}
