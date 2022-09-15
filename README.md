# Biest to python for vacuum field application (blueprinting virtual-casing repo)

## Installation
### C++ Executable
In addition to having C++ compiler that supports OpenMP, install FFTW and LAPACK libraries. Intel MKL provides both of them.
Also install cmake package. The CMake setup is written in a monolithic way so we have to install python dependencies also,
even though they are strictly not required. On the python side, we require python header files and Numpy. All of them can be installed by using pip.

    pip install cmake numpy
  
Create a folder called ``build`` and switch to ``build`` directory. 

    mkdir build; cd build
    
Run cmake from within the build folder.

    cmake ..
  
If the above command succeeds, we can go to the next step. Build the shared library for the python interface

    make 
  
If the compilation is successful, you will have a ``*.so`` in the ``build`` folder. This file  already allows to  call the routines from python.


### Install as python package

We also need ninja package, which can be installed with pip

    pip install ninja
  
Then run 

    python setup.py install

