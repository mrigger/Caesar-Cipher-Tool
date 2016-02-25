# Caesar Cipher Tool
Usually we see caesar cipher in crypto problems/races or in hackaflags. This tool was developed to help in this situations, make the crack proccess easier and faster.

## Usage
Caesar Cipher accepts some options, you can always see more information with:
```
$ caesar -h
$ caesar --help
```
### Input Text
The input text can be specified in two ways  
- Direct as argument:
```
$ caesar [text]
$ caesar "kimaiz kqxpmz bwwt"
```
- From file:
```
$ caesar -f [filename]
$ caesar --file [filename]
```
### Encrypt
Encrypt mode requires the key(shift value):
```
$ caesar "kimaiz kqxpmz bwwt" -k 12
$ caesar "kimaiz kqxpmz bwwt" --key 12
```

### Decrypt
For use the decrypt mode, option ```-d``` or ```--decrypt``` must be specified. The decrypt mode works in two ways:
- Brute force - This approach will try all possible keys and print the results:
```
$ caesar "kimaiz kqxpmz bwwt" -d
$ caesar "kimaiz kqxpmz bwwt" --decrypt
```
- With known key:
```
$ caesar "kimaiz kqxpmz bwwt" -d -k 8
$ caesar "kimaiz kqxpmz bwwt" --decrypt --key 12
```

## Setup
The setup bash script will compile and put the file in ```/usr/local/bin```. It must be executed as root for file manipulation in this directory.
### Options
Setup file can be edited to fit your needs. There are two options:
- PROGRAM_NAME:  
Default is ```caesar```. This is the name that you will call on command line:
```
$ [selected name] [options]
```
- DEFAULT_BIN_DIRECTORY:  
Usually ```/usr/local/bin``` is in PATH, if not, edit the setup for your needs.

## License
This program is under GPLv3, see ```LICENSE``` for more details.
