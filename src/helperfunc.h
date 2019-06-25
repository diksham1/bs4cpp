#ifndef __HELPER__
#define __HELPER__

string trimWhitespace(string s) {
    s = std::regex_replace(s, std::regex("\\s+"), "");
    return s;
}
