# SystemC SAM3X8E GPIO

SystemC repository for school project about SAM3X8E Architecture, focused on GPIO module


## About

* GPIO :
* TIMER :
* UART :
* PMC

## Installation

 You need to create a Makefile.in in your repository

 ```
	HOME_DIR=/home/<your_home_dir>
	SYSTEMC_HOME=$(HOME_DIR)/<sytemC_folder>/systemc-2.3.2
	LD_LIBRARY_PATH=$(SYSTEMC_HOME)/<systemC_lib_folder>

 ```

## Usage

Need SystemC Library available at http://www.accellera.org/downloads/standards/systemc

Instructions to build SystemC Lib :
 ```
cd systemc-2.3.2
mkdir build
cd build
cmake ../
make
sudo make install
sudo ldconfig
 ```

## Credits

F. Boizot, L. Boumah, J.F. Grandmougin, M. Fouillat, P. Lebeau, T. Marazano

## License

Free usage
