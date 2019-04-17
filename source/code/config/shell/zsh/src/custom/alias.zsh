####################
# DIRECTORY MOVING #
####################
alias ..='cd ..'
alias ...='cd ../..'
alias ....='cd ../../..'
alias .....='cd ../../../..'
alias 'bk=cd $OLDPWD'


####################
# LOOKING AT FILES #
####################
#adds colors automatically and provide other flags I'd like by default

#looking at files and moving around the directory
#alias ls='ls -Al --color=auto --sort=extension'
alias grep='grep --color=auto'
alias fgrep='fgrep --color=auto'
alias egrep='egrep --color=auto'
alias dir='dir --color=auto'
alias vdir='vdir --color=auto'
    
#things I accidently mistype, but they wouldn't do anything anyway,
#so they might as well do what I usually intend
alias l=ls #sometimes I'm typing real quick and miss the s
alias s=ls #sometimes I'm typing real quick and miss the l


##############
# USING MAKE #
##############
#I always forget to run make faster
#sometimes build break like this, but that's the build systems fault
alias make-slow='clear && make -j 1'
alias make='clear && make -j 6'
alias make-fast='clear && make -j `number-of-cores`'

##############
# USING GIT #
##############
#A lot of git commands aren't any program names I would be using outside of git anyway.
#I'll just shorten them so that I'm not typing git all of the time.
alias push='git push'
alias pull='git pull'
alias add='git add'
alias commit='git commit -m'
alias commit-all='git add -A:/ git commit -am'
alias clone='git clone'
alias status='git status'
alias branch='git branch'
alias branches='git branch'
alias checkout='git checkout'

#overwrite an oh-my-zsh alias plugin
alias rm='rm'

#working on projects
alias cpp-code='subl -n `ls-cpp`'
alias full-clean-and-build='make clean; git-it --clean --all; git-it --local-pulls --all; make'

alias uppercase='tr "[:lower:]" "[:upper:]"'
alias lowercase='tr "[:upper:]" "[:lower:]"'

###############################
# compadibility with other OS #
###############################
alias pbcopy='xclip -selection clipboard'
alias pbpaste='xclip -selection clipboard -o'

#resize terminal
alias big="printf '\e[8;70;200t'"
alias small="printf '\e[8;22;100t'"

# because I can't figure out how to actually extract binaries out of bazel in a reasonable way
# TODO: don't use full path
alias unilang="~/Desktop/unilang/source/bazel-bin/code/transcompilers/unilang/main/unilang-transcompiler"