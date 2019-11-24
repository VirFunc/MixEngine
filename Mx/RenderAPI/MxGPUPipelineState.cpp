#include "MxGPUPipelineState.h"
#include "MxRenderStateManager.h"

namespace Mix {
    std::shared_ptr<GraphicsPipelineState> GraphicsPipelineState::Create(const GraphicsPipelineStateDesc& _desc) {
        return RenderStateManager::Get()->createGraphicsPipelineState(_desc);
    }
}
