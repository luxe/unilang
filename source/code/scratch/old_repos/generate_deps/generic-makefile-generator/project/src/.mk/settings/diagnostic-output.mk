#I would like to process the compiler diagnostics through a custom program.  
#Here is me complaining on the internet:
#https://llvm.org/bugs/show_bug.cgi?id=30238
#http://stackoverflow.com/questions/36657869/how-do-i-dump-gcc-warnings-into-a-structured-format

CLANG_FORMAT_CONSUMER := -fshow-column \
-fshow-source-location \
-fno-caret-diagnostics \
-fno-color-diagnostics \
-fdiagnostics-format=msvc \
-fdiagnostics-show-option \
-fdiagnostics-show-category=name \
-fno-diagnostics-fixit-info \
-fno-diagnostics-print-source-range-info \
-fdiagnostics-parseable-fixits \
-fno-elide-type \
-fno-diagnostics-show-template-tree

CLANG_FORMAT_TERMINAL := -fshow-column \
-fshow-source-location \
-fcaret-diagnostics \
-fcolor-diagnostics \
-fdiagnostics-format=clang \
-fdiagnostics-show-option \
-fdiagnostics-show-category=name \
-fdiagnostics-fixit-info \
-fno-diagnostics-print-source-range-info \
-fno-diagnostics-parseable-fixits \
-felide-type \
-fdiagnostics-show-template-tree

GCC_FORMAT_CONSUMER := -fmessage-length=0 \
-fdiagnostics-show-location=once \
-fdiagnostics-show-location=every-line \
-fdiagnostics-color=never \
-fdiagnostics-show-option \
-fno-diagnostics-show-caret
# -fdiagnostics-parseable-fixits

GCC_FORMAT_TERMINAL := -fmessage-length=0 \
-fdiagnostics-show-location=once \
-fdiagnostics-show-location=every-line \
-fdiagnostics-color=always \
-fdiagnostics-show-option \
-fdiagnostics-show-caret
# -fno-diagnostics-parseable-fixits

DIAGNOSTIC_FORMAT := $(GCC_FORMAT_TERMINAL)
