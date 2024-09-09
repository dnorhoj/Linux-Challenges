#!/bin/bash
CHK="/home/chal8/secret/directory/contains/nonempty_file"
if [ ! -f "$CHK" ]; then
  echo "File $CHK does not exist, or is not regular file" 1>&2
  exit 1
elif [ ! -s "$CHK" ]; then
  echo "File $CHK is empty" 1>&2
  exit 1
fi
MD5=`echo -n "$CHK" | md5sum`
#echo "$MD5"
if [ "${MD5:0:32}" = "46d49a3eb1564d71cfbe95afeaef80e7" ]; then
  MD5=`echo -n "${CHK}X_X" | md5sum`
  PAS=`echo "${MD5:0:32}2020" | xxd -r -p | base64`
  echo "Correct, your password is $PAS"
else
  echo "Nope"
fi
