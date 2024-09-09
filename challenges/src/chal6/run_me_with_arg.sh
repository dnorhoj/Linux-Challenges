#!/bin/bash
if [ "$#" -ne 1 ]; then
  echo "Give exactly one argument" 1>&2
  exit 1
fi
CHK="$1"
MD5=`echo -n "$CHK" | md5sum`
#echo "$MD5"
if [ "${MD5:0:32}" = "c8dae1c50e092f3d877192fc555b1dcf" ]; then
  MD5=`echo -n "${CHK}X_X" | md5sum`
  PAS=`echo "${MD5:0:32}2020" | xxd -r -p | base64`
  echo "Correct, your password is $PAS"
else
  echo "Nope"
fi
