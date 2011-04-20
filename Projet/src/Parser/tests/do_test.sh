#!/bin/bash

# Path relative to this file's path
PARSER=../bin/parser
function major_sep ()
{
	echo "=================================================="
}
function minor_sep ()
{
	echo "--------------------------------------------------"
}
function find_xml_files ()
{
	find . -maxdepth 1 -name '*.xml' -type f | sort
}
function output_redirection ()
{
# $1 : file beeing tested
#	echo '1>/dev/null' '2>&1'
echo
}

for bundle in $(find . -maxdepth 1 -name 'bundle*' -type d | sort)
do
	major_sep
	echo "Testing $bundle"
	cd $bundle

	minor_sep
	if cd valid
	then
		for valid in $(find_xml_files)
		do
			eval ../../$PARSER $valid $(output_redirection $PWD/$valid)
			if (( $? == 0 ))
			then
				echo "File $bundle/valid/$valid: ok"
			else
				echo "File $bundle/valid/$valid: FAILURE"
			fi
		done
		cd ..
	else
		echo "No 'valid' directory."
	fi

	minor_sep
	if cd invalid
	then
		for invalid in $(find_xml_files)
		do
			eval ../../$PARSER $invalid $(output_redirection $PWD/$invalid)
			if (( $? == 0 ))
			then
				echo "File $bundle/invalid/$invalid: FAILURE"
			else
				echo "File $bundle/invalid/$invalid: ok"
			fi
		done
		cd ..
	else
		echo "No 'invalid' directory."
	fi

	cd ..
done
