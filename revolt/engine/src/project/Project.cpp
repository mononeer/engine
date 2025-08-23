#include "Project.h"

#include <fstream>
#include <nlohmann/json.hpp>

namespace Revolt {

    // --- JSON Deserialization Helpers ---
    // These free functions allow nlohmann::json to automatically convert
    // a JSON object into our C++ structs.

    void from_json(const nlohmann::json& j, ProjectAssets& assets) {
        j.at("root").get_to(assets.root);
        j.at("packs").get_to(assets.packs);
    }

    void from_json(const nlohmann::json& j, ProjectBuild& build) {
        j.at("toolchain").get_to(build.toolchain);
        j.at("configurations").get_to(build.configurations);
        j.at("rhi").get_to(build.rhi);
    }

    void from_json(const nlohmann::json& j, Project& p) {
        j.at("version").get_to(p.version);
        j.at("name").get_to(p.name);
        j.at("engine_min").get_to(p.engine_min);
        j.at("modules").get_to(p.modules);
        j.at("defines").get_to(p.defines);
        j.at("assets").get_to(p.assets);
        j.at("build").get_to(p.build);
        j.at("plugins").get_to(p.plugins);
    }

    // --- Project Class Implementation ---

    Project Project::Load(const std::string& filepath) {
        std::ifstream file(filepath);
        if (!file.is_open()) {
            // In a real engine, we might want a more specific exception type.
            throw std::runtime_error("Failed to open project file: " + filepath);
        }

        // Parse the file stream into a JSON object.
        // This can throw nlohmann::json::parse_error on invalid JSON.
        nlohmann::json data = nlohmann::json::parse(file);

        // Convert the JSON object to a Project object using our from_json helpers.
        // This can throw nlohmann::json::type_error if fields are missing/wrong type.
        return data.get<Project>();
    }

} // namespace Revolt
