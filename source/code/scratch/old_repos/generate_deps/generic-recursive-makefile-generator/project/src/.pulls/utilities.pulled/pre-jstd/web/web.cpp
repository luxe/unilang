  std::string Get_HTML_Of_Site(std::string const& website){
  return execute_and_get_back_stdout_only("curl " + website);
}
std::vector<std::string> Get_HTML_Of_Site_With_Each_Line_In_Vector(std::string const& website){
    auto it = Get_HTML_Of_Site(website);
    return Put_Each_Line_Of_String_Into_A_Vector(it);
}
