####################
# LOOKING AT FILES #
####################
	#adds colors automatically and provide other flags I'd like by default
	
	#looking at files and moving around the directory
	alias ls='ls -Al --color=auto --sort=extension'
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
	alias make='clear && make -j'

##############
# USING GIT  #
##############
	#A lot of git commands aren't any program names I would be using outside of git anyway.
	#I'll just shorten them so that I'm not typing git all of the time.
	alias push='git push'
	alias pull='git pull'
	alias add='git add'
	alias commit='git commit -m'
	alias clone='git clone'
	alias status='git status'
	alias branch='git branch'
	alias branches='git branch'
	
#####################
# MY OWN FUNCTIONS  #
#####################
	alias start_notes='cd `start_notes_folder_printer`'

