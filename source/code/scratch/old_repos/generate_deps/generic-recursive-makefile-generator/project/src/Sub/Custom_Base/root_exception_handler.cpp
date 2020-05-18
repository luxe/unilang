#include "Sub/Custom_Base/root_exception_handler.hpp"







 void Root_Exception_Handler::Handle_Exceptions() {
    try{throw;}
    catch(std::string const& e                      ){Handle_Exception(e);}
    catch(const char* e                             ){Handle_Exception(e);}
    catch(std::exception const& e                   ){Handle_Exception(e);}
    //add other exceptions...
    catch(...)                                       {Handle_Exception( );}
}

 void Root_Exception_Handler::Handle_Exception(std::string const& e){
    Print_Message_Along_With_Diagnostic_Information(e);
}
 void Root_Exception_Handler::Handle_Exception(std::exception const& e){
    Print_Message_Along_With_Diagnostic_Information(e.what());
}

 void Root_Exception_Handler::Handle_Exception(){
    Print_Message_Along_With_Diagnostic_Information
    ("Unknown exception thrown. This should not happen.\nYou found a bug in the software.\nPlease report this.");
}

//handle other exceptions...

 void Root_Exception_Handler::Print_Message_Along_With_Diagnostic_Information(std::string const& exception_message){
  Red_Error_Message(exception_message);
  auto diagnostic_info = boost::current_exception_diagnostic_information();
  Red_Error_Message("\n\nCaptured Exception Info:\n" + diagnostic_info);
}
