#!/bin/bash

####################
##      ENV       ##
####################

function export_env {
  echo "Exporting env variables"

  export INSTALL_DIR=`pwd`
  export SOURCE_URL="https://eliastre100.fr/dep.tar.gz"
  export LOG_PATH="`pwd`/errors.logs"

  export PATH="$INSTALL_DIR/bin:$PATH"
  export PERL5LIB=`pwd`/perl-5.24.1/lib
  export PKG_CONFIG_PATH="$INSTALL_DIR/lib/pkgconfig/"

  export LUA_PATH=${INSTALL_DIR}

  export CPATH="$INSTALL_DIR/include"
  export LD_LIBRARY_PATH="$INSTALL_DIR/lib"
  export LIBRARY_PATH="$INSTALL_DIR/lib"
}

function export_env_bash
{
  echo "export PATH=\"${INSTALL_DIR}/bin:${PATH}\"" >> ~/.bashrc
  echo "export LD_LIBRARY_PATH=\"${INSTALL_DIR}/lib\"" >> ~/.bashrc
}


####################
##      DEP       ##
####################

function check_dependancies {
  echo "Checking dependancies"

  unzip -v 2>> errors.logs 1> /dev/null
  if [ $? != 0 ]; then
    echo "Cannot find unzip"
    exit 1
  fi

  tar --version 2>> errors.logs 1> /dev/null
  if [ $? != 0 ]; then
    echo "Cannot find tar"
    exit 1
  fi

  sed --version 2>> errors.logs 1> /dev/null
  if [ $? != 0 ]; then
    echo "Cannot find sed"
    exit 1
  fi

  curl --version 2>> errors.logs 1> /dev/null
  if [ $? != 0 ]; then
    echo "Cannot find curl"
    exit 1
  fi

  gcc -v 2>> /dev/null 1> /dev/null
  if [ $? != 0 ]; then
    echo "Cannot find gcc"
    exit 1
  fi

  g++ -v 2>> /dev/null 1> /dev/null
  if [ $? != 0 ]; then
    echo "Cannot find g++"
    exit 1
  fi

}

####################
##    DOWNLOAD    ##
####################

