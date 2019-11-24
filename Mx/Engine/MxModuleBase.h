#pragma once

#ifndef MX_MODULE_BASE_H_
#define MX_MODULE_BASE_H_

#include "../Utils/MxGeneralBase.hpp"
#include "../Log/MxLog.h"

namespace Mix {
    class ModuleBase : GeneralBase::NoCopyBase {
    public:
        virtual void load() {}

        virtual void init() {}

        virtual ~ModuleBase() = default;

    protected:
        ModuleBase();
    };


    //////////////////////////////////////////////////
    //                 Test Module                  //
    //////////////////////////////////////////////////

    template<typename _Ty>
    class TModule :GeneralBase::NoCopyAndMoveBase {
    public:
        virtual ~TModule() {
            if (!IsDestroyed()) {
                MX_LOG_ERROR("Trying destroy a module out of Destroy().");
                std::terminate();
            }
        }

        static _Ty* Get() {
            if (!IsInitialized()) {
                throw ModuleError("Trying to get a module that hasn't been initialized.");
            }

            if (IsDestroyed()) {
                throw ModuleError("Trying to get a module that has been destroyed.");
            }

            return InstanceInternal();
        }

        template<typename ... _Args>
        static void Initialize(_Args&&... _args) {
            if (IsInitialized()) {
                throw ModuleError("Trying to initialize a module that has been initialized.");
            }

            InstanceInternal() = new _Ty(std::forward<_Args>(_args)...);
            IsInitializedInternal() = true;
        }

        template<typename _Derived, typename ... _Args>
        static void Initialize(_Args&&... _args) {
            static_assert(std::is_base_of<_Ty, _Derived>::value, "Provided type should be derived from the module it self.");

            if (IsInitialized()) {
                throw ModuleError("Trying to initialize a module that has been initialized.");
            }

            InstanceInternal() = new _Derived(std::forward<_Args>(_args)...);
            IsInitializedInternal() = true;
        }

        static void Destroy() {
            if (IsDestroyed()) {
                throw ModuleError("Trying to destroy a module that has been destroyed.");
            }

            IsDestroyedInternal() = true;
            delete InstanceInternal();
            InstanceInternal() = nullptr;
        }

        static bool IsInitialized() { return IsInitializedInternal(); }

        static bool IsDestroyed() { return IsDestroyedInternal(); }

    private:

        static _Ty*& InstanceInternal() {
            static _Ty* ptr = nullptr;
            return ptr;
        }

        static bool& IsInitializedInternal() {
            static bool flag = false;
            return flag;
        }

        static bool& IsDestroyedInternal() {
            static bool flag = false;
            return flag;
        }

    protected:
        TModule() = default;
    };

}

#endif
