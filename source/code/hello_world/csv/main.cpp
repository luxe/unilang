#include "csv/reader.hpp"
#include "code/utilities/csv/csv_extractor.hpp"
#include <iostream>

int main(){
    
    
    auto ips = Csv_Extractor::Get_Column_Values_Of_Double_Quoted("/home/thickey/Desktop/wireshark.csv", "Address");
    for (auto const& it: ips){
        std::cout << it << std::endl;
    }
    // exit(0);
    
    // csv::Reader foo;
    // foo.read("/home/thickey/Desktop/wireshark.csv");

    // //foo.configure_dialect("my fancy dialect")
    //   //.delimiter(",")
    //   //.quote_character('"')
    //   //.double_quote(true)
    //   //.skip_initial_space(false)
    //   //.trim_characters(' ', '\t')
    //   //.ignore_columns("foo", "bar")
    //   //.header(true)
    //   //.skip_empty_rows(false);
    
    // auto rows = foo.rows();
    
    // for (auto & row: rows){
    //     auto data = row["\"Address\""];
    //     std::cout << data << std::endl.hpp;
    // }
}