# git-bash-linux
git-bash-linux

# 在/etc/bashrc 和 ~/.bashrc 前面添加这些代码
```bash
function get_git_branch_now  {
        git branch --no-color 2> /dev/null | awk '/\*/{printf "\033[34m[>"$2"]\033[0m" }'
        return 0
}
function get_git_status_now {
        #合并冲突状态
		git status 2> /dev/null | grep -q "Unmerged paths" && echo -e '\033[41;37m*\033[0m' &&  return 0
		#未暂存状态
        git status 2> /dev/null | grep -qE "Changes not staged for commit|Changed but not updated" && echo -e '\033[31m*\033[0m' &&  return 0
        #未提交状态
		git status 2> /dev/null | grep -q "Changes to be committed" && echo -e '\033[33m*\033[0m' &&  return 0		
}
[ "$PS1" = "\\s-\\v\\\$ " ] && PS1="\[\e[36m\][\u\[\e[0m\]\[\e[5m\] \[\e[0m\]\h \[\e[32m\]\w\[\e[36m\]]\[\e[0m\]\$(get_git_branch_now)\$(get_git_status_now)\\$ "
```
****
# 在命令行中敲这些命令
```bash
git config --global color.status auto
git config --global color.diff auto
git config --global color.branch auto
git config --global color.interactive auto
```
****
# 在命令行中敲这些命令
```bash
git config --global alias.lg "log --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset'"
```
