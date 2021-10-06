#this will dump an entire json object for a particular code file.
#if another program or language uses thisll have to be able to parse the json
#argv[1] - username
#argv[2] - password
#argv[3] - code snippet id
from ideone import Ideone
import sys
import os

#this function creates a file based on the second parameter key
def Create_File(file_name,key_value):
	f = open('src/getter-src/data/info_dump/ideone/' + file_name + "-" + sys.argv[4], 'w')
	data = i.submission_details(sys.argv[3])[key_value]
	f.write(str(data))
	f.close()

#validate credentials
i = Ideone(sys.argv[1], sys.argv[2])

#source code
Create_File('source_code','source')

#input (stdin)
Create_File('stdin','input')

#output (stdout)
Create_File('stdout','output')

#output (stderr)
Create_File('stderr','stderr')

#error (should always be OK)
Create_File('error','error')

#status (should always be zero)
#if not zero, a request will have to be re-made
#we don't care what the other numbers mean, because 0 is the only one that says the submitted code has finished processing
Create_File('status','status')

#signal (what the program gives back)
Create_File('signal','signal')

#result (SUCCESS/FAILURE/etc. expressed as a number)
Create_File('result','result')