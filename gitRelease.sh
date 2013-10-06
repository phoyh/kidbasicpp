#parameter: [Version]
#Pre-requisites: all commits on develop done
if [ $# != 1 ]
	then
		echo "No version ID provided"
		exit -1
fi
git checkout release
git merge develop --no-commit
rm Version.h~
mv Version.h Version.h~
sed s/"#define VERSION \"[^\"]*\""/"#define VERSION \"$1\""/ <Version.h~ >Version.h
git commit -a -m "Merged from develop for release $1"
git tag -a $1
bash oyhMake.sh
cp BASIC256 /share/kidbasic
git checkout develop
