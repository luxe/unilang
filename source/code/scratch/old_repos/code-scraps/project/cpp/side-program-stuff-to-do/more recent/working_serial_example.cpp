#include <fstream>
#include <iostream>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

//STL serializers
#include <boost/serialization/vector.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/array.hpp>
#include <boost/serialization/map.hpp>

using namespace std;

class Test {
private:    
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive & ar,
            const unsigned int version) {
        ar & BOOST_SERIALIZATION_NVP(a);
        ar & BOOST_SERIALIZATION_NVP(b);
        ar & BOOST_SERIALIZATION_NVP(c);
        ar & BOOST_SERIALIZATION_NVP(d);
    }
  
    int a;
    int b;
    float c;
    std::vector<int> d{1,2,3,4,5};
public:
    inline Test(int a, int b, float c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int main() {
    std::ofstream ofs("filename.xml");

    Test* test = new Test(1, 2, 3.3);

    boost::archive::xml_oarchive oa(ofs);
    oa << BOOST_SERIALIZATION_NVP(test);

    return 0;
}