function download_individual {
  curl -o Irrlicht.zip "https://kent.dl.sourceforge.net/project/irrlicht/Irrlicht%20SDK/1.8/1.8.4/irrlicht-1.8.4.zip" 1> /dev/null
  curl -o Messa.tar.gz "https://mesa.freedesktop.org/archive/mesa-17.0.5.tar.gz" 1> /dev/null
  curl -o Pkgconfig.tar.gz "https://pkg-config.freedesktop.org/releases/pkg-config-0.29.2.tar.gz" 1> /dev/null
  curl -o Pthreads-stubs.tar.bz2 "https://xcb.freedesktop.org/dist/libpthread-stubs-0.1.tar.bz2" 1> /dev/null
  curl -o Glproto.tar.bz2 "https://www.x.org/releases/individual/proto/glproto-1.4.14.tar.bz2" 1> /dev/null
  curl -o Libdrm.tar.gz "https://dri.freedesktop.org/libdrm/libdrm-2.4.80.tar.gz" 1> /dev/null
  curl -o Libpciaccess.tar.gz "https://www.x.org/archive/individual/lib/libpciaccess-0.13.5.tar.gz" 1> /dev/null
  curl -o Libdri2proto.tar.gz "https://www.x.org/archive/individual/proto/dri2proto-2.8.tar.gz" 1> /dev/null
  curl -o Libdri3proto.tar.gz "https://www.x.org/archive/individual/proto/dri3proto-1.0.tar.gz" 1> /dev/null
  curl -o Presentproto.tar.gz "https://www.x.org/archive/individual/proto/presentproto-1.1.tar.gz" 1> /dev/null
  curl -o Libxcb.tar.gz "https://xcb.freedesktop.org/dist/libxcb-1.11.1.tar.gz" 1> /dev/null
  curl -o Python.tar.gz "https://www.python.org/ftp/python/2.7.13/Python-2.7.13.tgz" 1> /dev/null
  curl -o Zlib.tar.gz "https://netcologne.dl.sourceforge.net/project/libpng/zlib/1.2.11/zlib-1.2.11.tar.gz" 1> /dev/null
  curl -o Xslt.tar.gz "ftp://xmlsoft.org/libxslt/libxslt-1.1.29.tar.gz" 1> /dev/null
  curl -o Xml2.tar.gz "ftp://xmlsoft.org/libxslt/libxml2-2.9.4.tar.gz" 1> /dev/null
  curl -o Xcbproto.tar.gz "https://xcb.freedesktop.org/dist/xcb-proto-1.11.tar.gz" 1> /dev/null
  curl -o Xau.tar.bz2 "https://www.x.org/archive/individual/lib/libXau-1.0.8.tar.bz2" 1> /dev/null
  curl -o Dmxproto.tar.gz "https://www.x.org/archive/individual/proto/dmxproto-2.3.tar.gz" 1> /dev/null
  curl -o Xproto.tar.gz "https://www.x.org/archive/individual/proto/xproto-7.0.31.tar.gz" 1> /dev/null
  curl -o Xshmfence.tar.bz2 "http://www.paldo.org/paldo/sources/xshmfence/libxshmfence-1.2.tar.bz2" 1> /dev/null
  curl -o X11.tar.gz "https://www.x.org/archive/individual/lib/libX11-1.6.5.tar.gz" 1> /dev/null
  curl -o Xextproto.tar.gz "https://www.x.org/archive/individual/proto/xextproto-7.3.0.tar.gz" 1> /dev/null
  curl -o Xtrans.tar.gz "https://www.x.org/archive/individual/lib/xtrans-1.3.5.tar.gz" 1> /dev/null
  curl -o Kbproto.tar.gz "https://www.x.org/archive/individual/proto/kbproto-1.0.7.tar.gz" 1> /dev/null
  curl -o InputProto.tar.gz "https://www.x.org/archive/individual/proto/inputproto-2.3.tar.gz" 1> /dev/null
  curl -o Perl.tar.gz "http://www.cpan.org/src/5.0/perl-5.24.1.tar.gz" 1> /dev/null
  curl -o Libxext.tar.gz "https://www.x.org/archive/individual/lib/libXext-1.3.3.tar.gz" 1> /dev/null
  curl -o Xdamage.tar.gz "https://www.x.org/archive/individual/lib/libXdamage-1.1.4.tar.gz" 1> /dev/null
  curl -o Damageproto.tar.gz "https://www.x.org/archive/individual/proto/damageproto-1.2.1.tar.gz" 1> /dev/null
  curl -o Xfixes.tar.gz "https://www.x.org/archive/individual/lib/libXfixes-5.0.3.tar.gz" 1> /dev/null
  curl -o Fixesproto.tar.gz "https://www.x.org/archive/individual/proto/fixesproto-5.0.tar.gz" 1> /dev/null
  curl -o Expat.tar.bz2 "https://netcologne.dl.sourceforge.net/project/expat/expat/2.2.0/expat-2.2.0.tar.bz2" 1> /dev/null
  curl -o Omxil-lellagio.tar.gz "https://kent.dl.sourceforge.net/project/omxil/omxil/Bellagio%200.9.3/libomxil-bellagio-0.9.3.tar.gz" 1> /dev/null
  curl -o M4.tar.gz "http://ftp.gnu.org/gnu/m4/m4-1.4.9.tar.gz" 1> /dev/null
  curl -o Autoconf.tar.xz "http://ftp.gnu.org/gnu/autoconf/autoconf-2.69.tar.xz" 1> /dev/null
  curl -o Llvm.tar.xz "http://releases.llvm.org/4.0.0/llvm-4.0.0.src.tar.xz" 1> /dev/null
  curl -o Cmake.tar.gz "https://cmake.org/files/v3.8/cmake-3.8.0.tar.gz" 1> /dev/null
  curl -o Libc.tar.gz "http://fr.mirror.babylon.network/gnu/libc/glibc-2.23.tar.gz"  1> /dev/null
  curl -o Boost.tar.gz "https://freefr.dl.sourceforge.net/project/boost/boost/1.47.0/boost_1_47_0.tar.gz" 1> /dev/null
  curl -o Lua.tar.gz "https://www.lua.org/ftp/lua-5.1.tar.gz" 1> /dev/null
  curl -o LuaBind.tar.gz "https://netix.dl.sourceforge.net/project/luabind/luabind/0.9.1/luabind-0.9.1.tar.gz" 1> /dev/null
  curl -o Readline.tar.gz "ftp://ftp.gnu.org/gnu/readline/readline-6.3.tar.gz" 1> /dev/null
  curl -o BoostBuild.tar.gz "https://codeload.github.com/boostorg/build/tar.gz/boost-1.60.0" 1> /dev/null
  curl -o SFML.zip "http://mirror0.sfml-dev.org/files/SFML-2.4.2-sources.zip" 1> /dev/null
  curl -o Xrandr.tar.gz "http://security.debian.org/debian-security/pool/updates/main/libx/libxrandr/libxrandr_1.3.2.orig.tar.gz" 1> /dev/null
  curl -o RandrProto.tar.gz "http://artfiles.org/x.org/pub/individual/proto/randrproto-1.5.0.tar.gz" 1> /dev/null
  curl -o Xrender.tar.gz "https://launchpadlibrarian.net/1284117/xrender_0.9.0.orig.tar.gz" 1> /dev/null
  curl -o RenderProto.tar.gz "https://www.x.org/archive/individual/proto/renderproto-0.11.tar.gz" 1> /dev/null
  curl -o LibXrender.tar.gz "http://security.debian.org/debian-security/pool/updates/main/libx/libxrender/libxrender_0.9.7.orig.tar.gz" 1> /dev/null

}

