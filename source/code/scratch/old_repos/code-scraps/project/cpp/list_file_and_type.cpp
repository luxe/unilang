#include <dirent.h>
#include <string>
#include <iostream>


bool listFileAndType( const std::string &dir )
{
  DIR *dirp = opendir( dir.c_str() );

  if ( dirp )
  {
    struct dirent *dp = 0;

    while ( (dp = readdir( dirp )) != 0 )
    {
      std::string file( dp->d_name );

      if ( file == "." || file == ".." )   // skip these
        continue;

      if ( dp->d_type == DT_DIR )
      {
        std::string dirPath = dir + "/" + file;

        std::cout << file << ": Directory." << std::endl;

        // recurse into directory
        listFileAndType( dirPath );
      }
      else
      {
        std::cout << file << ": ";

        switch( dp->d_type )
        {
          case DT_FIFO:
              std::cout << "FIFO.";
              break;
          case DT_CHR:
              std::cout << "Character Special.";
              break;
          case DT_BLK:
              std::cout << "Block File.";
              break;
          case DT_REG:
              //std::cout << "Regular File.";
              break;
          case DT_LNK:
              std::cout << "Link.";
              break;
          case DT_SOCK:
              std::cout << "Socket.";
              break;
          case DT_WHT:
              std::cout << "WHT.";
              break;
          case DT_UNKNOWN:
          default:
              std::cout << "Unknown Type.";
              break;
        }

        std::cout << std::endl;
      }
    }

    closedir( dirp );

    return true;
  }
  else
  {
    return false;
  }
}


int main( int argc, char **argv )
{
  const std::string dir = (argc > 1 ? argv[1] : "classes");

  if ( listFileAndType( dir ) == false )
  {
    std::cout << "Error:  Cannot open directory '" << dir << "'" << std::endl;
  }

  return 0;
}