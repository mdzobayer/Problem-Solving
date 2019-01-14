#include "ZSString.h"

#pragma mark - constructors/destructors

ZSString::ZSString( ) {
    reset();
}

ZSString::ZSString( const char * s ) {
    copy_str(s);
}

ZSString::ZSString( const ZSString & old ) {
    copy_str(old);
}


ZSString::~ZSString() {
    reset();
}

// move constructor
ZSString::ZSString( ZSString && other ) _NOEXCEPT {
    reset();
    _str = other._str;
    _str_len = other._str_len;
    other._str = nullptr;
    other._str_len = 0;
    other.reset();
}

#pragma mark - private methods

void ZSString::_reset_split_array() const {
    if (_split_count) {
        // dtor the elements in the array
        while(_split_count) {
            _split_array[--_split_count].reset();
        }
        _split_array.reset();
        _split_count = 0;
    }
}

void ZSString::_append_split_array(const ZSString & s) const {
    if (_split_count >= __ZSString__MAX_SPLIT) return;
    if (!_split_count) {
        _split_array.reset(new _zssp[__ZSString__MAX_SPLIT + 1]);
    }
    _split_array[_split_count] = std::make_shared<ZSString>(s);
    ++ _split_count;
}

#pragma mark - public methods

const char * ZSString::alloc_str( size_t sz ) {
    if (_str) reset();
    _str_len = (sz > __ZSString__MAX_LEN) ? __ZSString__MAX_LEN : sz;
    _str = new char[_str_len + 1]();  // new char[]() fills with 0
    return _str;
}

void ZSString::reset() {
    _reset_split_array();
    if(_str) delete [] _str;
    _str = nullptr;
    _str_len = 0;
}

void ZSString::swap(ZSString & other) {
    std::swap(_str, other._str);
    std::swap(_str_len, other._str_len);
}

const char * ZSString::c_str() const {
    return _str;
}

const char * ZSString::copy_str( const char * s) {
    if(s) {
        size_t len = strlen(s);
        alloc_str(len);
        strncpy((char *)_str, s, len);
        _str_len = len;
    }
    return _str;
}

#pragma mark - operators

// copy-and-swap assignment
ZSString & ZSString::operator = ( ZSString other ) {
    swap(other);
    return *this;
}

ZSString & ZSString::operator += ( const char * rhs ) {
    if(rhs) {
        size_t newlen = _str_len + strlen(rhs);
        if (newlen > __ZSString__MAX_LEN) newlen = __ZSString__MAX_LEN;

        size_t rhslen = newlen - _str_len;
        if(rhslen < 1) return *this;

        char * buf = new char[newlen + 1]();
        if(_str && _str_len) memcpy(buf, _str, _str_len);
        memcpy(buf + _str_len, rhs, rhslen);
        copy_str(buf);
        delete [] buf;
    }
    return *this;
}

ZSString & ZSString::operator += ( const ZSString & rhs ) {
    operator+=(rhs.c_str());
    return *this;
}

const char ZSString::operator[] ( const int index ) const {
    if(index < 0) return 0;
    if(index >= (int) _str_len) return 0;
    else return _str[index];
}

#pragma mark - comparison operators

bool ZSString::operator == ( const ZSString & rhs ) const {
    if( std::strncmp(this->c_str(), rhs.c_str(), __ZSString__MAX_LEN) == 0 ) return true;
    else return false;
}

bool ZSString::operator != ( const ZSString & rhs ) const {
    if( std::strncmp(this->c_str(), rhs.c_str(), __ZSString__MAX_LEN) != 0 ) return true;
    else return false;
}

bool ZSString::operator > ( const ZSString & rhs ) const {
    if( std::strncmp(this->c_str(), rhs.c_str(), __ZSString__MAX_LEN) > 0 ) return true;
    else return false;
}

bool ZSString::operator < ( const ZSString & rhs ) const {
    if( std::strncmp(this->c_str(), rhs.c_str(), __ZSString__MAX_LEN) < 0 ) return true;
    else return false;
}

bool ZSString::operator >= ( const ZSString & rhs ) const {
    if( std::strncmp(this->c_str(), rhs.c_str(), __ZSString__MAX_LEN) >= 0 ) return true;
    else return false;
}

bool ZSString::operator <= ( const ZSString & rhs ) const {
    if( std::strncmp(this->c_str(), rhs.c_str(), __ZSString__MAX_LEN) <= 0 ) return true;
    else return false;
}

#pragma mark - conversion operators

ZSString::operator const char * () const {
    return c_str();
}

#pragma mark - Utility methods

bool ZSString::have_value() const {
    if(_str) return true;
    else return false;
}

// string format
ZSString & ZSString::format( const char * format , ... ) {
    char * buffer;

    va_list args;
    va_start(args, format);

    vsprintf(buffer, format, args);
    copy_str(buffer);
    free(buffer);   // vasprintf uses malloc
    return *this;
}

