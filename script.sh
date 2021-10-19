#!/bin/bash

#Libs locations
LIBFT=../libft/
PRINTF=../ft_printf/
GNL=../getnextline/

#Dont touch anything under this (Unless you know what your are doing and are adding in a new project to test)
USRFLS=./userfiles/
USRHDRS=./userheaders/

#Strings
PATHERROR="Error Missing/Incorrect Path in script.sh"

#Funcs
checkpath(){
	if [ ! $1 ] || [ $1 == "../" ] || [ ! -d $1 ] || [ ! "$(ls -A $1)" ]; then
		echo "${PATHERROR}"
		exit 1
	fi
}


#Script Start
if (($# != 1)); then exit 1; fi
case $1 in
	(libft)
		checkpath ${LIBFT};;
	(printf)
		checkpath ${PRINTF};;
	(gnl)
		checkpath ${GNL};;
	(*)
		echo "Error No Valid Tester"
		exit 1;
esac
echo -n "Removing old files..."
rm -rf ${USRFLS} ${USRHDRS}
echo "Done"
echo -n "Copying User Files..."
case $1 in
	(libft)
		cp -a ${LIBFT} ${USRFLS};;
	(printf)
		cp -a ${PRINTF} ${USRFLS};;
	(gnl)
		cp -a ${GNL} ${USRFLS};;
	(*)
		;;
esac
echo "Done"
echo -n "Inserting Macros to User Headers..."
mkdir ${USRHDRS}
HEADERS=$(find ${USRFLS} -type f -name '*.h')
if [[ -n "$HEADERS" ]]; then
	for x in ${HEADERS}
	do
		echo "#include \"macros.h\"" >> $x
		`cp -a $x ${USRHDRS}`
		DIR=`dirname $x`
		`cp -a ./includes/macros.h ${DIR}`
	done
fi
echo "Done"
