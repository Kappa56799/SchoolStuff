#!/bin/bash
while true;
HISTFILE=~/.bash_history
set -o history
do

  echo "\n* Bash Commands *"
  echo "1. List Files"
  echo "2. Show Free disk space"
  echo "3. Show System path"
  echo "4. Display command history"
  echo "5. Backup Files"
  echo "6. Exit"

  read input

  case $input in
    1) echo "These are the current files in your directory:"; ls -a;;
    2) echo "This is the amount of disk space you have left:"; df -H;;
    3) echo "Your system path is:"; pwd;;
    4) echo "Your command history is:"; history 5;;
    5) echo "Enter your directory you want to backup in format /your/directory/here: "; read directory; mkdir ~/BackupFolder;cd $directory; cp -r $directory ~/BackupFolder; ls -a ;;
    6) exit 1;;
    *) echo "Invalid Input Try Again"
  esac
done
