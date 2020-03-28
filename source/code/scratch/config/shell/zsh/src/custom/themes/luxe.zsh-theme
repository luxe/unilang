
#if the last command fails, the return code is shown in red
local return_code="%(?..%{$fg[red]%}%?%{$reset_color%})"

#show three directories up from home
local dir='[%{$FG[154]%}%4~%{$reset_color%}]'




#git portion
local git='$(git_prompt_status)$(git_prompt_ahead)$(git_prompt_info)'

	ZSH_THEME_GIT_PROMPT_AHEAD="!"


	ZSH_THEME_GIT_PROMPT_CLEAN=""
	ZSH_THEME_GIT_PROMPT_DIRTY=""

ZSH_THEME_GIT_PROMPT_PREFIX="[%{$fg[blue]%}"
ZSH_THEME_GIT_PROMPT_SUFFIX="%{$reset_color%}]"
ZSH_THEME_GIT_PROMPT_UNTRACKED="%%"
ZSH_THEME_GIT_PROMPT_ADDED="a"
ZSH_THEME_GIT_PROMPT_MODIFIED="m"
ZSH_THEME_GIT_PROMPT_RENAMED="r"
ZSH_THEME_GIT_PROMPT_DELETED="d"
ZSH_THEME_GIT_PROMPT_UNMERGED="u"

#rvm variables
local rvm='%{$fg[magenta]%}[$(~/.rvm/bin/rvm-prompt)]%{$reset_color%}'






PROMPT="${dir}${git}"
RPROMPT="${return_code}"
