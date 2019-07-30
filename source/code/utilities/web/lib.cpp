#include "code/utilities/web/lib.hpp"
#include "code/utilities/types/strings/observers/converting/lib.hpp"
#include "code/utilities/shell/lib.hpp"
#include <curl/curl.h>
#include <iostream>
#include "code/utilities/json/json_extractor.hpp"


nlohmann::json Extract_Web_Json(Html_Fetch_Settings const& settings){
    auto str = Get_Html_Of_Site(settings);
    auto j = nlohmann::json::parse(str);
    return j;
}

float Extract_Web_Json_Float(Web_Json_Extraction_Settings const& settings){
  
  auto str = Get_Html_Of_Site(settings.fetch);
  auto val = Json_Extractor::Extract(str,settings.extract);
  return val;
}

std::string Get_Html_Of_Site(Html_Fetch_Settings const& settings){
  std::string str;
  
  if (settings.strategy == Html_Fetch_Strategy::CURL_LIB){
    str = Get_HTML_Of_Site_With_Curl_Lib(settings);
  }
  else if (settings.strategy == Html_Fetch_Strategy::CURL_COMMAND){
    str = Get_HTML_Of_Site_With_Curl_Command(settings.url);
  }
  return str;
}

std::string Get_HTML_Of_Site_With_Curl_Command(std::string const& website){
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

void possibly_show_error(std::string const& message, bool const& should_show){
  if (should_show){
    std::cerr << message << std::endl;
  }
}

std::string Get_HTML_Of_Site_With_Curl_Lib(Html_Fetch_Settings const& settings){
    std::string buffer;
 
    CURL *curl;
    CURLcode result;
    curl = curl_easy_init();
 
    if (curl){
      curl_easy_setopt(curl, CURLOPT_URL, settings.url.c_str()  );
      curl_easy_setopt(curl, CURLOPT_HEADER, 0);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
      curl_easy_setopt(curl, CURLOPT_TIMEOUT,settings.seconds_till_timeout);
      
      //set headers
      struct curl_slist *list = NULL;
      for (auto const& it: settings.headers){
        list = curl_slist_append(list, it.c_str());
      }
      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
      
      if (settings.post){
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
      }
 
      result = curl_easy_perform(curl);//http get performed
      curl_slist_free_all(list); /* free the list again */
 
      curl_easy_cleanup(curl);//must cleanup
 
      //error codes: http://curl.haxx.se/libcurl/c/libcurl-errors.html
      if (result == CURLE_OK)
          return buffer;
      //curl_easy_strerror was added in libcurl 7.12.0
      std::string message = std::string("error: ") + std::to_string(result) + " " + curl_easy_strerror(result);
      possibly_show_error(message,settings.show_errors);
      return "";
    }
 
    possibly_show_error("error: could not initialize curl",settings.show_errors);
    return "";
}


std::vector<std::string> Get_HTML_Of_Site_With_Each_Line_In_Vector(std::string const& website){
    auto it = Get_HTML_Of_Site_With_Curl_Command(website);
    return Put_Each_Line_Of_String_Into_A_Vector(it);
}
void Send_Email(std::string const& message, std::string const& email)
{
	execute("echo \"" + message + "\" | mail \"" + email + "\"");
}


int Website_Response_Code(std::string const& url){
  CURL *curl = curl_easy_init();
  long response_code = 0;
  if(curl) {
    CURLcode res;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    res = curl_easy_perform(curl);
    if(res == CURLE_OK) {
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    }
    curl_easy_cleanup(curl);
  }
  
  return response_code;
}

bool Is_Url_Reponse_200(std::string const& url){
  if (Website_Response_Code(url) == 200){
    return true;
  }
  return false;
}