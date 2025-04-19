// Copyright

#ifndef OPTIONS_CORE_OPTIONS_HPP
#define OPTIONS_CORE_OPTIONS_HPP

#include <options/core/OptionNode.hpp>

#include <string>

namespace options {

class Options{
public:
    Options() = default;

    /**
     * @brief Load options from a file.
     * @param filename The name of the file to load.
     * @return True if the file was loaded successfully, false otherwise.
     */
    bool load(const std::string& filename);

    OptionNode operator[](const std::string& name) const;
};

} // namespace option

#endif // !OPTIONS_CORE_OPTIONS_HPP