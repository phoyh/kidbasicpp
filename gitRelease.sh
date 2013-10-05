#parameter: [Version]
#Pre-requisites: all commits on develop done
if [ $# != 1 ]
	then
		echo "No version ID provided"
		exit -1
fi
git checkout release
git merge develop
git tag -a $1
git checkout develop
