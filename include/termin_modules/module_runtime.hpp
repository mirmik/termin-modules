#pragma once

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "termin_modules/module_backend.hpp"
#include "termin_modules/module_descriptor_parser.hpp"
#include "termin_modules/module_integration.hpp"

namespace termin_modules {

class ModuleRuntime {
public:
    using ModuleEventCallback = std::function<void(const ModuleEvent&)>;

    void set_environment(ModuleEnvironment environment);
    void set_integration(std::shared_ptr<IModuleIntegration> integration);
    void set_event_callback(ModuleEventCallback callback);
    void set_descriptor_parser(std::shared_ptr<ModuleDescriptorParser> parser);
    void register_backend(std::shared_ptr<IModuleBackend> backend);

    void discover(const std::filesystem::path& project_root);

    bool load_all();
    bool load_module(const std::string& module_id);
    bool unload_module(const std::string& module_id);
    bool reload_module(const std::string& module_id);

    const ModuleRecord* find(const std::string& module_id) const;
    std::vector<const ModuleRecord*> list() const;

    const std::string& last_error() const;

private:
    bool build_load_order(std::vector<ModuleRecord*>& ordered, std::string& error);
    bool visit_module(
        ModuleRecord& record,
        std::unordered_map<std::string, int>& marks,
        std::vector<ModuleRecord*>& ordered,
        std::string& error
    );
    IModuleBackend* get_backend(ModuleKind kind) const;
    void emit(ModuleEventKind kind, const std::string& module_id, const std::string& message = std::string());
    bool should_skip(const ModuleSpec& spec) const;

    ModuleEnvironment _environment;
    std::shared_ptr<IModuleIntegration> _integration;
    std::shared_ptr<ModuleDescriptorParser> _parser;
    std::unordered_map<ModuleKind, std::shared_ptr<IModuleBackend>> _backends;
    std::vector<ModuleRecord> _records;
    ModuleEventCallback _event_callback;
    std::string _last_error;
};

} // namespace termin_modules
