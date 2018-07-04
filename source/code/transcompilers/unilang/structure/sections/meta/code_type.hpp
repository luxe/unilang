#pragma once

//how the data is to be thought of and understood.  
//this also effects how the code is generated.
//every UniLang file represents one of the following:  
//It's either:
//GLOBAL: global collection of data and functions
//SUM_TYPE: a union/variant/sum type with possible methods and other miscellanous data (typedefs/enums/inlined includes/etc)
//PRODUCT_TYPE: a collection of data inside an object with possible methods and other miscellanous data (typedefs/enums/inlined includes/etc)
enum class Code_Type
{GLOBAL
,SUM_TYPE
,PRODUCT_TYPE
};
