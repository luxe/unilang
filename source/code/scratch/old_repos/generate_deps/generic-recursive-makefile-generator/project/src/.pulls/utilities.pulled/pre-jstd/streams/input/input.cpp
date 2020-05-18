std::vector<std::string> Read_In_All_Of_Std_Input_As_Vector_Of_Lines(){
    std::vector<std::string> lines;
    std::string line;
    std::getline(std::cin,line);
    while (std::cin){
        lines.push_back(line);
        std::getline(std::cin,line);
    }
    return lines;
}


std::vector<std::vector<int>> Read_In_Integers_For_Each_Line(){
    
}
