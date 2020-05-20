#include "AudioFile.h"
#include "code/utilities/types/vectors/operators/lib.hpp"
#include "code/utilities/peripheral/sound/wav/wav_file_join_settings.hpp"
#include "code/utilities/peripheral/sound/wav/wav_file_joiner.hpp"
#include "code/utilities/assets/english_sounds.hpp"
#include "code/utilities/peripheral/sound/wav/pitch_adjuster.hpp"

int main(){
    
    
    
    std::string message = "welcome to nook cranny how can i help you today";
    
    Wav_File_Join_Settings settings;
    settings.output_path = "/home/laptop/Desktop/out.wav";
    for (auto c: message){
        
        if (c == ' '){
            settings.input_paths.emplace_back(English_Sounds::Space());
        }
        else if (c == '.'){
            settings.input_paths.emplace_back(English_Sounds::Period());
        }
        else{
            settings.input_paths.emplace_back(English_Sounds::From_Letter(c));
        }
    }
    
    
    Wav_File_Joiner::Join(settings);
    Pitch_Adjuster::Adjust(settings.output_path,"/home/laptop/Desktop/out2.wav",1500);
    
}