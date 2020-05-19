#include "AudioFile.h"
#include "code/utilities/types/vectors/operators/lib.hpp"
#include "code/utilities/peripheral/sound/wav/wav_file_join_settings.hpp"
#include "code/utilities/peripheral/sound/wav/wav_file_joiner.hpp"
#include "code/utilities/assets/english_sounds.hpp"

int main(){
    
    
    
    std::string message = "hello";
    
    Wav_File_Join_Settings settings;
    settings.output_path = "/home/laptop/Desktop/out.wav";
    for (auto c: message){
        settings.input_paths.emplace_back(English_Sounds::From_Letter(c));
    }
    
    Wav_File_Joiner::Join(settings);
    
}