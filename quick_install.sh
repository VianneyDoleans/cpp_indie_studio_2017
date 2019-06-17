#!/bin/bash

####################
##      ENV       ##
####################

function export_env {
  echo "Exporting env variables"

  export INSTALL_DIR=`pwd`
  export LOG_PATH="`pwd`/errors.logs"

  export PATH="$INSTALL_DIR/bin:$PATH"
}

function export_env_bash
{
  echo "export PATH=\"${INSTALL_DIR}/bin:${PATH}\"" >> ~/.bashrc
  echo "export LD_LIBRARY_PATH=\"${INSTALL_DIR}/lib\"" >> ~/.bashrc
}

function build_irrlicht {
  echo "Building Irrlicht"

  unzip -o Irrlicht.zip 2>> ${LOG_PATH} 1> /dev/null
  sed -e "s@#define _IRR_LINUX_X11_VIDMODE_@//#define _IRR_LINUX_X11_VIDMODE_@g" -i irrlicht-1.8.4/include/IrrCompileConfig.h # disable full screeen capability

  cd irrlicht-1.8.4/source/Irrlicht
  make CXXINCS="-I../../include -Izlib -Ijpeglib -Ilibpng -I${INSTALL_DIR}/include" LDFLAGS="-L${INSTALL_DIR}lib" sharedlib
  make CXXINCS="-I../../include -Izlib -Ijpeglib -Ilibpng -I${INSTALL_DIR}/include" LDFLAGS="-L${INSTALL_DIR}lib"
  make CXXINCS="-I../../include -Izlib -Ijpeglib -Ilibpng -I${INSTALL_DIR}/include" LDFLAGS="-L${INSTALL_DIR}lib" INSTALL_DIR=${INSTALL_DIR}/lib install
  cd ../../..
}

####################
##    EXECUTION   ##
####################

mkdir -p install
cd install
cp ../Irrlicht.zip .

export_env

# Stop script on error
set -e

build_irrlicht

export_env_bash


echo "SUCCESS"
