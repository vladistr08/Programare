for arg in $@
do
    if [ -f $arg ]
    then
        cp $arg /home/istra/Programare/bash/test/
        echo "$arg file copyed to /home/istra/Programare/bash/test/ succesfull!"
    else
        echo "$arg file does not exist!"
    fi
done