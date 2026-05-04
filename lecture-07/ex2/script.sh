#!/bin/bash
rm -rf lab7

mkdir lab7
cd lab7

touch notex.txt script.sh

chmod 640 notex.txt

chmod u+rwx script.sh
chmod g+rx script.sh
chmod o-rwx script.sh

ls -l