function download_all {
echo ${SOURCE_URL}
  curl -o dep.tar.gz ${SOURCE_URL}
  tar -zxf dep.tar.gz
  rm dep.tar.gz
}

function download_dependancies {
  echo "Downloading dependencies"
  #download_all
  download_individual
}

####################
##     INSTALL    ##
####################

function build_pkg_config {
  echo "Building pkg-config"

  tar -zxf Pkgconfig.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd pkg-config-0.29.2
  ./configure --prefix=${INSTALL_DIR} --with-internal-glib 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf pkg-config-0.29.2 Pkgconfig.tar.gz
}

function build_pthreads_stubs {
  echo "Building pthreads-stubs"

  tar -jxf Pthreads-stubs.tar.bz2 2>> ${LOG_PATH} 1> /dev/null
  cd libpthread-stubs-0.1
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf libpthread-stubs-0.1 Pthreads-stubs.tar.bz2
}

function build_glproto {
  echo "Building glproto"

  tar -jxf Glproto.tar.bz2 2>> ${LOG_PATH} 1> /dev/null
  cd glproto-1.4.14
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf glproto-1.4.14 Glproto.tar.bz2
}

function build_pciaccess {
  echo "Building pciaccess"

  tar -zxf Libpciaccess.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd libpciaccess-0.13.5
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf libpciaccess-0.13.5 Libpciaccess.tar.gz
}

function build_libdrm {
  echo "Building libdrm"

  tar -zxf Libdrm.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd libdrm-2.4.80
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf libdrm-2.4.80 Libdrm.tar.gz
}


function build_dri2proto {
  echo "Building dri2proto"

  tar -zxf Libdri2proto.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd dri2proto-2.8
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf dri2proto-2.8 Libdri2proto.tar.gz
}

function build_dri3proto {
  echo "Building dri3proto"

  tar -zxf Libdri3proto.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd dri3proto-1.0
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf dri3proto-1.0 Libdri3proto.tar.gz
}

function build_present_proto {
  echo "Building PresentProto"

  tar -zxf Presentproto.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd presentproto-1.1
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf presentproto-1.1 Presentproto.tar.gz
}

function build_zlib {
  echo "Building Zlib"

  tar -zxf Zlib.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd zlib-1.2.11
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf zlib-1.2.11 Zlib.tar.gz
}

function build_python {
  echo "Building Python"

  tar -zxf Python.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd Python-2.7.13
  ./configure --prefix=${INSTALL_DIR} --enable-shared 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf Python-2.7.13 Python.tar.gz
}

function build_xml2 {
  echo "Building Xml2"

  tar -zxf Xml2.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd libxml2-2.9.4
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf libxml2-2.9.4 Xml2.tar.gz
}

function build_xslt {
  echo "Building Xslt"

  tar -zxf Xslt.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd libxslt-1.1.29
  touch libtoolT #fix for failed libtoolT
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH}  1> /dev/null
  cd ..
  rm -rf libxslt-1.1.29 Xslt.tar.gz
}

function build_xcb_proto {
  echo "Building Xcb-proto"

  tar -zxvf Xcbproto.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd xcb-proto-1.11
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf xcb-proto-1.11 Xcbproto.tar.gz
}

