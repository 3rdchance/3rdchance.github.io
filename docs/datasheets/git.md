# use other key to push
 GIT_SSH_COMMAND="ssh -o IdentitiesOnly=yes  -i /Users/niuxilei/.thirdchance/id_rsa -F /dev/null -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no" git push

# git reset one local file to repos's state
git checkout HEAD -- ./bench/main.cpp
