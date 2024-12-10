# sputil for linux!
To install you can use the generic one i made or customize it to your likeing.
## installing with my makefile:
config config.c then do
```
sudo make install
```
and boom! it will be installed to /bin
## updateing
remove th prev source dir then git clone it again then do:
```
sudo make clean install
```
it has removed prev install and now has the new one
## removing
```
sudo make clean
```
it should remove the install!
## Dependancys (by default):
- gnu's getopt (saying this cuz idk if it is pre-installed or not)
- gcc (default for the makefile but clang does work too)
- make
## usage:
to update the void system simply do
```
sputil -s
```
to install something do:
```
sputil -i (app)
```
to uninstall:
```
sputil -r (app)
```
to see options do:
```
sputil -h
```
## why does this exist:
i wanted to try out getopt and do a simple coding project. there will be versions for gentoo and arch later! i have plans to later add config file.


