#!/bin/bash

if [ -f "$1" ]
then
	tac "$1" | sed 's/^/\t/' | awk '{ print; print ""  }' > tmp
	mv tmp "$1"
	echo "File has been prepared for the game"
else
	echo "Couldn't load the file, so I created it :)"
fi
