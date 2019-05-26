#make terminal colored
if [ "$TERM" == "xterm" ]; then
    export TERM=xterm-256color
fi

# don't put duplicate lines or lines starting with space in the history.
export HISTCONTROL=erasedups:ignoreboth

# set history sizes
export HISTSIZE=1000
export HISTFILESIZE=2000

#path variables
path_add_back() {
    if [ -d "$1" ] && [[ ":$PATH:" != *":$1:"* ]]; then
        PATH="${PATH:+"$PATH:"}$1"
    fi
}
path_add_front() {
    if [ -d "$1" ] && [[ ":$PATH:" != *":$1:"* ]]; then
        PATH="$1:$PATH"
    fi
}

#other places to find binaries
path_add_front $HOME/.bin

#other places to find libraries
#idk...
