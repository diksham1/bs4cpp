#include <iostream>

std::string trimWhitespace(std::string s) {
    s = std::regex_replace(s, std::regex("\\s+"), "");
    return s;
}
