 if sort -C <&0 ; then
	# return code 0
  echo "sorted"
else
  # return code not 0
  echo "not sorted"
fi
