#include <fstream>

// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


template<typename T>
void Load_Object_From_Boost_Serialized_Data_File(T & obj, std::string const& file_name);
template<typename T>
void Save_Object_To_A_Boost_Serliazed_Data_File(T const& obj, std::string const& file_name);
template<typename T>
void Append_Object_To_A_Boost_Serliazed_Data_File(T const& obj, std::string const& file_name);

class gps_position
{
private:
    friend class boost::serialization::access;
    // When the class Archive corresponds to an output archive, the
    // & operator is defined similar to <<.  Likewise, when the class Archive
    // is a type of input archive the & operator is defined similar to >>.
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & degrees;
        ar & minutes;
        ar & seconds;
        ar & hi;
    }
    int degrees;
    int minutes;
    float seconds;
    std::string hi = "sdf\nsdfs\nsdf\tsdf";
    static unsigned int serialization_counter;
public:

    //constructor
    gps_position(){
      ++serialization_counter;
      
    };
    
    
    gps_position(int d, int m, float s) :
        degrees(d), minutes(m), seconds(s)
    {}
};

unsigned int gps_position::serialization_counter = 0;

int main() {

    // create class instance
    gps_position g1(35, 59, 24.567f);
    gps_position g2(20, 59, 24.567f);
    Save_Object_To_A_Boost_Serliazed_Data_File(g1,"file_name2");
    Save_Object_To_A_Boost_Serliazed_Data_File(g2,"file_name2");

    gps_position ga;
    gps_position gb;
    Load_Object_From_Boost_Serialized_Data_File(ga,"file_name2");
    Load_Object_From_Boost_Serialized_Data_File(gb,"file_name2");
    
    std::cout << ga.degrees << std::endl;
    std::cout << gb.degrees << std::endl;
    return 0;
}

template<typename T>
void Load_Object_From_Boost_Serialized_Data_File(T & obj, std::string const& file_name){
    std::ifstream infile(file_name);
    std::unique_ptr<boost::archive::text_iarchive> arc(new boost::archive::text_iarchive(infile));
        *arc >> obj;
}

template<typename T>
void Save_Object_To_A_Boost_Serliazed_Data_File(T const& obj, std::string const& file_name){
    std::ofstream outfile(file_name);
    std::unique_ptr<boost::archive::text_oarchive> arc(new boost::archive::text_oarchive(outfile));
    *arc << obj;
}
template<typename T>
void Append_Object_To_A_Boost_Serliazed_Data_File(T const& obj, std::string const& file_name){
    std::ofstream outfile(file_name, std::ios::app);
    std::unique_ptr<boost::archive::text_oarchive> arc(new boost::archive::text_oarchive(outfile));
    *arc << obj;
}

