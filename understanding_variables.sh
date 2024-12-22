$IFS= "A"
set foo bar bam
echo “$@”
echo "$*"
unset IFS
echo "$*"
