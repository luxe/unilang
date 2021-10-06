#############################
# Terminal Default Behavior #
#############################
#this will edit shell options through the shopt program
#(THESE COMMANDS DO NOT WORK IN ZSH)
#shopt -u autocd #don't automatically cd into a folder if that folder is the same name as a program
#shopt -s cdspell #still go to the directory if there is a minor misspelling
#shopt -s checkwinsize #update window size(LINES and COLUMNS) after each command is executed
#shopt -s dirspell #helps with word completion. when no other names exist, it checks for misspellings
#shopt -s dotglob #include 'dot' files in results of filename expansion
#shopt -s expand_aliases #yes, use my aliases
#shopt -s histappend #appends to history file(HISTFILE) instead of overwriting it when the shell exits
#shopt -s hostcomplete #host name completion
#shopt -s interactive_comments #allow comments in bash
#shopt -s nocaseglob #match case-insensitively for tab completion
#shopt -s nocasematch #match case-insensitively for matching in like conditional commands and stuff
#shopt -s progcomp #enable programmable completion facilities
#shopt -s sourcepath #use PATH to find things for source

#ones I skipped, because I don't really care about
# shopt -u cdable_vars
# shopt -u checkhash
# shopt -u checkjobs
# shopt -s cmdhist
# shopt -u compat31
# shopt -u compat32
# shopt -u compat40
# shopt -u compat41
# shopt -u direxpand
# shopt -u execfail
# shopt -u extdebug
# shopt -s extglob
# shopt -s extquote
# shopt -u failglob
# shopt -s force_fignore
# shopt -u globstar
# shopt -u gnu_errfmt
# shopt -u histreedit
# shopt -u histverify
# shopt -u huponexit
# shopt -u lastpipe
# shopt -u lithist
# shopt -u login_shell
# shopt -u mailwarn
# shopt -u no_empty_cmd_completion
# shopt -u nullglob
# shopt -s promptvars
# shopt -u restricted_shell
# shopt -u shift_verbose
# shopt -u xpg_echo
