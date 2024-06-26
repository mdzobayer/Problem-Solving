#include "strc.h"
#include <cstdio>
#include <cstring>
#include <memory>

void strc::msg(const char * s) {
    if(data) printf("%s: %s (%s)\n", __strc_class, s, data);
    else printf("%s: %s\n", __strc_class, s);
    fflush(stdout);
}

strc::strc() : data(nullptr) {
    msg("default ctor");
}

strc::strc(const char * s) {
    size_t slen = strlen(s);
    data = new char[slen + 1];
    data[slen] = 0;
    memcpy(data, s, slen);
    msg("cstring ctor");
}

strc::strc(const strc & f) {
    size_t slen = strlen(f.data);
    data = new char[slen + 1];
    data[slen] = 0;
    memcpy(data, f.data, slen);
    msg("copy ctor");
}

strc::strc(strc && o) {
    data = std::move(o.data);
    o.data = nullptr;
    msg("move ctor");
}

strc::~strc() {
    msg("dtor");
    delete[] data;
}

strc & strc::operator = (strc o) {
    swap(o);
    msg("copy and swap =");
    return *this;
}

const char * strc::value() const {
    return data;
}

strc::operator const char * () const {
    return value();
}

void strc::swap(strc & o) {
    std::swap(this->data, o.data);
}
