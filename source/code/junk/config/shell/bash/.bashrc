########################################################################################################
# Alright, so when does this .bashrc file get executed?                                                #
# It gets executed every time a shell is used.                                                         #
# When is a shell used?                                                                                #
# Well for my purposes, a shell will be used during the following scenarios:                           #
#                                                                                                      #
# --> The normal way.  I open a GUI terminal emulator and use                                          #
#     that terminal program to do shell / command line stuff                                           #
#                                                                                                      #
# --> Another program uses a shell.                                                                    #
#    If another program uses a shell, the current shell will spawn                                     #
#    a new child shell.  In that scenario, we will want to take a different action,                    #
#    and that is specified in the first command of this script.                                        #
#                                                                                                      #
# --> Lastly, if I ssh or putty into this machine, the .bashrc is NOT called by default.               #
#     Instead, the .bash_profile is called. It doesn't matter though,  because the only                #
#     thing I tell .bash_profile do,  is call this file here.  Therefore, logging in through           #
#     ssh should be the same as being on this machine (bullet 1 and 3 should have the same behavior)   #
########################################################################################################

# If not running interactively, don't do anything.
# What does interactively mean exactly? The interactive shell,
# is the shell you actually see and use in the terminal.  When other programs
# execute system things,  they will get their own shell and they are considered
# NOT interactive.  Since they are not interactive, we don't need to apply all the behavior.
[ -z "$PS1" ] && return

#I like starting on the Desktop
cd Desktop > /dev/null 2>&1;

#all of the other customizations get pulled in from these files
source $HOME/.bashrc_impl/alias.sh
source $HOME/.bashrc_impl/defaults.sh
source $HOME/.bashrc_impl/functions.sh
source $HOME/.bashrc_impl/exports.sh
source $HOME/.bashrc_impl/prompt.sh
