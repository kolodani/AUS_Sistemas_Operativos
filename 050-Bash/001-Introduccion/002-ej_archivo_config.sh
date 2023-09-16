# If running interactively, then:
if [ "$PS1" ]; then
    # don't put duplicate lines in the history.
    # export HISTCONTROL=ignoredups

    # enable color support of ls and also add handy aliases
    eval `dircolors -b`
    alias ls='ls --color=auto'

    # some more ls aliases
    #alias ll='ls -l'
    #alias la='ls -A'
    #alias l='ls -CF'

    # set a fancy prompt
    PS1='\u@\h:\w\$ '

    # If this is an xterm set the title to user@host:dir
    #case "$TERM" in
    #xterm*)
    # PROMPT_COMMAND='echo -ne "\033]0;${USER}@${HOSTNAME}: ${PWD}\007"
    #    ;;
    #*)
    #    ;;
    #esac
fi
