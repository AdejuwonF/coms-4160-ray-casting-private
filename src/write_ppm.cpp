#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  ////////////////////////////////////////////////////////////////////////////
  std::ofstream out_file;
  out_file.open(filename);
  
  
  if (out_file.is_open()){
    if (num_channels == 1){
      out_file << "P2\n";
      out_file << width << " " << height << std::endl;
      out_file << "255\n";
      for (int i = 0; i < width*height; i++) {
        out_file << std::to_string(data.at(i)) << " ";
      }
    } else if (num_channels == 3) {  
      out_file << "P3\n";
      out_file << width << " " << height << std::endl;
      out_file << "255\n";
      for (int i = 0; i < width*height; i++) {
        out_file << std::to_string(data.at(3*i)) << " " << std::to_string(data.at(3*i + 1)) << " " << std::to_string(data.at(3*i+2)) << std::endl;
      }
    }
  }
  out_file.close();
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
