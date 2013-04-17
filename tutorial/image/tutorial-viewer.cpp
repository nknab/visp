/*! \example tutorial-viewer.cpp */
#include <visp/vpDisplayGDI.h>
#include <visp/vpDisplayX.h>
#include <visp/vpImageIo.h>

int main(int argc, char** argv )
{
  if(argc != 2) {
    printf( "Usage: viewer <image name.[pgm,ppm,jpeg,png]>\n" );
    return -1;
  }

#if defined(VISP_HAVE_X11) || defined(VISP_HAVE_GDI)
  vpImage<vpRGBa> I;

  try {
    vpImageIo::read(I, argv[1]);

#ifdef UNIX
    vpDisplayX d(I);
#else
    vpDisplayGDI d(I);
#endif
    vpDisplay::setTitle(I, "My image");
    vpDisplay::display(I);
    vpDisplay::flush(I);
    std::cout << "A click to quit..." << std::endl;
    vpDisplay::getClick(I);
  }
  catch(...) {
    std::cout << "Cannot read image \"" << argv[1] << "\"" << std::endl;
  }
#endif
}
