#pragma once

#include <memory>

#include "termin_modules/module_types.hpp"

namespace termin_modules {

class IModuleIntegration;

class IModuleBackend {
public:
    virtual ~IModuleBackend() = default;

    virtual ModuleKind kind() const = 0;

    virtual bool load(
        ModuleRecord& record,
        const ModuleEnvironment& environment,
        IModuleIntegration* integration
    ) = 0;

    virtual bool unload(
        ModuleRecord& record,
        const ModuleEnvironment& environment,
        IModuleIntegration* integration
    ) = 0;
};

} // namespace termin_modules