function build_dmx_proto {
  echo "Building DmXproto"

  tar -zxf Dmxproto.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd dmxproto-2.3
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf dmxproto-2.3 Dmxproto.tar.gz
}

function build_xproto {
  echo "Building Xproto"

  tar -zxf Xproto.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd xproto-7.0.31
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf xproto-7.0.31 Xproto.tar.gz
}

function build_xau {
  echo "Building Xau"

  tar -jxf Xau.tar.bz2 2>> ${LOG_PATH} 1> /dev/null
  cd libXau-1.0.8
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf libXau-1.0.8 Xau.tar.bz2
}

function build_xcb {
  echo "Building Xcb"

  tar -zxf Libxcb.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd libxcb-1.11.1
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf libxcb-1.11.1 Libxcb.tar.gz
}

function build_xshmdence {
  echo "Building Xshmfence"

  tar -jxf Xshmfence.tar.bz2 2>> ${LOG_PATH} 1> /dev/null
  cd libxshmfence-1.2
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf libxshmfence-1.2 Xshmfence.tar.bz2
}

function build_xextproto {
  echo "Building Xextproto"

  tar -zxf Xextproto.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd xextproto-7.3.0
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf xextproto-7.3.0 Xextproto.tar.gz
}

function build_xtrans {
  echo "Building Xtrans"

  tar -zxf Xtrans.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd xtrans-1.3.5
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf xtrans-1.3.5 Xtrans.tar.gz
}

function build_kbproto {
  echo "Building Kbproto"

  tar -zxf Kbproto.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd kbproto-1.0.7
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf kbproto-1.0.7 Kbproto.tar.gz
}

function build_input_proto {
  echo "Building Inputproto"

  tar -zxf InputProto.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd inputproto-2.3
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf inputproto-2.3 InputProto.tar.gz
}

function build_perl {
  echo "Building perl"

  tar -zxf Perl.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd perl-5.24.1
  ./configure.gnu --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf perl-5.24.1 Perl.tar.gz
}

function build_x11 {
  echo "Building X11"

  tar -zxf X11.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd libX11-1.6.5
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf libX11-1.6.5 X11.tar.gz
}

function build_xext {
  echo "Building Xext"

  tar -zxf Libxext.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd libXext-1.3.3
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf libXext-1.3.3 Libxext.tar.gz
}

function build_damage_proto {
  echo "Building Damageproto"

  tar -zxf Damageproto.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd damageproto-1.2.1
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf damageproto-1.2.1 Damageproto.tar.gz
}

function build_fixes_proto {
  echo "Building Fixesproto"

  tar -zxf Fixesproto.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd fixesproto-5.0
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf fixesproto-5.0 Fixesproto.tar.gz
}

function build_xfixes {
  echo "Building Xfixes"

  tar -zxf Xfixes.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd libXfixes-5.0.3
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf libXfixes-5.0.3 Xfixes.tar.gz
}

function build_xdamage {
  echo "Building Xdamage"

  tar -zxf Xdamage.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd libXdamage-1.1.4
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf libXdamage-1.1.4 Xdamage.tar.gz
}

function build_expat {
  echo "Building expat"

  tar -jxf Expat.tar.bz2 2>> ${LOG_PATH} 1> /dev/null
  cd expat-2.2.0
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf expat-2.2.0 Expat.tar.bz2
}

function build_m4 {
  echo "Building M4"

  tar -zxf M4.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd m4-1.4.9
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf m4-1.4.9 M4.tar.gz
}

function build_autoconf {
  echo "Building autoconf"

  tar -Jxf Autoconf.tar.xz 2>> ${LOG_PATH} 1> /dev/null
  cd autoconf-2.69
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf autoconf-2.69 Autoconf.tar.xz
}

function build_omxil_bellagio {
  echo "Building Omxil-bellagio"

  tar -zxf Omxil-lellagio.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd libomxil-bellagio-0.9.3
  sed -e s/-Werror//g -i configure.ac
  autoconf 2>> ${LOG_PATH} 1> /dev/null
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf libomxil-bellagio-0.9.3 Omxil-lellagio.tar.gz
}

function build_cmake {
  echo "Building Cmake"

  tar -zxf Cmake.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd cmake-3.8.0
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf cmake-3.8.0 Cmake.tar.gz
}

