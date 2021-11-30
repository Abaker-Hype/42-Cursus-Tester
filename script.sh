#!/bin/bash

#Libs locations
LIBFT=../libft/
PRINTF=../ft_printf/
GNL=../getnextline/

#Dont touch anything under this (Unless you know what your are doing and are adding in a new project to test)
USRFLS=./userfiles/

#Strings
PATHERROR="Error Missing/Incorrect Path in script.sh"

#Funcs
checkpath(){
	if [ ! $1 ] || [ $1 == "../" ] || [ ! -d $1 ] || [ ! "$(ls -A $1)" ]; then
		echo "${PATHERROR}"
		exit 1
	fi
	echo $1
}


#Script Start
if (($# != 1)); then exit 1; fi
case $1 in
	(libft)
		LOC=$(checkpath ${LIBFT});;
	(printf)
		LOC=$(checkpath ${PRINTF});;
	(gnl)
		LOC=$(checkpath ${GNL});;
	(*)
		echo "Error No Valid Tester"
		exit 1;
esac
echo -n "Removing old files..."
rm -rf ${USRFLS}
echo "Done"
echo -n "Copying User Files..."
cp -a ${LOC} ${USRFLS}
echo "Done"
echo -n "Inserting Macros to User Headers..."
HEADERS=$(find ${USRFLS} -type f -name '*.h')
if [[ -n "$HEADERS" ]]; then
	for x in ${HEADERS}
	do
		printf "\n#include \"macros.h\"" >> $x
		DIR=`dirname $x`
		`cp -a ./includes/macros.h ${DIR}`
	done
fi
echo "Done"
