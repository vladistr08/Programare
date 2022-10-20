echo "First argument is the PATH where you want to copy your files!"

cpDir=$1
shift

if [ -d $cpDir ]
then
    for arg in $@
    do
        if [ -f $arg ]
        then
            cp $arg $cpDir
            echo "$arg file copyed succesfully!"
        else
            echo "$arg does not exist!"
        fi
    done
else
    echo "First argument is invalid!"
fi
