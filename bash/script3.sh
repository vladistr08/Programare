for arg in $@
do
    if [ -f $arg ] && [ -w $arg ]
    then
        echo "$arg is a file that exists and has write permission!"
    elif [ -f $arg ]
    then
        echo "$arg file exists but has no write permission!"
    else
        echo "$arg is not a valid path!"
    fi
    
done