// trim leading and trailing spaces
ZSString & ZSString::trim() {
    const static char * whitespace = "\x20\x1b\t\r\n\v\b\f\a";

    if(!have_value()) return *this; // make sure we have a string

    size_t begin = 0;
    size_t end = length() - 1;

    for (begin = 0; begin <= end; ++begin) {
        if (strchr(whitespace, _str[begin]) == nullptr) {
            break;
        }
    }

    for ( ; end > begin; --end) {
        if (strchr(whitespace, _str[end]) == nullptr) {
            break;
        } else {
            _str[end] = '\0';
        }
    }

    if (begin) {
        for (size_t i = 0; _str[i]; ++i) {
            _str[i] = _str[begin++];
        }
    }

    _str_len = strlen(_str);
    return *this;
}

ZSString ZSString::lower() const {
    ZSString rs = *this;
    for (size_t i = 0; rs._str[i]; ++i) {
        rs._str[i] = tolower(rs._str[i]);
    }
    return rs;
}

ZSString ZSString::upper() const {
    ZSString rs = *this;
    for (size_t i = 0; rs._str[i]; ++i) {
        rs._str[i] = toupper(rs._str[i]);
    }
    return rs;
}

const char & ZSString::back() const {
    return _str[length() - 1];
}

const char & ZSString::front() const {
    return _str[0];
}

#pragma mark find and replace methods

long int ZSString::char_find( const char & match ) const {
    for (size_t i = 0; _str[i]; ++i) {
        if(_str[i] == match) return i;
    }
    return -1;
}

const ZSString & ZSString::char_repl( const char & match, const char & repl ) {
    for (size_t i = 0; _str[i]; ++i) {
        if(_str[i] == match) _str[i] = repl;
    }
    return *this;
}

ZSString ZSString::substr( size_t start, size_t length ) {
    ZSString rs;
    char * buf;
    if ((length + 1) > __ZSString__MAX_LEN || (start + length) > __ZSString__MAX_LEN) return rs;
    if (length > _str_len - start) return rs;
    if (!_str) return rs;

    buf = new char[length + 1]();
    memcpy(buf, _str + start, length);
    rs = buf;
    delete [] buf;

    return rs;
}

long ZSString::find( const ZSString & match ) const {
    char * pos = strstr(_str, match.c_str());
    if(pos) return (long) ( pos - _str );
    else return -1;
}

const ZSString ZSString::replace( const ZSString & match, const ZSString & repl ) {
    ZSString rs;
    long f1 = find(match);
    if (f1 >= 0) {
        size_t pos1 = (size_t) f1;
        size_t pos2 = pos1 + match.length();
        ZSString s1 = pos1 > 0 ? substr(0, pos1) : "";
        ZSString s2 = substr(pos2, length() - pos2);
        rs = s1 + repl + s2;
    }
    return rs;
}

#pragma mark split methods

// non-destructive split
const ZSString::split_ptr & ZSString::split( const char match ) const {
    const char match_s[2] = { match, 0 };
    return split(match_s, -1);
}

const ZSString::split_ptr & ZSString::split( const char * match ) const {
    return split(match, -1);
}

const ZSString::split_ptr & ZSString::split( const char * match, int max_split ) const {
    _reset_split_array();
    if (length() < 1) return _split_array;
    if (max_split < 0) max_split = __ZSString__MAX_SPLIT;

    size_t match_len = strlen(match);
    if(match_len >= __ZSString__MAX_LEN) return _split_array;

    char * mi;              // match index
    char * pstr = _str;     // string pointer
    while (( mi = strstr(pstr, match)) && --max_split ) {
        if(mi != pstr) {
            size_t lhsz = mi - pstr;
            char * cslhs = new char[lhsz + 1]();
            memcpy(cslhs, pstr, lhsz);
            _append_split_array(cslhs);
            delete [] cslhs;
            pstr += lhsz;
        }
        pstr += match_len;
    }

    if (*pstr != '\0') {
        _append_split_array(pstr);
    }

    return _split_array;
}

// zero-based index of _split_array
const ZSString & ZSString::split_item( size_t index ) const {
    if(_split_count > index) return *_split_array[index];
    else return *this;
}

#pragma mark - non-member operator overloads

ZSString operator + ( const ZSString & lhs, const ZSString & rhs ) {
    ZSString rs = lhs;
    rs += rhs;
    return rs;
}

#ifdef _MSC_VER

#pragma mark - MS missing standard functions

int vasprintf(char ** ret, const char * format, va_list ap)
{
    int len;
    char *buffer;

    len = _vscprintf(format, ap) + 1;
    buffer = (char *) malloc(len * sizeof(char));
    if (!buffer) return 0;
    vsprintf_s(buffer, len, format, ap);
    *ret = buffer;
    return len -1;
}

#endif
