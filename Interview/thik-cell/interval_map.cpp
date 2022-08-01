// #include <iostream>
#include <map>
#include <limits>

template<typename K, typename V>
class interval_map {
	std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        // INSERT YOUR SOLUTION HERE
        if (keyBegin >= keyEnd) {
            return;
        }
        
        // Find boundary
        auto beginIter = m_map.lower_bound(keyBegin);
        auto endIter = m_map.lower_bound(keyEnd);

        // If not in the map
        // Insert previous element at keyEnd
        if (endIter->first != keyEnd) {
            V const& oldValue = std::prev(endIter, 1)->second;  
            endIter = m_map.insert(endIter, std::make_pair(keyEnd, oldValue));
        }

        // If not in the map
        // Insert val to keyBegin
        if (beginIter->first != keyBegin) {
            beginIter = m_map.insert(beginIter, std::make_pair(keyBegin, val));
            ++beginIter;
        }

        // Interval Range Update
        while(beginIter != endIter) {
            beginIter->second = val;
            ++beginIter;
        }
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of unsigned int intervals to char.

void test();

int main() {
    test();

    return (0);
};

void test() {
    interval_map<int, char> aIntervalMap('5');

    aIntervalMap.assign(51, 60, 'C');

    // std::cout << "50: " << aIntervalMap[50] << std::endl;
    // std::cout << "51: " << aIntervalMap[51] << std::endl;
    // std::cout << "55: " << aIntervalMap[55] << std::endl;

    // std::cout << "59: " << aIntervalMap[59] << std::endl;
    // std::cout << "60: " << aIntervalMap[60] << std::endl;
    // std::cout << "61: " << aIntervalMap[61] << std::endl;


};
