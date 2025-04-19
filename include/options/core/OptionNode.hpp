

#ifndef OPTIONS_CORE_OPTIONNODE_HPP
#define OPTIONS_CORE_OPTIONNODE_HPP

#include <string>

namespace options{
    
class OptionNode {
public:

    [[nodiscard]] bool has_value() const;

    [[nodiscard]] bool has_children() const;

    [[nodiscard]] virtual bool is_value() const = 0;

    [[nodiscard]] std::string key() const{
        return m_key;
    }

private:
    std::string m_key;
};

} // namespace options

#endif // !OPTIONS_CORE_OPTIONNODE_HPP
