#pragma once
#include <vector>
#include <utility>
#include <functional>
#include "code/tools/transcompilers/unilang/tokens/token_name.hpp"
#include "code/tools/transcompilers/unilang/parser/token_value.hpp"

namespace Parser{
    
    //string content to to Token Value
    using Token_Value_Binds = std::vector<std::pair<Token_Name,std::reference_wrapper<Token_Value>>>;
    
    //various chars whose existence, map to bools
    using Bool_Value_Binds =  std::vector<std::pair<Token_Name,std::vector<std::pair<wchar_t,std::reference_wrapper<bool>>>>>;
    
    
    //a more complicated and descriptive type build up for any type to type
    //it was created to handle the enum classes, as they are all technically different types
    template <typename From, typename To>
    struct Value_To_Value{

      Value_To_Value(From from, To to)
      : from(from)
      , to(to)
      {}

      From from;
      To to;
    };

    template <typename From, typename To>
    using Type_To_Type_Value_Map = std::vector<Value_To_Value<From,To>>;

    template <typename From, typename To>
    struct Any_Value_Mapping{

      Any_Value_Mapping(std::reference_wrapper<To> binded, Token_Name const& token_name, Type_To_Type_Value_Map<From,To> map, To fallback)
      : map(map)
      , binded(binded)
      , fallback(fallback)
      , token_name(token_name)
      {}

      Type_To_Type_Value_Map<From,To> map;
      std::reference_wrapper<To> binded;
      To fallback;
      Token_Name token_name;
    };
}
