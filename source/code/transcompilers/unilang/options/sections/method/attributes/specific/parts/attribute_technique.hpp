#pragma once

enum class Attribute_Technique
{GCC       //example: __attribute__((unused))
,CLANG     //example: __attribute__((unused))
,STD       //example: [[maybe_unused]]
,MICROSOFT //ecample: ...
,SPLINT    //example: /*@unused@*/
,CUSTOM    //example: user specified
};
