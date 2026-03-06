#pragma once

#include <string>

#include "termin_modules/module_types.hpp"

namespace termin_modules {

class IModuleIntegration {
public:
    virtual ~IModuleIntegration() = default;

    virtual void before_load(const ModuleRecord& record) {}
    virtual void after_load(const ModuleRecord& record) {}
    virtual void before_unload(const ModuleRecord& record) {}
    virtual void after_unload(const ModuleRecord& record) {}
    virtual void after_reload(const ModuleRecord& record) {}
    virtual void after_failed_load(const ModuleRecord& record, const std::string& error) {}
};

} // namespace termin_modules
