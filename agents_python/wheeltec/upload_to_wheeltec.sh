#! /bin/bash

cur_dir=${PWD##*/} 

DIRNAME="wheeltec"

if [[ $cur_dir != $DIRNAME ]]; then
    echo "Please run it from '${DIRNAME}' directory. Abort..."
    exit 1
fi

cd ../../

# ssh wheeltec@192.168.1.80 
# pass 12345678 

USER=wheeltec
ADDR=192.168.1.80

rsync -av --exclude '__pycache__' --exclude '.venv' agents_python/iqrdevice $USER@$ADDR:~/agents_python/
rsync -av --exclude '__pycache__' --exclude '.venv' agents_python/$DIRNAME $USER@$ADDR:~/agents_python/
rsync -av agents_python/requirements.txt $USER@$ADDR:~/agents_python/

ssh $USER@$ADDR 'sudo systemctl restart robot.${DIRNAME}.service'
echo $?