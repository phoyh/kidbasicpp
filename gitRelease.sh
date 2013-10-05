#parameter: [Version]
#Pre-requisites: all commits on develop done
if [ $# != 1 ]
	then
		echo "No version ID provided"
		exit -1
fi
git checkout release
git merge develop
rm Version.h~
mv Version.h Version.h~
sed s/"#define VERSION \"[^\"]*\""/"#define VERSION \"$1\""/ <Version.h~ >Version.h
git commit -a -m "Added release version information $1"
git tag -a $1
git checkout develop
