#!/bin/sh
#  This is a simple script to facilitate trying out some basic Lisp.
#  Just place a series of Lisp expressions into the file (one per line)
#  and then invoke this script by name the file after typing "sh trylisp.sh"
#  All this does is add a directive to print out the results, and then
#  call the Emacs software to run it (lacking a direct Lisp interpreter)
if test $# -ne 1; then
   echo "Syntax:  sh trylisp.sh < lisp file >"
   exit
fi
awk '{ print "( print " $0 ")" }' $1 > $1.el
emacs --script $1.el -Q
