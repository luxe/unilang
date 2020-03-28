
#if I putty or ssh in, this file will be run.
#well I just want the same behaviour as being at the actual terminal, so run the bashrc
if [ -f ~/.bashrc ]; then
  . ~/.bashrc
fi
