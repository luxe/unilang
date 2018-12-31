#include "code/utilities/web/lib.hpp"
#include "code/utilities/types/strings/observers/converting/lib.hpp"
#include "code/utilities/shell/lib.hpp"
#include <curl/curl.h>
#include <iostream>

std::string Get_HTML_Of_Site(std::string const& website){
  return execute_and_get_back_stdout_only("curl " + website);
}

int writer(char *data, size_t size, size_t nmemb, std::string *buffer){
  int result = 0;
  if (buffer != NULL)
  {
      buffer->append(data, size * nmemb);
      result = size * nmemb;
  }
  return result;
}

std::string Get_HTML_Of_Site_With_Curl_Lib(std::string const& url){
    std::string buffer;
 
    CURL *curl;
    CURLcode result;
 	
    curl = curl_easy_init();
 
    if (curl){
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str()  );
      curl_easy_setopt(curl, CURLOPT_HEADER, 0);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
 
      result = curl_easy_perform(curl);//http get performed
 
      curl_easy_cleanup(curl);//must cleanup
 
      //error codes: http://curl.haxx.se/libcurl/c/libcurl-errors.html
      if (result == CURLE_OK)
          return buffer;
      //curl_easy_strerror was added in libcurl 7.12.0
      std::cerr << "error: " << result << " " << curl_easy_strerror(result) << std::endl;
      return "";
    }
 
    std::cerr << "error: could not initalize curl" << std::endl;
    return "";
}
std::vector<std::string> Get_HTML_Of_Site_With_Each_Line_In_Vector(std::string const& website){
    auto it = Get_HTML_Of_Site(website);
    return Put_Each_Line_Of_String_Into_A_Vector(it);
}
void Send_Email(std::string const& message, std::string const& email)
{
	execute("echo \"" + message + "\" | mail \"" + email + "\"");
}