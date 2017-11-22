#!/usr/bin/python

import os, sys
import fnmatch
import subprocess
from subprocess import PIPE
import filecmp
import locale

__encoding = locale.getdefaultlocale()[1]


def testCode( retcode, msg ):
  if retcode > 0:
    print msg
    sys.exit( 1 )

testDir = os.path.join( os.getcwd(), 'cases')
if not os.path.isdir( testDir ):
  print testDir, "isn't a directory"
  sys.exit( 1 )

executable = os.path.join(os.getcwd(), "run")
if not os.path.isfile( executable ):
  retcode = subprocess.call("make",shell=True)
  testCode( retcode, "\tFAILED to make the scanner" )

files = os.listdir( testDir )
for x in files:
  if fnmatch.fnmatch(x, "*.py"):
	python_file_to_parse = os.path.join(testDir, x)
	
	our_process = subprocess.Popen( ["./run", python_file_to_parse] , stdout=PIPE, stderr=PIPE, stdin=PIPE)
	our_output = our_process.communicate()
	our_output = sorted(our_output[0].split("\n"))

	mccabe_process = subprocess.Popen( ["python", python_file_to_parse], stdout=PIPE, stderr=PIPE, stdin=PIPE)	
	mccabe_output = mccabe_process.communicate()
	mccabe_output = sorted(mccabe_output[0].split("\n"))

	if our_output != mccabe_output: 
		print "\tTEST CASE FAILED", x
	else :
		print "testcase:", x, "passed"

