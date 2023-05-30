#!/bin/bash
history=$(cat ~/.bash_history)
while true;
do

  #menu display
  echo "* Bash Commands *"
  echo "1. List Files"
  echo "2. Show Free disk space"
  echo "3. Show System path"
  echo "4. Display command history"
  echo "5. Backup Files"
  echo "6. Exit"

  #reads in input from the user
  read input

  #case statment to process user input
  case $input in
    1) echo "These are the current files in your directory:"; ls -a; echo;;
    2) echo "This is the amount of disk space you have left:"; df -h; echo;;
    3) echo "Your system path is:"; pwd; echo;;
    4) echo "Your command history is:"; echo $history ;echo ;;
    5) echo "Enter your directory you want to backup in format /your/directory/here: "; read directory; mkdir ~/BackupFolder;cd $directory; cp -r $directory ~/BackupFolder; ls -a ;echo;;
    6) exit 1;;
    *) echo "Invalid Input Try Again"; echo;;
  esac
done
