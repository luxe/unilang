printf_new() {
 str=$1
 num=$2
 v=$(printf "%-${num}s" "$str")
 PS1="${v// /$str}"
}

   #include the branch detection file
   source ~/.bashrc_impl/git/.git-prompt.sh


#this is some built-in bash thing that will ensure the prompt is upated every time=
PROMPT_COMMAND=set_prompt


set_prompt () {

    #uncomment to draw line across terminal"
    #printf_new "═" $COLUMNS;
    #PS1+="\r"
    
    #adds the author and repo name (if inside a git repository)
    PS1='$(__git_ps1 "[\[\x1b[38;5;33m\]$(git-repo-printer --author --repo)\[\x1b[0m\]]")'
    
    #add the current branch (if inside a git repository)
    PS1+='$(__git_ps1 "[\[\x1b[38;5;33m\]%s\[\x1b[0m\]]")'

    #shows the path
    PS1+="[\[\e[38;5;144m\]\w"

    #reset colors
    PS1+="\[\033[0m\]]\n"
}
