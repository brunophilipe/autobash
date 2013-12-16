#autobash

Bash file library.

---

With autobash you can place all the bash files you have to use frequently into a single place and run any of them from a simple terminal command.

##How to use

autobash has a simple syntax:

`$ autobash [flag] file_name;`

The available flags are:

* (no flag): run the parameter bash file with the matching name without an extension;
* `-a`: add the parameter file to the autobash library, its name will be the filename without the extension;
* `-r`: remove the file with the name equal to the parameter from the autobash library;
* `-l`: list all files currently in the autobash library;
* `-h`: shows the help page;

If you wish you can use the longer versions of the flags:

* `--add`;
* `--remove`;
* `--list`;
* `--help`;

---

##Installation

autobash is very simple to build and install. Just open the extracted folder and:

* `make`
* `make install` - sudo may be necessary in some OSses, like Linux and Ubuntu

autobash has been tested on Mac OS 10.9 and Ubuntu 12.04 LTS.

---

##License

This project is licensed under the [GLPv3](http://www.gnu.org/licenses/gpl-3.0-standalone.html) license. Although not necessary, any feedback or attribution on the use of this software is welcome!