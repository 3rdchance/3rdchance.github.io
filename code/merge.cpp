#include <iostream>
#include <iostream>
#include <filesystem>

#include <unistd.h>

void Usage(const char* bin) {
	std::cout <<"Usage: " << bin << " [-lfm] src dst" << std::endl;
	std::cout <<"\r -l(default) only list defference of two directory" << std::endl;
	std::cout <<"\r -f force merge the source directory file to dest" << std::endl;
	std::cout <<"\r -m only merge the file that only existed in the source directory to dst" << std::endl;
}

enum OpMode {
	LIST,   // list all different files
	MERGE,  
	FORCE,  // force override dst file
};

static const char* OpModeString[] = {
	"list",
	"merge",
	"force",
};

// linue format
// TODO 1 class name format
// TODO 2 折行缩进 

using Op = std::function<void(const std::filesystem::path& src, const std::filesystem::path& dst)>;



void Compare(const std::filestem::path& src, const std::filesystem::path& dst) {
}

void Dispay() {
  // how out put red in terminal
}


static void ComparePath(std::filesystem::path src, std::filesystem::path dst, Op op)
{
  if (!std::filesystem::exist(src) || !std::filesystem::is_directory(src)) {
  }
  
  if (!std::filesystem::exist(dst) || !std::filesystem::is_directory(dst)) {
  }

  for (const auto& entry : std::filesystem::directory_iterator(src) {
      auto& src_path = entry.path();
      auto dst_path = src_path;
      dst_path += path.file_name();
      
      if (src_path.is_regular_file()) {
	Op(src_path, dst_path);
      }

      
      if (path.is_directory()) {
	ComparePath(src.append(path.filename()), dst.append(path.filename()))
	  }
    }
	 }	

int main(int argc, char* argv[])
{
	enum OpMode op = LIST;
	int optchar;
	
	while((optchar = getopt(argc, argv, "flm")) != -1) {
		switch (optchar) {
			case 'f':
				op = FORCE;
				break;
			case 'l':
				op = LIST;
				break;
			case 'm':
				op = MERGE;
				break;
			default : /* ? */
				Usage(argv[0]);
				exit(EXIT_FAILURE);
		}	
	}
	
	if (argc - optind != 2) {
		std::cout << "ERROR: Need SRC and DST directory\n";
		Usage(argv[0]);
		exit(EXIT_FAILURE);
	}
	std::cout << "opt mode : " << OpModeString[op] << " src: " << argv[optind] <<
	      " dst: " << argv[optind + 1] << std::endl;


	return -1;
}
