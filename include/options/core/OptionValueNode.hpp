

#ifndef OPTIONS_CORE_OPTIONVALUENODE_HPP
#define OPTIONS_CORE_OPTIONVALUENODE_HPP

#include <options/core/OptionNode.hpp>

#include <string>

namespace options{
    
class OptionValueNode : public OptionNode{
public:

    [[nodiscard]] bool has_value() const;

    [[nodiscard]] bool has_children() const;

    [[nodiscard]] std::string key() const{
        return m_key;
    }

    [[nodiscard]] bool is_value() const override{
        return true;
    }

private:
    std::string m_key;
};

} // namespace options

#endif // !OPTIONS_CORE_OPTIONVALUENODE_HPP