function build_llvm {
  echo "Building Llvm"

  tar -Jxf Llvm.tar.xz 2>> ${LOG_PATH} 1> /dev/null
  mkdir -p build
  cd build
  cmake -DBUILD_SHARED_LIBS=true DCMAKE_INSTALL_PREFIX:PATH=${INSTALL_DIR} ../llvm-4.0.0.src/ 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf build llvm-4.0.0.src Llvm.tar.xz
}

function build_mesa {
  echo "Building lib Mesa"

  tar -zxf Messa.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd mesa-17.0.5
  ./configure --prefix=${INSTALL_DIR} --with-internal-glib --enable-gallium-llvm 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf mesa-17.0.5 Messa.tar.gz
}

function build_irrlicht {
  echo "Building Irrlicht"

  unzip -o Irrlicht.zip 2>> "`pwd`/errors.logs" 1> /dev/null
  sed -e "s@#define _IRR_LINUX_X11_VIDMODE_@//#define _IRR_LINUX_X11_VIDMODE_@g" -i irrlicht-1.8.4/include/IrrCompileConfig.h # disable full screeen capability

  cd irrlicht-1.8.4/source/Irrlicht
  make CXXINCS="-I../../include -Izlib -Ijpeglib -Ilibpng -I${INSTALL_DIR}/include" LDFLAGS="-L${INSTALL_DIR}lib" sharedlib
  make CXXINCS="-I../../include -Izlib -Ijpeglib -Ilibpng -I${INSTALL_DIR}/include" LDFLAGS="-L${INSTALL_DIR}lib"
  make CXXINCS="-I../../include -Izlib -Ijpeglib -Ilibpng -I${INSTALL_DIR}/include" LDFLAGS="-L${INSTALL_DIR}lib" INSTALL_DIR=${INSTALL_DIR}/lib install
  cd ../../..
}

function build_randr_proto {
  echo "Building RandrProto"

  tar -zxf RandrProto.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd randrproto-1.5.0
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf randrproto-1.5.0 RandrProto.tar.gz
}

function build_renderproto {
  echo "Building RenderProto"

  tar -zxf RenderProto.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd renderproto-0.11
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf renderproto-0.11 RenderProto.tar.gz
}

function build_xrender {
  echo "Building Xrender"

  tar -zxf LibXrender.tar.gz 2>> ${LOG_PATH} 1> /dev/null
  cd libXrender-0.9.7/
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf libXrender-0.9.7 Xrender.tar.gz
}


function build_xrandr {
  echo "Building Xrandr"

  tar -zxf Xrandr.tar.gz  2>> ${LOG_PATH} 1> /dev/null
  cd libXrandr-1.3.2
  ./configure --prefix=${INSTALL_DIR} 2>> ${LOG_PATH} 1> /dev/null
  make install 2>> ${LOG_PATH} 1> /dev/null
  cd ..
  rm -rf libXrandr-1.3.2 Xrandr.tar.gz
}

function build_sfml {
  echo "Building SFML"

  unzip SFML.zip 2>> ${LOG_PATH} 1> /dev/null
  cd SFML-2.4.2
  cmake -DBUILD_SHARED_LIBS=true -DCMAKE_INSTALL_PREFIX:PATH=${INSTALL_DIR} . 2>> ${LOG_PATH} 1> /dev/null
  make install
  cd ..
  rm -rf SFML.zip SFML-2.4.2
}

####################
##    EXECUTION   ##
####################

mkdir -p install
cd install
#curl -o Irrlicht.zip "https://kent.dl.sourceforge.net/project/irrlicht/Irrlicht%20SDK/1.8/1.8.4/irrlicht-1.8.4.zip" 1> /dev/null
cp ../Irrlicht.zip .

export_env
check_dependancies
download_dependancies

# Stop script on error
set -e

build_pkg_config
build_pthreads_stubs
build_glproto
build_pciaccess
build_libdrm
build_dri2proto
build_dri3proto
build_present_proto
build_zlib
build_python
build_xml2
build_xslt
build_xcb_proto
build_dmx_proto
build_xproto
build_xau
build_xcb
build_xshmdence
build_xextproto
build_xtrans
build_kbproto
build_input_proto
build_perl
build_x11
build_xext
build_damage_proto
build_fixes_proto
build_xfixes
build_xdamage
build_expat
build_m4
build_autoconf
build_omxil_bellagio
build_cmake
build_llvm # TODO TEST
build_mesa # TODO TEST
build_irrlicht
build_randr_proto
build_renderproto
build_xrender
build_xrandr
build_sfml

export_env_bash

echo "SUCCESS"
