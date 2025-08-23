#pragma once

#include <string>
#include <vector>
#include <nlohmann/json_fwd.hpp>

namespace Revolt {

    // Forward declaration
    class Project;

    // Non-member parsing functions for automatic conversion from JSON
    void from_json(const nlohmann::json& j, Project& p);

    struct ProjectAssets {
        std::string root;
        std::vector<std::string> packs;
    };

    struct ProjectBuild {
        std::string toolchain;
        std::vector<std::string> configurations;
        std::string rhi;
    };

    /**
     * @class Project
     * @brief Represents the data loaded from a revolt.project.json file.
     *
     * This class models the project's configuration, including its name,
     * required modules, asset paths, and build settings.
     */
    class Project {
    public:
        /**
         * @brief Loads and parses a project file from the given path.
         * @param filepath The path to the revolt.project.json file.
         * @return A Project object populated with the data from the file.
         * @throws std::runtime_error if the file cannot be opened or parsed.
         */
        static Project Load(const std::string& filepath);

        // Public members matching the JSON structure
        int version = 0;
        std::string name;
        std::string engine_min;
        std::vector<std::string> modules;
        std::vector<std::string> defines;
        ProjectAssets assets;
        ProjectBuild build;
        std::vector<std::string> plugins;

    private:
        // Private constructor to enforce usage of the Load factory method.
        Project() = default;

        // Grant the non-member from_json function access to private members if needed.
        friend void from_json(const nlohmann::json& j, Project& p);
    };

} // namespace Revolt
