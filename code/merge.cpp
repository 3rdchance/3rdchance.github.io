#include <iostream>
#include <iostream>
#include <filesystem>

#include <unistd.h>

// linue format
// TODO 1 class name format
// TODO 2 折行缩进






//// compare
enum CompareResult {
  kSAME      = 0,
  kNotExists,
  kFsDiffer,    // File size differ
  kHashDiffer,
};

// compare the path, check whether it is different
static CompareResult  Compare(const std::filestem::path& src, const std::filesystem::path& dst) {
  if (!std::filesystem::exists(dst)) return kNotExists;
  if (std::filesystem::file_size(src) != std::filesystem::file_size(dst))
    return KFsDiffer;
  if (std::filesystem::hash(src) != std::filesystem::hash(dst))
    return kHashDiffer;
  return kSAME;
}

using Op = std::function<void(const std::filesystem::path& src, const std::filesystem::path& dst)>;
void List(const std::filesystem::path& src, const std::filesystem::path& dst) {
  // how out put red in terminal
}
void Merge(const std::filesystem::path& src, const std::filesystem::path& dst) {
  // how out put red in terminal
}
void Force(const std::filesystem::path& src, const std::filesystem::path& dst) {
  // how out put red in terminal
}


static void ComparePath(std::filesystem::path src, std::filesystem::path dst, Op op)
{
  // src not exist
  if (!std::filesystem::exist(src) || !std::filesystem::is_directory(src)) {
    std::cout << "Input Error: src not exist, or is a file\n";
    return;
  }

  // dst is a file
  if (std::filesystem::exist(dst) && !std::filesystem::is_directory(dst)) {
    op(src, dst);
    return;
  }

  for (const auto& entry : std::filesystem::directory_iterator(src) {
      auto& src_path = entry.path();
      auto dst_path = src_path;
      dst_path += path.file_name();

      if (!src_path.is_directory(src_path)) {
	(Compare(src, dst) != kSAME) {
	op(src_path, dst_path);
	} else {
	  ComparePath(src_path, dst_path);
	}

      }
 }

  // roadmaps:
  // 1. function and command line opt / argument design
  // 2. archtecture design
  // 3. implement it

  // newtodo: write the doc about
  // 1. getopt design
  // 2. how terminal print color

void Usage(const char* bin) {
	std::cout <<"Usage: " << bin << " [-lfm] src dst" << std::endl;
	std::cout <<"\r -l(default) only list defference of two directory" << std::endl;
	std::cout <<"\r -f force merge the source directory file to dest" << std::endl;
	std::cout <<"\r -m only merge the file that only existed in the source directory to dst" << std::endl;
}
  
enum OpMode {
	LIST,   // list all different files
	MERGE,  // only move file does not exit in dst directory
	FORCE,  // force override dst file
};

static const char* OpModeString[] = {
	"list",
	"merge",
	"force",
};

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


	std::filesystem::path src(argv[optind]);
	std::filesystem::path dst(argv[optind + 1]);

	switch (op) {
	case LIST:
	  ComparePath(src, dst, list);
	  break;
	case MERGE:
	  ComparePath(src, dst, merge);
	  break;
	case FORCE:
	  ComparePath(src, dst, merge);
	default:
	  std::cout << "Error: Not Supported Operation mode " << op << std::endl;
	}

	return -1;
}
