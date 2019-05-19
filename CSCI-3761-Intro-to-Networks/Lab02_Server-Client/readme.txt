Patrick Tate
CSCI 3761 Lab 2

Source files server side: server.c sample_server_file.txt makefile

Source files client side: client.c test_file_c.txt makefile

*** Program Status: compiles and runs on the csegrid ***

*** Running the program instructions ***

1. navigate into the server folder
2. type 'make'
3. type './server' and server will start with message that it is listening for clients
4. open a separate terminal and navigate into the client folder
5. type 'make'
6. type './client csci-gnode-01'
	*** csci-gnode-01 is just an example, the exact number may vary depending on where server
	    is running, check the server terminal for the exact node ***
7. once the client is connected the user has a menu of options/commands they can enter

*** to end the server program enter "ctrl + c" ***

- for main menu command options type: help
- to display files in client directory type: ls
- to display current directory on client side type: pwd
- to display current directory on server side type: spwd
- to display files in server directory type: catalog
- to download file from server type: download
	- now enter filename: example.txt
	- now enter destination filename: downloaded_example.txt
- to upload new file to server type: upload
	- enter source filename: upload_file.txt
	- enter destination file name: new_upload_file.txt
- to disconnect from server type: bye
